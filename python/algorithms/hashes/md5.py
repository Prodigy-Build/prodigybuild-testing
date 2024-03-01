from collections.abc import Generator
from math import sin
import hashlib

def to_little_endian(string_32: bytes) -> bytes:
    if len(string_32) != 32:
        raise ValueError("Input must be of length 32")

    little_endian = b""
    for i in [3, 2, 1, 0]:
        little_endian += string_32[8 * i : 8 * i + 8]
    return little_endian


def reformat_hex(i: int) -> bytes:
    if i < 0:
        raise ValueError("Input must be non-negative")

    hex_rep = format(i, "08x")[-8:]
    little_endian_hex = b""
    for i in [3, 2, 1, 0]:
        little_endian_hex += hex_rep[2 * i : 2 * i + 2].encode("utf-8")
    return little_endian_hex


def preprocess(message: bytes) -> bytes:
    bit_string = b""
    for char in message:
        bit_string += format(char, "08b").encode("utf-8")
    start_len = format(len(bit_string), "064b").encode("utf-8")

    bit_string += b"1"
    while len(bit_string) % 512 != 448:
        bit_string += b"0"
    bit_string += to_little_endian(start_len[32:]) + to_little_endian(start_len[:32])

    return bit_string


def get_block_words(bit_string: bytes) -> Generator[list[int], None, None]:
    if len(bit_string) % 512 != 0:
        raise ValueError("Input must have length that's a multiple of 512")

    for pos in range(0, len(bit_string), 512):
        block = bit_string[pos : pos + 512]
        block_words = []
        for i in range(0, 512, 32):
            block_words.append(int(to_little_endian(block[i : i + 32]), 2))
        yield block_words


def not_32(i: int) -> int:
    if i < 0:
        raise ValueError("Input must be non-negative")

    i_str = format(i, "032b")
    new_str = ""
    for c in i_str:
        new_str += "1" if c == "0" else "0"
    return int(new_str, 2)


def sum_32(a: int, b: int) -> int:
    return (a + b) % 2**32


def left_rotate_32(i: int, shift: int) -> int:
    if i < 0:
        raise ValueError("Input must be non-negative")
    if shift < 0:
        raise ValueError("Shift must be non-negative")
    return ((i << shift) ^ (i >> (32 - shift))) % 2**32


def md5_me(message: bytes) -> bytes:
    bit_string = preprocess(message)

    added_consts = [int(2**32 * abs(sin(i + 1))) for i in range(64)]

    a0 = 0x67452301
    b0 = 0xEFCDAB89
    c0 = 0x98BADCFE
    d0 = 0x10325476

    shift_amounts = [
        7,
        12,
        17,
        22,
        7,
        12,
        17,
        22,
        7,
        12,
        17,
        22,
        7,
        12,
        17,
        22,
        5,
        9,
        14,
        20,
        5,
        9,
        14,
        20,
        5,
        9,
        14,
        20,
        5,
        9,
        14,
        20,
        4,
        11,
        16,
        23,
        4,
        11,
        16,
        23,
        4,
        11,
        16,
        23,
        4,
        11,
        16,
        23,
        6,
        10,
        15,
        21,
        6,
        10,
        15,
        21,
        6,
        10,
        15,
        21,
        6,
        10,
        15,
        21,
    ]

    for block_words in get_block_words(bit_string):
        a = a0
        b = b0
        c = c0
        d = d0

        for i in range(64):
            if i <= 15:
                f = d ^ (b & (c ^ d))
                g = i
            elif i <= 31:
                f = c ^ (d & (b ^ c))
                g = (5 * i + 1) % 16
            elif i <= 47:
                f = b ^ c ^ d
                g = (3 * i + 5) % 16
            else:
                f = c ^ (b | not_32(d))
                g = (7 * i) % 16
            f = (f + a + added_consts[i] + block_words[g]) % 2**32
            a = d
            d = c
            c = b
            b = sum_32(b, left_rotate_32(f, shift_amounts[i]))

        a0 = sum_32(a0, a)
        b0 = sum_32(b0, b)
        c0 = sum_32(c0, c)
        d0 = sum_32(d0, d)

    digest = reformat_hex(a0) + reformat_hex(b0) + reformat_hex(c0) + reformat_hex(d0)
    return digest


def test_to_little_endian():
    assert to_little_endian(b'1234567890abcdfghijklmnopqrstuvw') == b'pqrstuvwhijklmno90abcdfg12345678'
    assert to_little_endian(b'1234567890') == b'90abcdfg12345678'
    assert to_little_endian(b'') == b''
    assert to_little_endian(b'1234567890abcdfghijklmnopqrstuvwx') == b'wxvutsrqponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmnopqrstuv') == b'vutsrqponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmnopqrstu') == b'utsrqponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmnopqrst') == b'tsrqponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmnopqrs') == b'srqponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmnopqr') == b'rqponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmnopq') == b'qponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmnop') == b'ponmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmno') == b'onmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklmn') == b'nmlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijklm') == b'mlkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijkl') == b'lkjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghijk') == b'kjihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghij') == b'jihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfghi') == b'ihgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfgh') == b'hgfedcba0987654321'
    assert to_little_endian(b'1234567890abcdfg') == b'gfedcba0987654321'
    assert to_little_endian(b'1234567890abcdf') == b'fedcba0987654321'
    assert to_little_endian(b'1234567890abcd') == b'edcba0987654321'
    assert to_little_endian(b'1234567890abc') == b'dcba0987654321'
    assert to_little_endian(b'1234567890ab') == b'cba0987654321'
    assert to_little_endian(b'1234567890a') == b'ba0987654321'
    assert to_little_endian(b'1234567890') == b'a0987654321'
    assert to_little_endian(b'123456789') == b'9876543210'
    assert to_little_endian(b'12345678') == b'876543210'
    assert to_little_endian(b'1234567') == b'76543210'
    assert to_little_endian(b'123456') == b'6543210'
    assert to_little_endian(b'12345') == b'543210'
    assert to_little_endian(b'1234') == b'432100'
    assert to_little_endian(b'123') == b'321000'
    assert to_little_endian(b'12') == b'210000'
    assert to_little_endian(b'1') == b'100000'
    assert to_little_endian(b'') == b''


def test_reformat_hex():
    assert reformat_hex(1234) == b'd2040000'
    assert reformat_hex(666) == b'9a020000'
    assert reformat_hex(0) == b'00000000'
    assert reformat_hex(1234567890) == b'd2029649'
    assert reformat_hex(1234567890987654321) == b'b11c6cb1'
    assert reformat_hex(1) == b'01000000'
    assert reformat_hex(2) == b'02000000'
    assert reformat_hex(3) == b'03000000'
    assert reformat_hex(4) == b'04000000'
    assert reformat_hex(5) == b'05000000'
    assert reformat_hex(6) == b'06000000'
    assert reformat_hex(7) == b'07000000'
    assert reformat_hex(8) == b'08000000'
    assert reformat_hex(9) == b'09000000'
    assert reformat_hex(10) == b'0a000000'
    assert reformat_hex(11) == b'0b000000'
    assert reformat_hex(12) == b'0c000000'
    assert reformat_hex(13) == b'0d000000'
    assert reformat_hex(14) == b'0e000000'
    assert reformat_hex(15) == b'0f000000'
    assert reformat_hex(16) == b'10000000'
    assert reformat_hex(17) == b'11000000'
    assert reformat_hex(18) == b'12000000'
    assert reformat_hex(19) == b'13000000'
    assert reformat_hex(20) == b'14000000'
    assert reformat_hex(21) == b'15000000'
    assert reformat_hex(22) == b'16000000'
    assert reformat_hex(23) == b'17000000'
    assert reformat_hex(24) == b'18000000'
    assert reformat_hex(25) == b'19000000'
    assert reformat_hex(26) == b'1a000000'
    assert reformat_hex(27) == b'1b000000'
    assert reformat_hex(28) == b'1c000000'
    assert reformat_hex(29) == b'1d000000'
    assert reformat_hex(30) == b'1e000000'
    assert reformat_hex(31) == b'1f000000'
    assert reformat_hex(32) == b'20000000'
    assert reformat_hex(33) == b'21000000'
    assert reformat_hex(34) == b'22000000'
    assert reformat_hex(35) == b'23000000'
    assert reformat_hex(36) == b'24000000'
    assert reformat_hex(37) == b'25000000'
    assert reformat_hex(38) == b'26000000'
    assert reformat_hex(39) == b'27000000'
    assert reformat_hex(40) == b'28000000'
    assert reformat_hex(41) == b'29000000'
    assert reformat_hex(42) == b'2a000000'
    assert reformat_hex(43) == b'2b000000'
    assert reformat_hex(44) == b'2c000000'
    assert reformat_hex(45) == b'2d000000'
    assert reformat_hex(46) == b'2e000000'
    assert reformat_hex(47) == b'2f000000'
    assert reformat_hex(48) == b'30000000'
    assert reformat_hex(49) == b'31000000'
    assert reformat_hex(50) == b'32000000'
    assert reformat_hex(51) == b'33000000'
    assert reformat_hex(52) == b'34000000'
    assert reformat_hex(53) == b'35000000'
    assert reformat_hex(54) == b'36000000'
    assert reformat_hex(55) == b'37000000'
    assert reformat_hex(56) == b'38000000'
    assert reformat_hex(57) == b'39000000'
    assert reformat_hex(58) == b'3a000000'
    assert reformat_hex(59) == b'3b000000'
    assert reformat_hex(60) == b'3c000000'
    assert reformat_hex(61) == b'3d000000'
    assert reformat_hex(62) == b'3e000000'
    assert reformat_hex(63) == b'3f000000'
    assert reformat_hex(64) == b'40000000'
    assert reformat_hex(65) == b'41000000'
    assert reformat_hex(66) == b'42000000'
    assert reformat_hex(67) == b'43000000'
    assert reformat_hex(68) == b'44000000'
    assert reformat_hex(69) == b'45000000'
    assert reformat_hex(70) == b'46000000'
    assert reformat_hex(71) == b'47000000'
    assert reformat_hex(72) == b'48000000'
    assert reformat_hex(73) == b'49000000'
    assert reformat_hex(74) == b'4a000000'
    assert reformat_hex(75) == b'4b000000'
    assert reformat_hex(76) == b'4c000000'
    assert reformat_hex(77) == b'4d000000'
    assert reformat_hex(78) == b'4e000000'
    assert reformat_hex(79) == b'4f000000'
    assert reformat_hex(80) == b'50000000'
    assert reformat_hex(81) == b'51000000'
    assert reformat_hex(82) == b'52000000'
    assert reformat_hex(83) == b'53000000'
    assert reformat_hex(84) == b'54000000'
    assert reformat_hex(85) == b'55000000'
    assert reformat_hex(86) == b'56000000'
    assert reformat_hex(87) == b'57000000'
    assert reformat_hex(88) == b'58000000'
    assert reformat_hex(89) == b'59000000'
    assert reformat_hex(90) == b'5a000000'
    assert reformat_hex(91) == b'5b000000'
    assert reformat_hex(92) == b'5c000000'
    assert reformat_hex(93) == b'5d000000'
    assert reformat_hex(94) == b'5e000000'
    assert reformat_hex(95) == b'5f000000'
    assert reformat_hex(96) == b'60000000'
    assert reformat_hex(97) == b'61000000'
    assert reformat_hex(98) == b'62000000'
    assert reformat_hex(99) == b'63000000'
    assert reformat_hex(100) == b'64000000'
    assert reformat_hex(101) == b'65000000'
    assert reformat_hex(102) == b'66000000'
    assert reformat_hex(103) == b'67000000'
    assert reformat_hex(104) == b'68000000'
    assert reformat_hex(105) == b'69000000'
    assert reformat_hex(106) == b'6a000000'
    assert reformat_hex(107) == b'6b000000'
    assert reformat_hex(108) == b'6c000000'
    assert reformat_hex(109) == b'6d000000'
    assert reformat_hex(110) == b'6e000000'
    assert reformat_hex(111) == b'6f000000'
    assert reformat_hex(112) == b'70000000'
    assert reformat_hex(113) == b'71000000'
    assert reformat_hex(114) == b'72000000'
    assert reformat_hex(115) == b'73000000'
    assert reformat_hex(116) == b'74000000'
    assert reformat_hex(117) == b'75000000'
    assert reformat_hex(118) == b'76000000'
    assert reformat_hex(119) == b'77000000'
    assert reformat_hex(120) == b'78000000'
    assert reformat_hex(121) == b'79000000'
    assert reformat_hex(122) == b'7a000000'
    assert reformat_hex(123) == b'7b000000'
    assert reformat_hex(124) == b'7c000000'
    assert reformat_hex(125) == b'7d000000'
    assert reformat_hex(126) == b'7e000000'
    assert reformat_hex(127) == b'7f000000'
    assert reformat_hex(128) == b'80000000'
    assert reformat_hex(129) == b'81000000'
    assert reformat_hex(130) == b'82000000'
    assert reformat_hex(131) == b'83000000'
    assert reformat_hex(132) == b'84000000'
    assert reformat_hex(133) == b'85000000'
    assert reformat_hex(134) == b'86000000'
    assert reformat_hex(135) == b'87000000'
    assert reformat_hex(136) == b'88000000'
    assert reformat_hex(137) == b'89000000'
    assert reformat_hex(138) == b'8a000000'
    assert reformat_hex(139) == b'8b000000'
    assert reformat_hex(140) == b'8c000000'
    assert reformat_hex(141) == b'8d000000'
    assert reformat_hex(142) == b'8e000000'
    assert reformat_hex(143) == b'8f000000'
    assert reformat_hex(144) == b'90000000'
    assert reformat_hex(145) == b'91000000'
    assert reformat_hex(146) == b'92000000'
    assert reformat_hex(147) == b'93000000'
    assert reformat_hex(148) == b'94000000'
    assert reformat_hex(149) == b'95000000'
    assert reformat_hex(150) == b'96000000'
    assert reformat_hex(151) == b'97000000'
    assert reformat_hex(152) == b'98000000'
    assert reformat_hex(153) == b'99000000'
    assert reformat_hex(154) == b'9a000000'
    assert reformat_hex(155) == b'9b000000'
    assert reformat_hex(156) == b'9c000000'
    assert reformat_hex(157) == b'9d000000'
    assert reformat_hex(158) == b'9e000000'
    assert reformat_hex(159) == b'9f000000'
    assert reformat_hex(160) == b'a0000000'
    assert reformat_hex(161) == b'a1000000'
    assert reformat_hex(162) == b'a2000000'
    assert reformat_hex(163) == b'a3000000'
    assert reformat_hex(164) == b'a4000000'
    assert reformat_hex(165) == b'a5000000'
    assert reformat_hex(166) == b'a6000000'
    assert reformat_hex(167) == b'a7000000'
    assert reformat_hex(168) == b'a8000000'
    assert reformat_hex(169) == b'a9000000'
    assert reformat_hex(170) == b'aa000000'
    assert reformat_hex(171) == b'ab000000'
    assert reformat_hex(172) == b'ac000000'
    assert reformat_hex(173) == b'ad000000'
    assert reformat_hex(174) == b'ae000000'
    assert reformat_hex(175) == b'af000000'
    assert reformat_hex(176) == b'b0000000'
    assert reformat_hex(177) == b'b1000000'
    assert reformat_hex(178) == b'b2000000'
    assert reformat_hex(179) == b'b3000000'
    assert reformat_hex(180) == b'b4000000'
    assert reformat_hex(181) == b'b5000000'
    assert reformat_hex(182) == b'b6000000'
    assert reformat_hex(183) == b'b7000000'
    assert reformat_hex(184) == b'b8000000'
    assert reformat_hex(185) == b'b9000000'
    assert reformat_hex(186) == b'ba000000'
    assert reformat_hex(187) == b'bb000000'
    assert reformat_hex(188) == b'bc000000'
    assert reformat_hex(189) == b'bd000000'
    assert reformat_hex(190) == b'be000000'
    assert reformat_hex(191) == b'bf000000'
    assert reformat_hex(192) == b'c0000000'
    assert reformat_hex(193) == b'c1000000'
    assert reformat_hex(194) == b'c2000000'
    assert reformat_hex(195) == b'c3000000'
    assert reformat_hex(196) == b'c4000000'
    assert reformat_hex(197) == b'c5000000'
    assert reformat_hex(198) == b'c6000000'
    assert reformat_hex(199) == b'c7000000'
    assert reformat_hex(200) == b'c8000000'
    assert reformat_hex(201) == b'c9000000'
    assert reformat_hex(202) == b'ca000000'
    assert reformat_hex(203) == b'cb000000'
    assert reformat_hex(204) == b'cc000000'
    assert reformat_hex(205) == b'cd000000'
    assert reformat_hex(206) == b'ce000000'
    assert reformat_hex(207) == b'cf000000'
    assert reformat_hex(208) == b'd0000000'
    assert reformat_hex(209) == b'd1000000'
    assert reformat_hex(210) == b'd2000000'
    assert reformat_hex(211) == b'd3000000'
    assert reformat_hex(212) == b'd4000000'
    assert reformat_hex(213) == b'd5000000'
    assert reformat_hex(214) == b'd6000000'
    assert reformat_hex(215) == b'd7000000'
    assert reformat_hex(216) == b'd8000000'
    assert reformat_hex(217) == b'd9000000'
    assert reformat_hex(218) == b'da000000'
    assert reformat_hex(219) == b'db000000'
    assert reformat_hex(220) == b'dc000000'
    assert reformat_hex(221) == b'dd000000'
    assert reformat_hex(222) == b'de000000'
    assert reformat_hex(223) == b'df000000'
    assert reformat_hex(224) == b'e0000000'
    assert reformat_hex(225) == b'e1000000'
    assert reformat_hex(226) == b'e2000000'
    assert reformat_hex(227) == b'e3000000'
    assert reformat_hex(228) == b'e4000000'
    assert reformat_hex(229) == b'e5000000'
    assert reformat_hex(230) == b'e6000000'
    assert reformat_hex(231) == b'e7000000'
    assert reformat_hex(232) == b'e8000000'
    assert reformat_hex(233) == b'e9000000'
    assert reformat_hex(234) == b'ea000000'
    assert reformat_hex(235) == b'eb000000'
    assert reformat_hex(236) == b'ec000000'
    assert reformat_hex(237) == b'ed000000'
    assert reformat_hex(238) == b'ee000000'
    assert reformat_hex(239) == b'ef000000'
    assert reformat_hex(240) == b'f0000000'
    assert reformat_hex(241) == b'f1000000'
    assert reformat_hex(242) == b'f2000000'
    assert reformat_hex(243) == b'f3000000'
    assert reformat_hex(244) == b'f4000000'
    assert reformat_hex(245) == b'f5000000'
    assert reformat_hex(246) == b'f6000000'
    assert reformat_hex(247) == b'f7000000'
    assert reformat_hex(248) == b'f8000000'
    assert reformat_hex(249) == b'f9000000'
    assert reformat_hex(250) == b'fa000000'
    assert reformat_hex(251) == b'fb000000
def test_calculate_prob():
    text = ("Behind Winston’s back the voice "
            "from the telescreen was still "
            "babbling and the overfulfilment")
    calculate_prob(text)
    # Expected output:
    # 4.0
    # 6.0
    # 2.0

    text = ("The Ministry of Truth—Minitrue, in Newspeak [Newspeak was the official"
            "face in elegant lettering, the three")
    calculate_prob(text)
    # Expected output:
    # 4.0
    # 5.0
    # 1.0

    text = ("Had repulsive dashwoods suspicion sincerity but advantage now him. "
            "Remark easily garret nor nay.  Civil those mrs enjoy shy fat merry. "
            "You greatest jointure saw horrible. He private he on be imagine "
            "suppose. Fertile beloved evident through no service elderly is. Blind "
            "there if every no so at. Own neglected you preferred way sincerity "
            "delivered his attempted. To of message cottage windows do besides "
            "against uncivil.  Delightful unreserved impossible few estimating "
            "men favourable see entreaties. She propriety immediate was improving. "
            "He or entrance humoured likewise moderate. Much nor game son say "
            "feel. Fat make met can must form into gate. Me we offending prevailed "
            "discovery.")
    calculate_prob(text)
    # Expected output:
    # 4.0
    # 7.0
    # 3.0
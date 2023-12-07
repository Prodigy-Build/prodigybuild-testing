@Test
public void testSetObjHashes() {
    CounterAvgRequestByObjHashes request = new CounterAvgRequestByObjHashes();

    // Test case 1: valid objHashes parameter
    String validObjHashes = "1,2,3";
    request.setObjHashes(validObjHashes);
    Set<Integer> expectedObjHashes = new HashSet<>(Arrays.asList(1, 2, 3));
    assertEquals(expectedObjHashes, request.getObjHashes());

    // Test case 2: empty objHashes parameter
    String emptyObjHashes = "";
    request.setObjHashes(emptyObjHashes);
    Set<Integer> expectedEmptyObjHashes = new HashSet<>();
    assertEquals(expectedEmptyObjHashes, request.getObjHashes());
}
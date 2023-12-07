@Test
public void testPageableXLogView() {
    long lastXLogTime = 12345L;
    long lastTxid = 67890L;
    boolean hasMore = true;
    List<SXLog> xLogs = new ArrayList<>();
    
    PageableXLogView pageableXLogView = new PageableXLogView();
    pageableXLogView.setLastXLogTime(lastXLogTime);
    pageableXLogView.setLastTxid(lastTxid);
    pageableXLogView.setHasMore(hasMore);
    pageableXLogView.setXLogs(xLogs);
    
    assertEquals(lastXLogTime, pageableXLogView.getLastXLogTime());
    assertEquals(lastTxid, pageableXLogView.getLastTxid());
    assertEquals(hasMore, pageableXLogView.isHasMore());
    assertEquals(xLogs, pageableXLogView.getXLogs());
}
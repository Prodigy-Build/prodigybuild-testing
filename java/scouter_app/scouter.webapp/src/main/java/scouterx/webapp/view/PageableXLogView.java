@RunWith(MockitoJUnitRunner.class)
public class PageableXLogViewTest {

    @Test
    public void testGetLastXLogTime() {
        // given
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setLastXLogTime(1234567890L);

        // when
        long lastXLogTime = pageableXLogView.getLastXLogTime();

        // then
        assertEquals(1234567890L, lastXLogTime);
    }

    @Test
    public void testGetLastTxid() {
        // given
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setLastTxid(987654321L);

        // when
        long lastTxid = pageableXLogView.getLastTxid();

        // then
        assertEquals(987654321L, lastTxid);
    }

    @Test
    public void testHasMore() {
        // given
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setHasMore(true);

        // when
        boolean hasMore = pageableXLogView.isHasMore();

        // then
        assertTrue(hasMore);
    }

    @Test
    public void testGetXLogs() {
        // given
        SXLog sxLog1 = new SXLog();
        SXLog sxLog2 = new SXLog();
        List<SXLog> xLogs = Arrays.asList(sxLog1, sxLog2);

        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setXLogs(xLogs);

        // when
        List<SXLog> retrievedXLogs = pageableXLogView.getXLogs();

        // then
        assertEquals(xLogs, retrievedXLogs);
    }
}
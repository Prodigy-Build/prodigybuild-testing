@RunWith(MockitoJUnitRunner.class)
public class PageableXLogViewTest {

    @Test
    public void testGetLastXLogTime() {
        // given
        long expected = 123456789;
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setLastXLogTime(expected);

        // when
        long actual = pageableXLogView.getLastXLogTime();

        // then
        assertEquals(expected, actual);
    }

    @Test
    public void testSetLastXLogTime() {
        // given
        long expected = 987654321;
        PageableXLogView pageableXLogView = new PageableXLogView();

        // when
        pageableXLogView.setLastXLogTime(expected);

        // then
        assertEquals(expected, pageableXLogView.getLastXLogTime());
    }

    @Test
    public void testGetLastTxid() {
        // given
        long expected = 123456789;
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setLastTxid(expected);

        // when
        long actual = pageableXLogView.getLastTxid();

        // then
        assertEquals(expected, actual);
    }

    @Test
    public void testSetLastTxid() {
        // given
        long expected = 987654321;
        PageableXLogView pageableXLogView = new PageableXLogView();

        // when
        pageableXLogView.setLastTxid(expected);

        // then
        assertEquals(expected, pageableXLogView.getLastTxid());
    }

    @Test
    public void testHasMore() {
        // given
        boolean expected = true;
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setHasMore(expected);

        // when
        boolean actual = pageableXLogView.isHasMore();

        // then
        assertEquals(expected, actual);
    }

    @Test
    public void testSetHasMore() {
        // given
        boolean expected = true;
        PageableXLogView pageableXLogView = new PageableXLogView();

        // when
        pageableXLogView.setHasMore(expected);

        // then
        assertEquals(expected, pageableXLogView.isHasMore());
    }

    @Test
    public void testGetXLogs() {
        // given
        List<SXLog> expected = new ArrayList<>();
        expected.add(new SXLog("log1"));
        expected.add(new SXLog("log2"));
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setXLogs(expected);

        // when
        List<SXLog> actual = pageableXLogView.getXLogs();

        // then
        assertEquals(expected, actual);
    }

    @Test
    public void testSetXLogs() {
        // given
        List<SXLog> expected = new ArrayList<>();
        expected.add(new SXLog("log1"));
        expected.add(new SXLog("log2"));
        PageableXLogView pageableXLogView = new PageableXLogView();

        // when
        pageableXLogView.setXLogs(expected);

        // then
        assertEquals(expected, pageableXLogView.getXLogs());
    }
}

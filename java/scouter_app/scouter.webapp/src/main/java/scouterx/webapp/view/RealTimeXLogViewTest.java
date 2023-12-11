@RunWith(MockitoJUnitRunner.class)
public class RealTimeXLogViewTest {

    @Mock
    private SXLog xLog;

    @Test
    public void testGetXLogIndex() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogIndex(10);
        assertEquals(10, view.getXLogIndex());
    }

    @Test
    public void testSetXLogIndex() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogIndex(20);
        assertEquals(20, view.getXLogIndex());
    }

    @Test
    public void testGetXLogLoop() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogLoop(100);
        assertEquals(100, view.getXLogLoop());
    }

    @Test
    public void testSetXLogLoop() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogLoop(200);
        assertEquals(200, view.getXLogLoop());
    }

    @Test
    public void testGetXLogs() {
        RealTimeXLogView view = new RealTimeXLogView();
        List<SXLog> xLogs = new ArrayList<>();
        xLogs.add(xLog);
        view.setXLogs(xLogs);
        
        assertEquals(xLogs, view.getXLogs());
    }

    @Test
    public void testSetXLogs() {
        RealTimeXLogView view = new RealTimeXLogView();
        List<SXLog> xLogs = new ArrayList<>();
        xLogs.add(xLog);
        view.setXLogs(xLogs);

        assertEquals(xLogs, view.getXLogs());
    }
}
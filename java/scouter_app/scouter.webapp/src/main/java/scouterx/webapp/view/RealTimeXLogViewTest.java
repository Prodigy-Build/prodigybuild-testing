package scouterx.webapp.view;

import org.junit.Test;
import scouterx.webapp.model.scouter.SXLog;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class RealTimeXLogViewTest {

    @Test
    public void testGetXLogIndex() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogIndex(10);

        int result = view.getXLogIndex();

        assertEquals(10, result);
    }

    @Test
    public void testSetXLogIndex() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogIndex(10);

        int result = view.getXLogIndex();

        assertEquals(10, result);
    }

    @Test
    public void testGetXLogLoop() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogLoop(100L);

        long result = view.getXLogLoop();

        assertEquals(100L, result);
    }

    @Test
    public void testSetXLogLoop() {
        RealTimeXLogView view = new RealTimeXLogView();
        view.setXLogLoop(100L);

        long result = view.getXLogLoop();

        assertEquals(100L, result);
    }

    @Test
    public void testGetXLogs() {
        RealTimeXLogView view = new RealTimeXLogView();
        List<SXLog> xLogs = new ArrayList<>();
        xLogs.add(new SXLog());
        view.setXLogs(xLogs);

        List<SXLog> result = view.getXLogs();

        assertNotNull(result);
        assertEquals(1, result.size());
    }

    @Test
    public void testSetXLogs() {
        RealTimeXLogView view = new RealTimeXLogView();
        List<SXLog> xLogs = new ArrayList<>();
        xLogs.add(new SXLog());
        view.setXLogs(xLogs);

        List<SXLog> result = view.getXLogs();

        assertNotNull(result);
        assertEquals(1, result.size());
    }
}
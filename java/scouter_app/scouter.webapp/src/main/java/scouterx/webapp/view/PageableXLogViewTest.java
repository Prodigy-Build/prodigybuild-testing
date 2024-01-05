package scouterx.webapp.view;

import org.junit.Assert;
import org.junit.Test;
import scouterx.webapp.model.scouter.SXLog;

import java.util.ArrayList;
import java.util.List;

public class PageableXLogViewTest {

    @Test
    public void testGetLastXLogTime() {
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setLastXLogTime(123456789L);

        Assert.assertEquals(123456789L, pageableXLogView.getLastXLogTime());
    }

    @Test
    public void testGetLastTxid() {
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setLastTxid(987654321L);

        Assert.assertEquals(987654321L, pageableXLogView.getLastTxid());
    }

    @Test
    public void testIsHasMore() {
        PageableXLogView pageableXLogView = new PageableXLogView();
        pageableXLogView.setHasMore(true);

        Assert.assertTrue(pageableXLogView.isHasMore());
    }

    @Test
    public void testGetXLogs() {
        PageableXLogView pageableXLogView = new PageableXLogView();
        List<SXLog> xLogs = new ArrayList<>();
        xLogs.add(new SXLog());
        xLogs.add(new SXLog());
        pageableXLogView.setXLogs(xLogs);

        Assert.assertEquals(xLogs, pageableXLogView.getXLogs());
    }
}
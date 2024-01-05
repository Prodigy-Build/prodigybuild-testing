package scouterx.webapp.view;

import org.junit.Test;
import scouterx.webapp.model.scouter.SAlert;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class RealTimeAlertViewTest {

    @Test
    public void testGetOffset1() {
        RealTimeAlertView view = new RealTimeAlertView();
        view.setOffset1(100L);

        assertEquals(100L, view.getOffset1());
    }

    @Test
    public void testGetOffset2() {
        RealTimeAlertView view = new RealTimeAlertView();
        view.setOffset2(200);

        assertEquals(200, view.getOffset2());
    }

    @Test
    public void testGetAlerts() {
        RealTimeAlertView view = new RealTimeAlertView();
        List<SAlert> alerts = new ArrayList<>();
        alerts.add(new SAlert());
        alerts.add(new SAlert());
        view.setAlerts(alerts);

        assertNotNull(view.getAlerts());
        assertEquals(2, view.getAlerts().size());
    }
}
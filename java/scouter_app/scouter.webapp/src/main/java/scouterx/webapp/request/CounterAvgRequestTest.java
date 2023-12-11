package scouterx.webapp.request;

import org.junit.Test;
import scouterx.webapp.framework.client.server.ServerManager;
import javax.validation.constraints.AssertTrue;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class CounterAvgRequestTest {

    @Test
    public void testServerId() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setServerId(1);
        assertTrue(request.getServerId() == ServerManager.getInstance().getServerIfNullDefault(1).getId());
        assertFalse(request.getServerId() == ServerManager.getInstance().getServerIfNullDefault(2).getId());
    }

    @Test
    public void testCounter() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setCounter("counter1");
        assertTrue(request.getCounter().equals("counter1"));
        assertFalse(request.getCounter().equals("counter2"));
    }

    @Test
    public void testStartYmd() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setStartYmd("2020-01-01");
        assertTrue(request.getStartYmd().equals("2020-01-01"));
        assertFalse(request.getStartYmd().equals("2019-12-31"));
    }

    @Test
    public void testEndYmd() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setEndYmd("2020-12-31");
        assertTrue(request.getEndYmd().equals("2020-12-31"));
        assertFalse(request.getEndYmd().equals("2021-01-01"));
    }
}
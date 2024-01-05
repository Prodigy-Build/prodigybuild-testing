package scouterx.webapp.request;

import org.junit.Assert;
import org.junit.Test;

public class CounterAvgRequestTest {

    @Test
    public void testSetServerId() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setServerId(1);
        Assert.assertEquals(1, request.getServerId());
    }

    @Test
    public void testSetCounter() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setCounter("counter");
        Assert.assertEquals("counter", request.getCounter());
    }

    @Test
    public void testSetStartYmd() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setStartYmd("2020-01-01");
        Assert.assertEquals("2020-01-01", request.getStartYmd());
    }

    @Test
    public void testSetEndYmd() {
        CounterAvgRequest request = new CounterAvgRequest();
        request.setEndYmd("2020-01-31");
        Assert.assertEquals("2020-01-31", request.getEndYmd());
    }
}
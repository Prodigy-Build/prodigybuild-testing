package scouterx.webapp.view;

import org.junit.Test;
import scouterx.webapp.model.scouter.SCounter;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class RealTimeCounterViewTest {

    @Test
    public void testGetObjHash() {
        RealTimeCounterView view = new RealTimeCounterView();
        view.setObjHash(12345);

        int objHash = view.getObjHash();

        assertEquals(12345, objHash);
    }

    @Test
    public void testGetCounter() {
        RealTimeCounterView view = new RealTimeCounterView();
        List<SCounter> counters = new ArrayList<>();
        counters.add(new SCounter("counter1", 10));
        counters.add(new SCounter("counter2", 20));
        view.setCounter(counters);

        List<SCounter> result = view.getCounter();

        assertNotNull(result);
        assertEquals(2, result.size());
        assertEquals("counter1", result.get(0).getName());
        assertEquals(10, result.get(0).getValue());
        assertEquals("counter2", result.get(1).getName());
        assertEquals(20, result.get(1).getValue());
    }
}
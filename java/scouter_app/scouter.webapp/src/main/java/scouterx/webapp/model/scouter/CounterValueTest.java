package scouterx.webapp.model.scouter;

import org.junit.Test;
import static org.junit.Assert.*;

public class CounterValueTest {

    @Test
    public void testGetName() {
        CounterValue counterValue = new CounterValue("counter1", 10);
        assertEquals("counter1", counterValue.getName());
    }

    @Test
    public void testGetValue() {
        CounterValue counterValue = new CounterValue("counter1", 10);
        assertEquals(10, counterValue.getValue());
    }

    @Test
    public void testOf() {
        SCounter counter = new SCounter("counter1", 10);
        CounterValue counterValue = CounterValue.of(counter);
        assertEquals("counter1", counterValue.getName());
        assertEquals(10, counterValue.getValue());
    }
}
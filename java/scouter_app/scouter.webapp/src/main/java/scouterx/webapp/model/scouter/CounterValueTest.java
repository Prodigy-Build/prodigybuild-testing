///////TEST CODE////////

import org.junit.Test;
import static org.junit.Assert.*;

public class CounterValueTest {

    @Test
    public void testCounterValueOf() {
        SCounter counter = new SCounter("Test Counter", 100);

        CounterValue counterValue = CounterValue.of(counter);

        assertEquals("Test Counter", counterValue.getName());
        assertEquals(100, counterValue.getValue());
    }
}
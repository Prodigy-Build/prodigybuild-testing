// Test code for CounterValue

import org.junit.Test;
import static org.junit.Assert.*;

public class CounterValueTest {

    @Test
    public void testOf() {
        // Create a mock SCounter object
        SCounter counter = new SCounter("testCounter", 100);

        // Create a CounterValue object using the static method 'of'
        CounterValue counterValue = CounterValue.of(counter);

        // Assert that the name and value of the CounterValue object match the mock SCounter object
        assertEquals("testCounter", counterValue.getName());
        assertEquals(100, counterValue.getValue());
    }
}
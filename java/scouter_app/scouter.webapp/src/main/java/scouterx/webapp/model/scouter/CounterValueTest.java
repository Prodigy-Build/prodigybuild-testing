package scouterx.webapp.model.scouter;

import org.junit.Assert;
import org.junit.Test;
import scouterx.webapp.model.scouter.SCounter;

public class CounterValueTest {

    @Test
    public void testOf() {
        // Create a mock SCounter object
        SCounter mockCounter = new SCounter();
        mockCounter.setName("Test Counter");
        mockCounter.setValue(100);

        // Call the of() method to create a CounterValue object
        CounterValue counterValue = CounterValue.of(mockCounter);

        // Verify that the CounterValue object has the correct name and value
        Assert.assertEquals("Test Counter", counterValue.getName());
        Assert.assertEquals(100, counterValue.getValue());
    }
}
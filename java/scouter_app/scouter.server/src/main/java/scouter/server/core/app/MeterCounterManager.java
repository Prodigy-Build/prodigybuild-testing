/* 
* Let's add some unit tests for the MeterCounterManager class 
*/

import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

public class MeterCounterManagerTest {

    private MeterCounterManager meterCounterManager;

    @Before
    public void setUp() {
        meterCounterManager = MeterCounterManager.getInstance();
    }

    @Test
    public void testGetMeterCounter() {
        MeterCounter meterCounter = meterCounterManager.getMeterCounter(12345, "counter1");
        assertNotNull(meterCounter);
    }

    @Test
    public void testGetMeterCounter_multipleTimes_sameKey() {
        MeterCounter meterCounter1 = meterCounterManager.getMeterCounter(12345, "counter1");
        assertNotNull(meterCounter1);

        MeterCounter meterCounter2 = meterCounterManager.getMeterCounter(12345, "counter1");
        assertNotNull(meterCounter2);

        assertSame(meterCounter1, meterCounter2);
    }

    @Test
    public void testGetMeterCounter_multipleTimes_differentKey() {
        MeterCounter meterCounter1 = meterCounterManager.getMeterCounter(12345, "counter1");
        assertNotNull(meterCounter1);

        MeterCounter meterCounter2 = meterCounterManager.getMeterCounter(54321, "counter1");
        assertNotNull(meterCounter2);

        assertNotSame(meterCounter1, meterCounter2);
    }
}
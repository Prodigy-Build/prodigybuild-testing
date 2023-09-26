package scouter.server.core.app;

import org.junit.Test;

import static org.junit.Assert.*;

public class MeterCounterManagerTest {

    @Test
    public void testGetMeterCounter() {
        MeterCounterManager meterCounterManager = MeterCounterManager.getInstance();
        MeterCounter meterCounter = meterCounterManager.getMeterCounter(1, "counter1");

        assertNotNull(meterCounter);
        assertEquals(0, meterCounter.getValue());

        meterCounter.increment();
        assertEquals(1, meterCounter.getValue());
    }
}
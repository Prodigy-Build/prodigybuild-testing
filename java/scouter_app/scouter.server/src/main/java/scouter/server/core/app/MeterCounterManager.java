package scouter.server.core.app;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import scouter.util.LinkedMap;

public class MeterCounterManagerTest {

    private MeterCounterManager meterCounterManager;

    @Before
    public void setUp() {
        meterCounterManager = MeterCounterManager.getInstance();
    }

    @Test
    public void testGetMeterCounter() {
        MeterCounter meterCounter = meterCounterManager.getMeterCounter(1, "counter1");

        Assert.assertNotNull(meterCounter);
    }
}
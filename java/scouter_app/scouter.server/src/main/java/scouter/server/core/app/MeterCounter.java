package scouter.server.core.app;

import org.junit.Test;
import scouter.lang.ref.DOUBLE;
import scouter.lang.ref.INT;
import scouter.util.MeteringUtil;
import scouter.util.MeteringUtil.Handler;

import static org.junit.Assert.assertEquals;

public class MeterCounterTest {

    @Test
    public void testAdd() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(1.0);
        meterCounter.add(2.0);
        meterCounter.add(3.0);
        double expectedValue = 6.0;
        double actualValue = meterCounter.getSum(2000);
        assertEquals(expectedValue, actualValue, 0);
    }

    @Test
    public void testGetAvg() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(1.0);
        meterCounter.add(2.0);
        meterCounter.add(3.0);
        double expectedValue = 2.0;
        double actualValue = meterCounter.getAvg(2000);
        assertEquals(expectedValue, actualValue, 0);
    }

    @Test
    public void testGetSum() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(1.0);
        meterCounter.add(2.0);
        meterCounter.add(3.0);
        double expectedValue = 6.0;
        double actualValue = meterCounter.getSum(2000);
        assertEquals(expectedValue, actualValue, 0);
    }
}
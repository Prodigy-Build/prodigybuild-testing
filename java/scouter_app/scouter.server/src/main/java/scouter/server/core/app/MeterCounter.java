package scouter.server.core.app;

import org.junit.Test;
import scouter.lang.ref.DOUBLE;

import static org.junit.Assert.assertEquals;

public class MeterCounterTest {

    @Test
    public void testAddAndGetAvg() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(10.0);
        meterCounter.add(20.0);
        meterCounter.add(30.0);

        double avg = meterCounter.getAvg(3);
        assertEquals(20.0, avg, 0.0);
    }

    @Test
    public void testAddAndGetSum() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(10.0);
        meterCounter.add(20.0);
        meterCounter.add(30.0);

        double sum = meterCounter.getSum(3);
        assertEquals(60.0, sum, 0.0);
    }
}
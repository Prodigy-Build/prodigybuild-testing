package scouter.server.core.app;

import org.junit.Test;
import static org.junit.Assert.*;

public class MeterCounterTest {

    @Test
    public void testAdd() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(10.0);
        meterCounter.add(20.0);
    }

    @Test
    public void testGetAvg() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(10.0);
        meterCounter.add(20.0);
        double avg = meterCounter.getAvg(2000);
        assertEquals(15.0, avg, 0.01);
    }

    @Test
    public void testGetSum() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(10.0);
        meterCounter.add(20.0);
        double sum = meterCounter.getSum(2000);
        assertEquals(30.0, sum, 0.01);
    }
}
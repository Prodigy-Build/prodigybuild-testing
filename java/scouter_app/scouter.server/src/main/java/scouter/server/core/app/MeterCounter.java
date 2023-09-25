package scouter.server.core.app;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

public class MeterCounterTest {

    private MeterCounter meterCounter;

    @Before
    public void setUp() {
        meterCounter = new MeterCounter();
    }

    @Test
    public void testAdd() {
        meterCounter.add(10.0);
        meterCounter.add(20.0);

        double avg = meterCounter.getAvg(2000);
        double sum = meterCounter.getSum(2000);

        assertEquals(15.0, avg, 0);
        assertEquals(30.0, sum, 0);
    }

    @Test
    public void testAdd_withNegativeValues() {
        meterCounter.add(-10.0);
        meterCounter.add(-20.0);

        double avg = meterCounter.getAvg(2000);
        double sum = meterCounter.getSum(2000);

        assertEquals(-15.0, avg, 0);
        assertEquals(-30.0, sum, 0);
    }

    @Test
    public void testAdd_withZeroValue() {
        meterCounter.add(0.0);

        double avg = meterCounter.getAvg(2000);
        double sum = meterCounter.getSum(2000);

        assertEquals(0.0, avg, 0);
        assertEquals(0.0, sum, 0);
    }

    @Test
    public void testGetAvg_withNoData() {
        double avg = meterCounter.getAvg(2000);

        assertEquals(0.0, avg, 0);
    }

    @Test
    public void testGetSum_withNoData() {
        double sum = meterCounter.getSum(2000);

        assertEquals(0.0, sum, 0);
    }

    @Test
    public void testGetAvg_withMultiplePeriods() {
        meterCounter.add(10.0);
        meterCounter.add(20.0);
        meterCounter.add(30.0);

        double avg = meterCounter.getAvg(1000);
        double sum = meterCounter.getSum(1000);

        assertEquals(20.0, avg, 0);
        assertEquals(60.0, sum, 0);
    }

    @Test
    public void testGetSum_withMultiplePeriods() {
        meterCounter.add(10.0);
        meterCounter.add(20.0);
        meterCounter.add(30.0);

        double avg = meterCounter.getAvg(1500);
        double sum = meterCounter.getSum(1500);

        assertEquals(20.0, avg, 0);
        assertEquals(60.0, sum, 0);
    }
}
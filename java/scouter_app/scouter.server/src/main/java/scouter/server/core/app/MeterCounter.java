package scouter.server.core.app;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class MeterCounterTest {

    @Test
    public void testAdd() {
        MeterCounter counter = new MeterCounter();
        counter.add(10.5);
        assertEquals(1, counter.meter.getBucketList().size());
        assertEquals(10.5, counter.meter.getBucketList().get(0).value);
        assertEquals(1, counter.meter.getBucketList().get(0).count);
    }

    @Test
    public void testGetAvg() {
        MeterCounter counter = new MeterCounter();
        counter.add(5.0);
        counter.add(15.0);
        double avg = counter.getAvg(1);
        assertEquals(10.0, avg);
    }

    @Test
    public void testGetAvgWithNoData() {
        MeterCounter counter = new MeterCounter();
        double avg = counter.getAvg(1);
        assertEquals(0.0, avg);
    }
    
    @Test
    public void testGetSum() {
        MeterCounter counter = new MeterCounter();
        counter.add(5.0);
        counter.add(15.0);
        double sum = counter.getSum(1);
        assertEquals(20.0, sum);
    }

    @Test
    public void testGetSumWithNoData() {
        MeterCounter counter = new MeterCounter();
        double sum = counter.getSum(1);
        assertEquals(0.0, sum);
    }
}
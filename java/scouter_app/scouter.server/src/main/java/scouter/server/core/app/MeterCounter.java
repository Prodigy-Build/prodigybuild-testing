package scouter.server.core.app;

import org.junit.Test;
import scouter.lang.ref.DOUBLE;
import scouter.lang.ref.INT;
import scouter.util.MeteringUtil;
import scouter.util.MeteringUtil.Handler;

import static org.junit.Assert.assertEquals;

public class MeterCounter {

    static class Bucket {
        double value;
        int count;
    }

    private MeteringUtil<Bucket> meter = new MeteringUtil<Bucket>(2000, 31) {
        protected Bucket create() {
            return new Bucket();
        };

        protected void clear(Bucket o) {
            o.value=0;
            o.count = 0;
        }
    };

    public synchronized void add(double value) {
        Bucket b = meter.getCurrentBucket();
        b.value += value;
        b.count++;
    }

    public double getAvg(int period) {
        final INT count = new INT();
        final DOUBLE sum = new DOUBLE();
        meter.search(period, new Handler<Bucket>() {
            public void process(Bucket u) {
                sum.value += u.value;
                count.value += u.count;
            }
        });
        return count.value == 0 ? 0 : sum.value / count.value;
    }

    public double getSum(int period) {
        final DOUBLE sum = new DOUBLE();
        meter.search(period, new Handler<Bucket>() {
            public void process(Bucket u) {
                sum.value += u.value;
            }
        });
        return sum.value;
    }

    @Test
    public void testAddMethod() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(10);
        meterCounter.add(20);
        double expected = 30;
        double actual = meterCounter.getSum(2000);
        assertEquals(expected, actual, 0.01);
    }

    @Test
    public void testGetAvgMethod() {
        MeterCounter meterCounter = new MeterCounter();
        meterCounter.add(10);
        meterCounter.add(20);
        double expected = 15;
        double actual = meterCounter.getAvg(2000);
        assertEquals(expected, actual, 0.01);
    }

}
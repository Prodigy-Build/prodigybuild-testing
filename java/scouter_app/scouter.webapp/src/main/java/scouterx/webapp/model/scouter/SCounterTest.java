package scouterx.webapp.model.scouter;

import org.junit.Assert;
import org.junit.Test;

public class SCounterTest {

    @Test
    public void testSCounterConstructor() {
        int objHash = 123;
        String name = "counterName";
        Object value = 456;

        SCounter sCounter = new SCounter(objHash, name, value);

        Assert.assertEquals(objHash, sCounter.getObjHash());
        Assert.assertEquals(name, sCounter.getName());
        Assert.assertEquals(value, sCounter.getValue());
    }
}
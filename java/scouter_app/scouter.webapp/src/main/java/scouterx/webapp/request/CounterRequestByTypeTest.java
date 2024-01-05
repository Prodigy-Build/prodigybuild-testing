package scouterx.webapp.request;

import org.junit.Assert;
import org.junit.Test;

public class CounterRequestByTypeTest {

    @Test
    public void testGetObjType() {
        CounterRequestByType request = new CounterRequestByType();
        request.setObjType("testObjType");
        Assert.assertEquals("testObjType", request.getObjType());
    }
}
package scouterx.webapp.request;

import org.junit.Test;
import static org.junit.Assert.*;

public class CounterAvgRequestByTypeTest {

    @Test
    public void testGetObjType() {
        CounterAvgRequestByType request = new CounterAvgRequestByType();
        request.setObjType("testObjType");
        assertEquals("testObjType", request.getObjType());
    }

    @Test
    public void testToString() {
        CounterAvgRequestByType request = new CounterAvgRequestByType();
        request.setObjType("testObjType");
        assertEquals("CounterAvgRequestByType(objType=testObjType)", request.toString());
    }
}
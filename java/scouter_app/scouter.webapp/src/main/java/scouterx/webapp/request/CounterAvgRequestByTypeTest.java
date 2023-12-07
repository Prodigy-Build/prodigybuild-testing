import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

public class CounterAvgRequestByTypeTest {

    @Test
    public void testObjType() {
        CounterAvgRequestByType request = new CounterAvgRequestByType();
        request.setObjType("objType");

        assertEquals("objType", request.getObjType());
    }

    @Test
    public void testNullObjType() {
        CounterAvgRequestByType request = new CounterAvgRequestByType();
        request.setObjType(null);

        assertNull(request.getObjType());
    }

    @Test
    public void testToString() {
        CounterAvgRequestByType request = new CounterAvgRequestByType();
        request.setObjType("objType");

        String expected = "CounterAvgRequestByType(objType=objType)";
        assertEquals(expected, request.toString());
    }
}
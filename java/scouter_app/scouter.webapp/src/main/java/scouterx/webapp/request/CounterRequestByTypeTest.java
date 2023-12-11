package scouterx.webapp.request;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class CounterRequestByTypeTest {

    @Test
    public void testGetterAndSetter() {
        CounterRequestByType request = new CounterRequestByType();
        request.setObjType("object_type");

        assertEquals("object_type", request.getObjType());
    }

    @Test
    public void testToString() {
        CounterRequestByType request = new CounterRequestByType();
        request.setObjType("object_type");

        String expected = "CounterRequestByType(objType=object_type)";
        assertEquals(expected, request.toString());
    }
}
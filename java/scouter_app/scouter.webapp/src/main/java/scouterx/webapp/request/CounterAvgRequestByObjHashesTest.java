package scouterx.webapp.request;

import org.junit.Test;
import static org.junit.Assert.*;

public class CounterAvgRequestByObjHashesTest {

    @Test
    public void testSetObjHashes() {
        CounterAvgRequestByObjHashes request = new CounterAvgRequestByObjHashes();
        request.setObjHashes("1,2,3,4,5");
        assertEquals(5, request.getObjHashes().size());
        assertTrue(request.getObjHashes().contains(1));
        assertTrue(request.getObjHashes().contains(2));
        assertTrue(request.getObjHashes().contains(3));
        assertTrue(request.getObjHashes().contains(4));
        assertTrue(request.getObjHashes().contains(5));
    }
}
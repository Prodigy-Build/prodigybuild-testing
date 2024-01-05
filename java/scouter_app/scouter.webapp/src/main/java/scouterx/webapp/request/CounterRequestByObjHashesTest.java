package scouterx.webapp.request;

import org.junit.Test;

import java.util.HashSet;
import java.util.Set;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class CounterRequestByObjHashesTest {

    @Test
    public void testSetObjHashes() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        Set<Integer> objHashes = new HashSet<>();
        objHashes.add(1);
        objHashes.add(2);
        objHashes.add(3);

        request.setObjHashes(objHashes);

        assertNotNull(request.getObjHashes());
        assertEquals(objHashes, request.getObjHashes());
    }
}
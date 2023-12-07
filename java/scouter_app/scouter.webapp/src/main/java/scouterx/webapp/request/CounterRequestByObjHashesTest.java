package scouterx.webapp.request;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class CounterRequestByObjHashesTest {

    @Test
    public void testSetObjHashes_String() {
        String objHashes = "1,2,3,4,5";
        CounterRequestByObjHashes counterRequest = new CounterRequestByObjHashes();
        counterRequest.setObjHashes(objHashes);
        assertEquals("1,2,3,4,5", counterRequest.getObjHashes());
    }

    @Test
    public void testSetObjHashes_Set() {
        Set<Integer> objHashes = new HashSet<>();
        objHashes.add(1);
        objHashes.add(2);
        objHashes.add(3);
        objHashes.add(4);
        objHashes.add(5);
        CounterRequestByObjHashes counterRequest = new CounterRequestByObjHashes();
        counterRequest.setObjHashes(objHashes);
        assertEquals(objHashes, counterRequest.getObjHashes());
    }

}
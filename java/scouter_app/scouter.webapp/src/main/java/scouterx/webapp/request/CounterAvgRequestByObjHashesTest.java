package scouterx.webapp.request;

import org.junit.Test;

import java.util.HashSet;
import java.util.Set;

import static org.junit.Assert.assertEquals;

public class CounterAvgRequestByObjHashesTest {

  @Test
  public void testSetObjHashes() {
    CounterAvgRequestByObjHashes request = new CounterAvgRequestByObjHashes();
    String objHashes = "1,2,3";
    request.setObjHashes(objHashes);

    Set<Integer> expected = new HashSet<>();
    expected.add(1);
    expected.add(2);
    expected.add(3);

    assertEquals(expected, request.getObjHashes());
  }
}
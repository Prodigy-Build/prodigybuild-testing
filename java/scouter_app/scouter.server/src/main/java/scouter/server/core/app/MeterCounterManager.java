package scouter.server.core.app;

import org.junit.Assert;
import org.junit.Test;

public class MeterCounterManagerTest {
  
  @Test
  public void testGetMeterCounter() {
    // Test case 1
    int objHash1 = 1;
    String counterName1 = "counter1";
    MeterCounter mc1 = MeterCounterManager.getInstance().getMeterCounter(objHash1, counterName1);
    Assert.assertNotNull(mc1);
    
    // Test case 2
    int objHash2 = 2;
    String counterName2 = "counter2";
    MeterCounter mc2 = MeterCounterManager.getInstance().getMeterCounter(objHash2, counterName2);
    Assert.assertNotNull(mc2);
    
    // Test case 3
    int objHash3 = 1;
    String counterName3 = "counter3";
    MeterCounter mc3 = MeterCounterManager.getInstance().getMeterCounter(objHash3, counterName3);
    Assert.assertNotNull(mc3);
    
    // Test case 4
    MeterCounter mc4 = MeterCounterManager.getInstance().getMeterCounter(objHash1, counterName1);
    Assert.assertEquals(mc1, mc4);
    
    // Test case 5
    MeterCounter mc5 = MeterCounterManager.getInstance().getMeterCounter(objHash2, counterName2);
    Assert.assertEquals(mc2, mc5);
  }
}
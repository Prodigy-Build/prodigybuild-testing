```java
package scouter.server.core.app;

import org.junit.Assert;
import org.junit.Test;
import scouter.util.LinkedMap;

public class MeterCounterManagerTest {

    @Test
    public void testGetMeterCounter() {
        MeterCounterManager.Key key = new MeterCounterManager.Key(1, "counter1");
        MeterCounter meterCounter1 = MeterCounterManager.getInstance().getMeterCounter(key.objHash, key.counterName);
        Assert.assertNotNull(meterCounter1);

        MeterCounter meterCounter2 = MeterCounterManager.getInstance().getMeterCounter(key.objHash, key.counterName);
        Assert.assertEquals(meterCounter1, meterCounter2);
    }
}
```
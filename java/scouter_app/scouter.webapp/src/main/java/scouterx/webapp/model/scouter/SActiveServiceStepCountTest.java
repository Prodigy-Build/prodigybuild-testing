import org.junit.Test;
import static org.junit.Assert.*;

public class SActiveServiceStepCountTest {
    
    @Test
    public void of_returnsSActiveServiceStepCountObject() {
        // create test data
        MapPack mapPack = new MapPack();
        mapPack.put(ParamConstant.OBJ_HASH, 123);
        mapPack.put(ParamConstant.ACTIVE_SERVICE_STEP1, 10);
        mapPack.put(ParamConstant.ACTIVE_SERVICE_STEP2, 20);
        mapPack.put(ParamConstant.ACTIVE_SERVICE_STEP3, 30);
        
        // call the method
        SActiveServiceStepCount stepCount = SActiveServiceStepCount.of(mapPack);
        
        // assert the result
        assertNotNull(stepCount);
        assertEquals(123, stepCount.getObjHash());
        assertEquals("UNKNOWN", stepCount.getObjName());
        assertEquals(10, stepCount.getStep1Count());
        assertEquals(20, stepCount.getStep2Count());
        assertEquals(30, stepCount.getStep3Count());
    }
}
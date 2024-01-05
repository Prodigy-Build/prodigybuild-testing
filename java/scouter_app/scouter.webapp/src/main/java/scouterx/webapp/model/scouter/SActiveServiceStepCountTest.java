import org.junit.Test;
import scouter.lang.constants.ParamConstant;
import scouter.lang.pack.MapPack;
import scouterx.webapp.framework.client.model.AgentModelThread;
import scouterx.webapp.model.scouter.SActiveServiceStepCount;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class SActiveServiceStepCountTest {

    @Test
    public void testOf() {
        // create a mock MapPack
        MapPack mapPack = mock(MapPack.class);
        when(mapPack.getInt(ParamConstant.OBJ_HASH)).thenReturn(123);
        when(mapPack.getInt(ParamConstant.ACTIVE_SERVICE_STEP1)).thenReturn(10);
        when(mapPack.getInt(ParamConstant.ACTIVE_SERVICE_STEP2)).thenReturn(20);
        when(mapPack.getInt(ParamConstant.ACTIVE_SERVICE_STEP3)).thenReturn(30);

        // create a mock AgentModelThread
        AgentModelThread agentModelThread = mock(AgentModelThread.class);
        when(agentModelThread.getAgentObject(123)).thenReturn(null);

        // set the mock AgentModelThread as the instance in AgentModelThread class
        AgentModelThread.setInstance(agentModelThread);

        // create the expected SActiveServiceStepCount object
        SActiveServiceStepCount expected = new SActiveServiceStepCount(123, "UNKNOWN", 10, 20, 30);

        // call the of() method and assert the result
        SActiveServiceStepCount result = SActiveServiceStepCount.of(mapPack);
        assertEquals(expected, result);
    }
}
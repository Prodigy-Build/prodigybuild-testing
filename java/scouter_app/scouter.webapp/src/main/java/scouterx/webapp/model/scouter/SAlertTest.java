import org.junit.Test;
import scouter.lang.pack.AlertLevelEnum;
import scouter.lang.pack.AlertPack;
import scouterx.webapp.framework.client.model.AgentModelThread;

import java.util.HashMap;
import java.util.Map;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class SAlertTest {

    @Test
    public void testOf() {
        // create a mock AlertPack
        AlertPack alertPack = mock(AlertPack.class);
        when(alertPack.time()).thenReturn(123456789L);
        when(alertPack.objType()).thenReturn("ObjectType");
        when(alertPack.objHash()).thenReturn(123);
        when(alertPack.level()).thenReturn(1);
        when(alertPack.title()).thenReturn("Alert Title");
        when(alertPack.message()).thenReturn("Alert Message");

        // create a mock AgentModelThread
        AgentModelThread agentModelThread = mock(AgentModelThread.class);
        when(agentModelThread.getAgentObject(123)).thenReturn(null);

        // create a mock tag map
        Map<String, Object> tagMap = new HashMap<>();
        tagMap.put("tag1", "value1");
        tagMap.put("tag2", "value2");

        // create a mock SAlert object
        SAlert expectedAlert = SAlert.builder()
                .time(123456789L)
                .objType("ObjectType")
                .objHash(123)
                .objName("UNKNOWN")
                .level(AlertLevelEnum.WARN)
                .title("Alert Title")
                .message("Alert Message")
                .tagMap(tagMap)
                .build();

        // set up the static methods in SAlert class
        AgentModelThread.setInstance(agentModelThread);

        // call the method under test
        SAlert actualAlert = SAlert.of(alertPack);

        // assert the result
        assertEquals(expectedAlert, actualAlert);
    }
}
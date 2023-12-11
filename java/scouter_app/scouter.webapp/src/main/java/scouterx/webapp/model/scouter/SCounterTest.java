package scouterx.webapp.model.scouter;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

import org.junit.Before;
import org.junit.Test;
import scouter.lang.counters.CounterEngine;
import scouterx.webapp.framework.client.model.AgentModelThread;
import scouterx.webapp.framework.client.model.AgentObject;
import scouterx.webapp.framework.client.server.ServerManager;

public class SCounterTest {
    private SCounter sCounter;
    private int objHash = 1;
    private String name = "testCounter";
    private Object value = 10;

    @Before
    public void setup() {
        AgentModelThread agentModelThread = mock(AgentModelThread.class);
        AgentModelThread.setInstance(agentModelThread);

        AgentObject agentObject = mock(AgentObject.class);
        when(agentModelThread.getAgentObject(objHash)).thenReturn(agentObject);

        ServerManager serverManager = mock(ServerManager.class);
        ServerManager.setInstance(serverManager);

        CounterEngine counterEngine = mock(CounterEngine.class);
        when(serverManager.getServerIfNullDefault(agentObject.getServerId())).thenReturn(serverIfNullDefault);
        when(serverIfNullDefault.getCounterEngine()).thenReturn(counterEngine);

        when(counterEngine.getCounterDisplayName(agentObject.getObjType(), name)).thenReturn("Test Counter");
        when(counterEngine.getCounterUnit(agentObject.getObjType(), name)).thenReturn("Units");

        sCounter = new SCounter(objHash, name, value);
    }

    @Test
    public void testConstructor() {
        assertEquals(objHash, sCounter.getObjHash());
        assertEquals(name, sCounter.getName());
        assertEquals(value, sCounter.getValue());
        assertEquals("Test Counter", sCounter.getDisplayName());
        assertEquals("Units", sCounter.getUnit());
        assertEquals(agentObject.getObjName(), sCounter.getObjName());
    }
}
// Unit tests for SActiveService

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.runners.MockitoJUnitRunner;
import scouter.lang.pack.MapPack;
import scouter.lang.pack.Pack;
import scouter.lang.value.ListValue;
import scouterx.webapp.framework.client.model.AgentModelThread;
import scouterx.webapp.framework.client.model.AgentObject;
import scouterx.webapp.model.enums.ActiveServiceMode;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.when;

@RunWith(MockitoJUnitRunner.class)
public class SActiveServiceTest {

    @Mock
    private AgentModelThread agentModelThread;
    
    @Mock
    private AgentObject agentObject;
    
    @Test
    public void testOfPackList() {
        // Create dummy Pack list
        List<Pack> activeServicePackList = new ArrayList<>();
        
        // Create dummy MapPack
        MapPack mapPack = new MapPack();
        mapPack.put("objHash", 123);
        mapPack.put("id", new ListValue(1));
        mapPack.put("name", new ListValue("Thread 1"));
        mapPack.put("stat", new ListValue("Running"));
        mapPack.put("cpu", new ListValue(100));
        mapPack.put("txid", new ListValue("ABCDE12345"));
        mapPack.put("elapsed", new ListValue(5000));
        mapPack.put("service", new ListValue("Service 1"));
        mapPack.put("ip", new ListValue("127.0.0.1"));
        mapPack.put("sql", new ListValue("SELECT * FROM table"));
        mapPack.put("subcall", new ListValue("apiCall"));
        
        activeServicePackList.add(mapPack);
        
        // Mock agent object
        when(agentObject.getObjName()).thenReturn("Object 1");
        when(agentModelThread.getAgentObject(123)).thenReturn(agentObject);
        
        // Call the method under test
        List<SActiveService> resultList = SActiveService.ofPackList(activeServicePackList);
        
        // Assert the result
        assertEquals(1, resultList.size());
        SActiveService activeService = resultList.get(0);
        assertEquals(123, activeService.getObjHash());
        assertEquals("Object 1", activeService.getObjName());
        assertEquals(1, activeService.getThreadId());
        assertEquals("Thread 1", activeService.getThreadName());
        assertEquals("Running", activeService.getThreadStatus());
        assertEquals(100, activeService.getThreadCpuTime());
        assertEquals("ABCDE12345", activeService.getTxidName());
        assertEquals(5000, activeService.getElapsed());
        assertEquals("Service 1", activeService.getServiceName());
        assertEquals("SELECT * FROM table", activeService.getNote());
        assertEquals(ActiveServiceMode.SQL.name(), activeService.getMode());
        assertEquals("127.0.0.1", activeService.getIpaddr());
        // Verify that sorting is correctly implemented
        // ...
    }
}

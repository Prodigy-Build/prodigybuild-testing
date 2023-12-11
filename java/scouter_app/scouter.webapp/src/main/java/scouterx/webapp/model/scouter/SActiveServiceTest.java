package scouterx.webapp.model.scouter;

import org.junit.jupiter.api.Test;
import scouter.lang.pack.MapPack;
import scouter.lang.pack.Pack;
import scouter.lang.value.ListValue;
import scouter.util.DateUtil;
import scouter.util.Hexa32;
import scouter.util.StringUtil;
import scouterx.webapp.framework.client.model.AgentModelThread;
import scouterx.webapp.framework.client.model.AgentObject;
import scouterx.webapp.model.enums.ActiveServiceMode;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class SActiveServiceTest {

    @Test
    public void testOfPackList() {
        // Given
        List<Pack> activeServicePackList = new ArrayList<>();
        MapPack mapPack = mock(MapPack.class);
        activeServicePackList.add(mapPack);

        when(mapPack.getInt("objHash")).thenReturn(1);
        when(mapPack.getList("id")).thenReturn(new ListValue(new long[]{1, 2}));
        when(mapPack.getList("name")).thenReturn(new ListValue(new String[]{"Thread1", "Thread2"}));
        when(mapPack.getList("stat")).thenReturn(new ListValue(new String[]{"Running", "Waiting"}));
        when(mapPack.getList("cpu")).thenReturn(new ListValue(new long[]{100, 50}));
        when(mapPack.getList("txid")).thenReturn(new ListValue(new String[]{"123", "456"}));
        when(mapPack.getList("elapsed")).thenReturn(new ListValue(new long[]{1000, 2000}));
        when(mapPack.getList("service")).thenReturn(new ListValue(new String[]{"Service1", "Service2"}));
        when(mapPack.getList("ip")).thenReturn(new ListValue(new String[]{"127.0.0.1", "127.0.0.2"}));
        when(mapPack.getList("sql")).thenReturn(new ListValue(new String[]{"SELECT * FROM table", ""}));
        when(mapPack.getList("subcall")).thenReturn(new ListValue(new String[]{"API1", ""}));

        AgentObject agentObject = mock(AgentObject.class);
        AgentModelThread agentModelThread = mock(AgentModelThread.class);
        when(AgentModelThread.getInstance()).thenReturn(agentModelThread);
        when(agentModelThread.getAgentObject(1)).thenReturn(agentObject);
        when(agentObject.getObjName()).thenReturn("Object1");

        // When
        List<SActiveService> actual = SActiveService.ofPackList(activeServicePackList);
		
        // Then
        assertEquals(2, actual.size());
        assertEquals(1, actual.get(0).getObjHash());
        assertEquals("Object1", actual.get(0).getObjName());
        assertEquals(1, actual.get(0).getThreadId());
        assertEquals("Thread1", actual.get(0).getThreadName());
        assertEquals("Running", actual.get(0).getThreadStatus());
        assertEquals(100, actual.get(0).getThreadCpuTime());
        assertEquals("123", actual.get(0).getTxidName());
        assertEquals(1000, actual.get(0).getElapsed());
        assertEquals("Service1", actual.get(0).getServiceName());
        assertEquals("127.0.0.1", actual.get(0).getIpaddr());
        assertEquals("SELECT * FROM table", actual.get(0).getNote());
        assertEquals(ActiveServiceMode.SQL.name(), actual.get(0).getMode());

        assertEquals(1, actual.get(1).getObjHash());
        assertEquals("Object1", actual.get(1).getObjName());
        assertEquals(2, actual.get(1).getThreadId());
        assertEquals("Thread2", actual.get(1).getThreadName());
        assertEquals("Waiting", actual.get(1).getThreadStatus());
        assertEquals(50, actual.get(1).getThreadCpuTime());
        assertEquals("456", actual.get(1).getTxidName());
        assertEquals(2000, actual.get(1).getElapsed());
        assertEquals("Service2", actual.get(1).getServiceName());
        assertEquals("127.0.0.2", actual.get(1).getIpaddr());
        assertEquals("API1", actual.get(1).getNote());
        assertEquals(ActiveServiceMode.SUBCALL.name(), actual.get(1).getMode());
    }

}

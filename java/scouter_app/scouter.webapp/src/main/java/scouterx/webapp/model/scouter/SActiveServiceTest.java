// Unit Test for SActiveService

import org.junit.Test;

import static org.junit.Assert.*;

public class SActiveServiceTest {

    @Test
    public void testOfPackList() {
        // Given
        List<Pack> activeServicePackList = new ArrayList<>();

        MapPack pack1 = new MapPack();
        pack1.put("objHash", 1);
        pack1.put("id", new ListValue(Arrays.asList(101L, 102L, 103L)));
        pack1.put("name", new ListValue(Arrays.asList("Thread1", "Thread2", "Thread3")));
        pack1.put("stat", new ListValue(Arrays.asList("Running", "Blocked", "Running")));
        pack1.put("cpu", new ListValue(Arrays.asList(50L, 100L, 75L)));
        pack1.put("txid", new ListValue(Arrays.asList("ABCD", "EFGH", "IJKL")));
        pack1.put("elapsed", new ListValue(Arrays.asList(200L, 100L, 150L)));
        pack1.put("service", new ListValue(Arrays.asList("Service1", "Service2", "Service3")));
        pack1.put("ip", new ListValue(Arrays.asList("127.0.0.1", "192.168.0.1", "10.0.0.1")));
        pack1.put("sql", new ListValue(Arrays.asList("SELECT * FROM Table", "", "INSERT INTO Table")));
        pack1.put("subcall", new ListValue(Arrays.asList("", "Call1", "")));

        MapPack pack2 = new MapPack();
        pack2.put("objHash", 2);
        pack2.put("id", new ListValue(Arrays.asList(201L, 202L, 203L)));
        pack2.put("name", new ListValue(Arrays.asList("Thread4", "Thread5", "Thread6")));
        pack2.put("stat", new ListValue(Arrays.asList("Waiting", "Running", "Running")));
        pack2.put("cpu", new ListValue(Arrays.asList(80L, 120L, 90L)));
        pack2.put("txid", new ListValue(Arrays.asList("MNOP", "QRST", "UVWX")));
        pack2.put("elapsed", new ListValue(Arrays.asList(80L, 60L, 100L)));
        pack2.put("service", new ListValue(Arrays.asList("Service4", "Service5", "Service6")));
        pack2.put("ip", new ListValue(Arrays.asList("192.168.1.1", "10.0.0.2", "172.16.0.1")));
        pack2.put("sql", new ListValue(Arrays.asList("", "UPDATE Table SET Column = 0", "SELECT * FROM Table")));
        pack2.put("subcall", new ListValue(Arrays.asList("", "", "")));

        activeServicePackList.add(pack1);
        activeServicePackList.add(pack2);

        // When
        List<SActiveService> resultList = SActiveService.ofPackList(activeServicePackList);

        // Then
        assertEquals(6, resultList.size());

        SActiveService activeService1 = resultList.get(0);
        assertEquals(1, activeService1.getObjHash());
        assertEquals("Thread2", activeService1.getThreadName());
        assertEquals("Blocked", activeService1.getThreadStatus());
        assertEquals(100L, activeService1.getThreadCpuTime());
        assertEquals("EFGH", activeService1.getTxidName());
        assertEquals(100L, activeService1.getElapsed());
        assertEquals("Service2", activeService1.getServiceName());
        assertEquals("192.168.0.1", activeService1.getIpaddr());
        assertEquals("SELECT * FROM Table", activeService1.getNote());
        assertEquals("SQL", activeService1.getMode());

        SActiveService activeService2 = resultList.get(3);
        assertEquals(2, activeService2.getObjHash());
        assertEquals("Thread5", activeService2.getThreadName());
        assertEquals("Running", activeService2.getThreadStatus());
        assertEquals(120L, activeService2.getThreadCpuTime());
        assertEquals("QRST", activeService2.getTxidName());
        assertEquals(60L, activeService2.getElapsed());
        assertEquals("Service5", activeService2.getServiceName());
        assertEquals("10.0.0.2", activeService2.getIpaddr());
        assertEquals("UPDATE Table SET Column = 0", activeService2.getNote());
        assertEquals("SUBCALL", activeService2.getMode());
    }
}
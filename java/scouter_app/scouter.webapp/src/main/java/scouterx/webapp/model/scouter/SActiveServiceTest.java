@Test
public void testOfPackList() {
    // Create mock activeServicePackList
    List<Pack> activeServicePackList = new ArrayList<>();
    MapPack mapPack1 = new MapPack();
    mapPack1.put("objHash", 123);
    mapPack1.put("id", new ListValue(1L));
    mapPack1.put("name", new ListValue("Thread1"));
    mapPack1.put("stat", new ListValue("Running"));
    mapPack1.put("cpu", new ListValue(100L));
    mapPack1.put("txid", new ListValue("ABC123"));
    mapPack1.put("elapsed", new ListValue(500L));
    mapPack1.put("service", new ListValue("Service1"));
    mapPack1.put("ip", new ListValue("127.0.0.1"));
    activeServicePackList.add(mapPack1);
    
    MapPack mapPack2 = new MapPack();
    mapPack2.put("objHash", 456);
    mapPack2.put("id", new ListValue(2L));
    mapPack2.put("name", new ListValue("Thread2"));
    mapPack2.put("stat", new ListValue("Waiting"));
    mapPack2.put("cpu", new ListValue(200L));
    mapPack2.put("txid", new ListValue("DEF456"));
    mapPack2.put("elapsed", new ListValue(1000L));
    mapPack2.put("service", new ListValue("Service2"));
    mapPack2.put("ip", new ListValue("192.168.0.1"));
    activeServicePackList.add(mapPack2);
    
    // Create mock agentObject
    AgentObject agentObject1 = new AgentObject();
    agentObject1.setObjName("Object1");
    AgentObject agentObject2 = new AgentObject();
    agentObject2.setObjName("Object2");
    
    // Set up AgentModelThread mock
    AgentModelThread agentModelThreadMock = mock(AgentModelThread.class);
    when(agentModelThreadMock.getAgentObject(123)).thenReturn(agentObject1);
    when(agentModelThreadMock.getAgentObject(456)).thenReturn(agentObject2);
    
    // Set AgentModelThread mock to SActiveService
    AgentModelThread.setInstance(agentModelThreadMock);
    
    // Call ofPackList method
    List<SActiveService> resultList = SActiveService.ofPackList(activeServicePackList);
    
    // Verify the results
    assertEquals(2, resultList.size());
    
    SActiveService activeService1 = resultList.get(0);
    assertEquals(123, activeService1.getObjHash());
    assertEquals("Object1", activeService1.getObjName());
    assertEquals(1L, activeService1.getThreadId());
    assertEquals("Thread1", activeService1.getThreadName());
    assertEquals("Running", activeService1.getThreadStatus());
    assertEquals(100L, activeService1.getThreadCpuTime());
    assertEquals("ABC123", activeService1.getTxidName());
    assertEquals(500L, activeService1.getElapsed());
    assertEquals("Service1", activeService1.getServiceName());
    assertEquals("127.0.0.1", activeService1.getIpaddr());
    assertNull(activeService1.getNote());
    assertEquals("NONE", activeService1.getMode());
    assertEquals(3637006165L, activeService1.getTxid());
    assertNotNull(activeService1.getActiveDate());
    
    SActiveService activeService2 = resultList.get(1);
    assertEquals(456, activeService2.getObjHash());
    assertEquals("Object2", activeService2.getObjName());
    assertEquals(2L, activeService2.getThreadId());
    assertEquals("Thread2", activeService2.getThreadName());
    assertEquals("Waiting", activeService2.getThreadStatus());
    assertEquals(200L, activeService2.getThreadCpuTime());
    assertEquals("DEF456", activeService2.getTxidName());
    assertEquals(1000L, activeService2.getElapsed());
    assertEquals("Service2", activeService2.getServiceName());
    assertEquals("192.168.0.1", activeService2.getIpaddr());
    assertNull(activeService2.getNote());
    assertEquals("NONE", activeService2.getMode());
    assertEquals(3733802070L, activeService2.getTxid());
    assertNotNull(activeService2.getActiveDate());
}
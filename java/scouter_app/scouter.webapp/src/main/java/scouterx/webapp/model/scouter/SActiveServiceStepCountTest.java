@Test
public void testOf() {
    MapPack mapPack = new MapPack();
    mapPack.put(ParamConstant.OBJ_HASH, 123);
    mapPack.put(ParamConstant.ACTIVE_SERVICE_STEP1, 10);
    mapPack.put(ParamConstant.ACTIVE_SERVICE_STEP2, 20);
    mapPack.put(ParamConstant.ACTIVE_SERVICE_STEP3, 30);

    SActiveServiceStepCount sActiveServiceStepCount = SActiveServiceStepCount.of(mapPack);

    assertEquals(123, sActiveServiceStepCount.getObjHash());
    assertEquals("UNKNOWN", sActiveServiceStepCount.getObjName());
    assertEquals(10, sActiveServiceStepCount.getStep1Count());
    assertEquals(20, sActiveServiceStepCount.getStep2Count());
    assertEquals(30, sActiveServiceStepCount.getStep3Count());
}
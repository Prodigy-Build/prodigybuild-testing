package scouterx.webapp.model.scouter;

import org.junit.Assert;
import org.junit.Test;
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

public class SActiveServiceTest {

    @Test
    public void testOfPackList() {
        List<Pack> activeServicePackList = new ArrayList<>();
        MapPack mapPack = new MapPack();
        mapPack.put("objHash", 123);
        mapPack.put("id", new ListValue(1));
        mapPack.put("name", new ListValue("Thread 1"));
        mapPack.put("stat", new ListValue("Running"));
        mapPack.put("cpu", new ListValue(1000L));
        mapPack.put("txid", new ListValue("ABC123"));
        mapPack.put("elapsed", new ListValue(500L));
        mapPack.put("service", new ListValue("Service 1"));
        mapPack.put("ip", new ListValue("127.0.0.1"));
        mapPack.put("sql", new ListValue(""));
        mapPack.put("subcall", new ListValue(""));

        activeServicePackList.add(mapPack);

        List<SActiveService> resultList = SActiveService.ofPackList(activeServicePackList);

        Assert.assertEquals(1, resultList.size());
        SActiveService activeService = resultList.get(0);
        Assert.assertEquals(123, activeService.getObjHash());
        Assert.assertEquals("Thread 1", activeService.getThreadName());
        Assert.assertEquals("Running", activeService.getThreadStatus());
        Assert.assertEquals(1000L, activeService.getThreadCpuTime());
        Assert.assertEquals("ABC123", activeService.getTxidName());
        Assert.assertEquals(500L, activeService.getElapsed());
        Assert.assertEquals("Service 1", activeService.getServiceName());
        Assert.assertEquals("127.0.0.1", activeService.getIpaddr());
        Assert.assertEquals("", activeService.getNote());
        Assert.assertEquals(ActiveServiceMode.NONE.name(), activeService.getMode());
        Assert.assertEquals(500L, activeService.getElapsed());
        Assert.assertEquals(DateUtil.yyyymmdd(), activeService.getActiveDate());
    }
}
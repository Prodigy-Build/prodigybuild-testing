package scouterx.webapp.view;

import org.junit.Test;
import static org.junit.Assert.*;

public class CounterViewTest {

    @Test
    public void testGetterAndSetter() {
        int objHash = 123;
        String objName = "TestObject";
        long startTimeMillis = System.currentTimeMillis();
        long endTimeMillis = startTimeMillis + 1000;
        String name = "TestCounter";
        String displayName = "Test Counter";
        String unit = "ms";
        List<Long> timeList = Arrays.asList(startTimeMillis, endTimeMillis);
        List<Double> valueList = Arrays.asList(10.0, 20.0);

        CounterView counterView = CounterView.builder()
                .objHash(objHash)
                .objName(objName)
                .startTimeMillis(startTimeMillis)
                .endTimeMillis(endTimeMillis)
                .name(name)
                .displayName(displayName)
                .unit(unit)
                .timeList(timeList)
                .valueList(valueList)
                .build();

        assertEquals(objHash, counterView.getObjHash());
        assertEquals(objName, counterView.getObjName());
        assertEquals(startTimeMillis, counterView.getStartTimeMillis());
        assertEquals(endTimeMillis, counterView.getEndTimeMillis());
        assertEquals(name, counterView.getName());
        assertEquals(displayName, counterView.getDisplayName());
        assertEquals(unit, counterView.getUnit());
        assertEquals(timeList, counterView.getTimeList());
        assertEquals(valueList, counterView.getValueList());
    }
}
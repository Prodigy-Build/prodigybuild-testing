// Unit tests for the CounterView class

import org.junit.Test;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class CounterViewTest {

    @Test
    public void testCounterViewObjHash() {
        CounterView counterView = CounterView.builder()
                .objHash(12345)
                .build();

        assertEquals(12345, counterView.getObjHash());
    }

    @Test
    public void testCounterViewObjName() {
        CounterView counterView = CounterView.builder()
                .objName("Object1")
                .build();

        assertEquals("Object1", counterView.getObjName());
    }

    @Test
    public void testCounterViewStartTimeMillis() {
        CounterView counterView = CounterView.builder()
                .startTimeMillis(1594400000000L)
                .build();

        assertEquals(1594400000000L, counterView.getStartTimeMillis());
    }

    @Test
    public void testCounterViewEndTimeMillis() {
        CounterView counterView = CounterView.builder()
                .endTimeMillis(1594400060000L)
                .build();

        assertEquals(1594400060000L, counterView.getEndTimeMillis());
    }

    @Test
    public void testCounterViewName() {
        CounterView counterView = CounterView.builder()
                .name("Counter1")
                .build();

        assertEquals("Counter1", counterView.getName());
    }

    @Test
    public void testCounterViewDisplayName() {
        CounterView counterView = CounterView.builder()
                .displayName("Counter 1")
                .build();

        assertEquals("Counter 1", counterView.getDisplayName());
    }

    @Test
    public void testCounterViewUnit() {
        CounterView counterView = CounterView.builder()
                .unit("ms")
                .build();

        assertEquals("ms", counterView.getUnit());
    }

    @Test
    public void testCounterViewTimeList() {
        List<Long> timeList = Arrays.asList(1594400000000L, 1594400010000L, 1594400020000L);
        CounterView counterView = CounterView.builder()
                .timeList(timeList)
                .build();

        assertEquals(timeList, counterView.getTimeList());
    }

    @Test
    public void testCounterViewValueList() {
        List<Double> valueList = Arrays.asList(0.5, 1.5, 2.5);
        CounterView counterView = CounterView.builder()
                .valueList(valueList)
                .build();

        assertEquals(valueList, counterView.getValueList());
    }
}
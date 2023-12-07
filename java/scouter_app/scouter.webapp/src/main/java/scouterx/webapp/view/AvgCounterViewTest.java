// Unit test for AvgCounterView class
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

public class AvgCounterViewTest {

    @Test
    public void testAvgCounterView() {
        // Create sample data
        int objHash = 123;
        String objName = "Object1";
        String fromYmd = "2021-01-01";
        String toYmd = "2021-01-31";
        String name = "Counter";
        String displayName = "Counter";
        String unit = "count";
        List<Long> timeList = Arrays.asList(1L, 2L, 3L, 4L, 5L);
        List<Double> valueList = Arrays.asList(10.0, 20.0, 30.0, 40.0, 50.0);

        // Create AvgCounterView object using the builder pattern
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .objHash(objHash)
                .objName(objName)
                .fromYmd(fromYmd)
                .toYmd(toYmd)
                .name(name)
                .displayName(displayName)
                .unit(unit)
                .timeList(timeList)
                .valueList(valueList)
                .build();

        // Assert that the object is created correctly
        assertNotNull(avgCounterView);
        assertEquals(objHash, avgCounterView.getObjHash());
        assertEquals(objName, avgCounterView.getObjName());
        assertEquals(fromYmd, avgCounterView.getFromYmd());
        assertEquals(toYmd, avgCounterView.getToYmd());
        assertEquals(name, avgCounterView.getName());
        assertEquals(displayName, avgCounterView.getDisplayName());
        assertEquals(unit, avgCounterView.getUnit());
        assertEquals(timeList, avgCounterView.getTimeList());
        assertEquals(valueList, avgCounterView.getValueList());
    }
}
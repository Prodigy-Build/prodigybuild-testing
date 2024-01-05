package scouterx.webapp.view;

import org.junit.Test;
import static org.junit.Assert.*;

public class AvgCounterViewTest {

    @Test
    public void testGetObjHash() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .objHash(123)
                .build();
        assertEquals(123, avgCounterView.getObjHash());
    }

    @Test
    public void testGetObjName() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .objName("testObj")
                .build();
        assertEquals("testObj", avgCounterView.getObjName());
    }

    @Test
    public void testGetFromYmd() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .fromYmd("2020-01-01")
                .build();
        assertEquals("2020-01-01", avgCounterView.getFromYmd());
    }

    @Test
    public void testGetToYmd() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .toYmd("2020-12-31")
                .build();
        assertEquals("2020-12-31", avgCounterView.getToYmd());
    }

    @Test
    public void testGetName() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .name("testName")
                .build();
        assertEquals("testName", avgCounterView.getName());
    }

    @Test
    public void testGetDisplayName() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .displayName("Test Display Name")
                .build();
        assertEquals("Test Display Name", avgCounterView.getDisplayName());
    }

    @Test
    public void testGetUnit() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .unit("ms")
                .build();
        assertEquals("ms", avgCounterView.getUnit());
    }

    @Test
    public void testGetTimeList() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .timeList(Arrays.asList(1L, 2L, 3L))
                .build();
        assertEquals(Arrays.asList(1L, 2L, 3L), avgCounterView.getTimeList());
    }

    @Test
    public void testGetValueList() {
        AvgCounterView avgCounterView = AvgCounterView.builder()
                .valueList(Arrays.asList(1.0, 2.0, 3.0))
                .build();
        assertEquals(Arrays.asList(1.0, 2.0, 3.0), avgCounterView.getValueList());
    }
}
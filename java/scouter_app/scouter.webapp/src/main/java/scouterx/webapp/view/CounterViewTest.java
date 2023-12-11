import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class CounterViewTest {
  
  @Test
  public void testGetters() {
    CounterView counterView = CounterView.builder()
        .objHash(123)
        .objName("TestObject")
        .startTimeMillis(System.currentTimeMillis())
        .endTimeMillis(System.currentTimeMillis() + 1000)
        .name("Counter")
        .displayName("Test Counter")
        .unit("ms")
        .timeList(List.of(1L, 2L, 3L))
        .valueList(List.of(0.5, 1.0, 1.5))
        .build();
    
    assertEquals(123, counterView.getObjHash());
    assertEquals("TestObject", counterView.getObjName());
    assertEquals("Counter", counterView.getName());
    assertEquals("Test Counter", counterView.getDisplayName());
    assertEquals("ms", counterView.getUnit());
    assertEquals(List.of(1L, 2L, 3L), counterView.getTimeList());
    assertEquals(List.of(0.5, 1.0, 1.5), counterView.getValueList());
  }
  
}
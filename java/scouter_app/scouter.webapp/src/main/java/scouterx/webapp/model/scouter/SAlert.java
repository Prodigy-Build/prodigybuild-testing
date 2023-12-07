import org.junit.Assert;
import org.junit.Test;

public class SAlertTest {

    @Test
    public void testSAlertOf() {
        AlertPack alertPack = new AlertPack();
        alertPack.time = 1623124032;
        alertPack.objType = "TestClass";
        alertPack.objHash = 123456789;
        alertPack.level = 2;
        alertPack.title = "Test Alert";
        alertPack.message = "This is a test alert";
        alertPack.tags = new HashMap<>();
        alertPack.tags.put("tag1", "value1");
        alertPack.tags.put("tag2", "value2");

        SAlert sAlert = SAlert.of(alertPack);

        Assert.assertEquals(1623124032, sAlert.getTime());
        Assert.assertEquals("TestClass", sAlert.getObjType());
        Assert.assertEquals(123456789, sAlert.getObjHash());
        Assert.assertEquals("Test Alert", sAlert.getTitle());
        Assert.assertEquals("This is a test alert", sAlert.getMessage());
        Assert.assertEquals(2, sAlert.getLevel().getValue());
        Assert.assertEquals("value1", sAlert.getTagMap().get("tag1"));
        Assert.assertEquals("value2", sAlert.getTagMap().get("tag2"));
    }
}
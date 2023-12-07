package scouterx.webapp.model.alertscript;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

public class ScriptingLogStateDataTest {

    private ScriptingLogStateData scriptingLogStateData;

    @Before
    public void setUp() {
        scriptingLogStateData = new ScriptingLogStateData();
    }

    @Test
    public void testGetLoop() {
        scriptingLogStateData.setLoop(10);
        Assert.assertEquals(10, scriptingLogStateData.getLoop());
    }

    @Test
    public void testGetIndex() {
        scriptingLogStateData.setIndex(5);
        Assert.assertEquals(5, scriptingLogStateData.getIndex());
    }

    @Test
    public void testGetMessage() {
        List<String> expectedList = new ArrayList<>();
        expectedList.add("message1");
        expectedList.add("message2");

        scriptingLogStateData.setMessage(expectedList);

        Assert.assertEquals(expectedList, scriptingLogStateData.getMessage());
    }
}
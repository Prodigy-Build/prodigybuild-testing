package scouterx.webapp.model.alertscript;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

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
    public void testDefaultValues() {
        assertEquals(0, scriptingLogStateData.getLoop());
        assertEquals(0, scriptingLogStateData.getIndex());
        assertTrue(scriptingLogStateData.getMessage().isEmpty());
    }

    @Test
    public void testSetLoop() {
        long loop = 10;
        scriptingLogStateData.setLoop(loop);
        assertEquals(loop, scriptingLogStateData.getLoop());
    }

    @Test
    public void testSetIndex() {
        long index = 5;
        scriptingLogStateData.setIndex(index);
        assertEquals(index, scriptingLogStateData.getIndex());
    }

    @Test
    public void testSetMessage() {
        List<String> message = new ArrayList<>();
        message.add("message1");
        message.add("message2");
        scriptingLogStateData.setMessage(message);
        assertEquals(message, scriptingLogStateData.getMessage());
    }
}
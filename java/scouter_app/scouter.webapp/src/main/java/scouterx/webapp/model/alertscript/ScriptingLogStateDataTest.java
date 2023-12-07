package scouterx.webapp.model.alertscript;

import org.junit.Test;
import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.List;

public class ScriptingLogStateDataTest {

    @Test
    public void testDefaultConstructor() {
        ScriptingLogStateData data = new ScriptingLogStateData();
        assertEquals(0, data.getLoop());
        assertEquals(0, data.getIndex());
        assertNotNull(data.getMessage());
        assertTrue(data.getMessage().isEmpty());
    }

    @Test
    public void testGettersAndSetters() {
        ScriptingLogStateData data = new ScriptingLogStateData();

        data.setLoop(10);
        assertEquals(10, data.getLoop());

        data.setIndex(5);
        assertEquals(5, data.getIndex());

        List<String> messages = new ArrayList<>();
        messages.add("Message 1");
        data.setMessage(messages);
        assertEquals(messages, data.getMessage());
    }
}
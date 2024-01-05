package scouterx.webapp.model.alertscript;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

public class ScriptingLogStateDataTest {

    @Test
    public void testDefaultConstructor() {
        ScriptingLogStateData data = new ScriptingLogStateData();

        assertEquals(0, data.getLoop());
        assertEquals(0, data.getIndex());
        assertNotNull(data.getMessage());
        assertEquals(0, data.getMessage().size());
    }

    @Test
    public void testSetterAndGetter() {
        ScriptingLogStateData data = new ScriptingLogStateData();

        data.setLoop(10);
        data.setIndex(5);
        List<String> messages = new ArrayList<>();
        messages.add("Message 1");
        messages.add("Message 2");
        data.setMessage(messages);

        assertEquals(10, data.getLoop());
        assertEquals(5, data.getIndex());
        assertNotNull(data.getMessage());
        assertEquals(2, data.getMessage().size());
        assertEquals("Message 1", data.getMessage().get(0));
        assertEquals("Message 2", data.getMessage().get(1));
    }
}
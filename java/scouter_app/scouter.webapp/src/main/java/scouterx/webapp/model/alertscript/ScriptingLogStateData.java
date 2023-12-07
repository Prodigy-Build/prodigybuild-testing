package scouterx.webapp.model.alertscript;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ScriptingLogStateDataTest {

    @Test
    public void testConstructor() {
        // Given
        long expectedLoop = 0;
        long expectedIndex = 0;
        List<String> expectedMessage = new ArrayList<>();

        // When
        ScriptingLogStateData stateData = new ScriptingLogStateData();

        // Then
        assertEquals(expectedLoop, stateData.getLoop());
        assertEquals(expectedIndex, stateData.getIndex());
        assertEquals(expectedMessage, stateData.getMessage());
    }
}
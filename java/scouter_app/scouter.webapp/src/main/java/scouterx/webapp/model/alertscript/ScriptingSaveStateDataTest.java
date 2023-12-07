package scouterx.webapp.model.alertscript;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public class ScriptingSaveStateData {
    int status;
    String message;

    //default define
    public ScriptingSaveStateData(){
        this.message = "No settings have been changed";
        this.status = 301;
    }
}


Below is the unit test for the ScriptingSaveStateData class:

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

class ScriptingSaveStateDataTest {
    @Test
    void testDefaultConstructor() {
        ScriptingSaveStateData data = new ScriptingSaveStateData();
        assertEquals("No settings have been changed", data.getMessage());
        asserEquals(301, data.getStatus());
    }
}
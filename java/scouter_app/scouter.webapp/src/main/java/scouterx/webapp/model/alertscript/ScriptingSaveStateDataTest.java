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
    
    // Unit tests
    public static void main(String[] args) {
        testDefaultConstructor();
    }
    
    private static void testDefaultConstructor() {
        ScriptingSaveStateData data = new ScriptingSaveStateData();
        assert data.getStatus() == 301;
        assert data.getMessage().equals("No settings have been changed");
    }
}
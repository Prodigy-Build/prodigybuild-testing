package scouterx.webapp.model.alertscript;

import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public class ScriptingSaveStateData {
    private int status;
    private String message;

    public ScriptingSaveStateData() {
        this.message = "No settings have been changed";
        this.status = 301;
    }

    // Include unit tests below

    public static void main(String[] args) {
        testDefaultConstructor();
    }

    public static void testDefaultConstructor() {
        ScriptingSaveStateData data = new ScriptingSaveStateData();
        assert data.getStatus() == 301;
        assert data.getMessage().equals("No settings have been changed");
    }
}
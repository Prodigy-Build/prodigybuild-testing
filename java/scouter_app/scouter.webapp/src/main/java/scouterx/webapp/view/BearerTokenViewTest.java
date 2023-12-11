package scouterx.webapp.view;

import org.junit.Test;
import static org.junit.Assert.*;

public class BearerTokenViewTest {

    @Test
    public void testGetterAndSetter() {
        boolean success = true;
        String bearerToken = "1234567890";

        BearerTokenView tokenView = new BearerTokenView(success, bearerToken);

        assertEquals(success, tokenView.isSuccess());
        assertEquals(bearerToken, tokenView.getBearerToken());
    }
}
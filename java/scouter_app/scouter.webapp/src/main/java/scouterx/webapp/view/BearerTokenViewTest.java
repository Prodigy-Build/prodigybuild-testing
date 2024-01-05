package scouterx.webapp.view;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class BearerTokenViewTest {

    @Test
    public void testConstructorAndGetters() {
        boolean success = true;
        String bearerToken = "abc123";

        BearerTokenView bearerTokenView = new BearerTokenView(success, bearerToken);

        Assertions.assertEquals(success, bearerTokenView.isSuccess());
        Assertions.assertEquals(bearerToken, bearerTokenView.getBearerToken());
    }
}
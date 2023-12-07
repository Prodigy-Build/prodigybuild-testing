package scouterx.webapp.view;

import org.junit.Assert;
import org.junit.Test;

public class BearerTokenViewTest {

    @Test
    public void testConstructorAndGetters() {
        boolean success = true;
        String bearerToken = "12345";
        BearerTokenView bearerTokenView = new BearerTokenView(success, bearerToken);

        Assert.assertEquals(success, bearerTokenView.isSuccess());
        Assert.assertEquals(bearerToken, bearerTokenView.getBearerToken());
    }
}
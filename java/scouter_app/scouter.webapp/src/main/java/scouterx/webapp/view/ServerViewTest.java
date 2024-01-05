package scouterx.webapp.view;

import org.junit.Assert;
import org.junit.Test;

public class ServerViewTest {

    @Test
    public void testGetId() {
        ServerView serverView = new ServerView(1, "Server1", true, 1234567890L, "1.0.0");
        Assert.assertEquals(1, serverView.getId());
    }

    @Test
    public void testGetName() {
        ServerView serverView = new ServerView(1, "Server1", true, 1234567890L, "1.0.0");
        Assert.assertEquals("Server1", serverView.getName());
    }

    @Test
    public void testIsConnected() {
        ServerView serverView = new ServerView(1, "Server1", true, 1234567890L, "1.0.0");
        Assert.assertTrue(serverView.isConnected());
    }

    @Test
    public void testGetServerTime() {
        ServerView serverView = new ServerView(1, "Server1", true, 1234567890L, "1.0.0");
        Assert.assertEquals(1234567890L, serverView.getServerTime());
    }

    @Test
    public void testGetVersion() {
        ServerView serverView = new ServerView(1, "Server1", true, 1234567890L, "1.0.0");
        Assert.assertEquals("1.0.0", serverView.getVersion());
    }
}
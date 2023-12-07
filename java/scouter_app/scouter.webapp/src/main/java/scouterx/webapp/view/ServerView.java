// Unit tests for ServerView class

import org.junit.Test;

import static org.junit.Assert.*;

public class ServerViewTest {

    @Test
    public void testGetId() {
        ServerView serverView = new ServerView(1, "Server", true, System.currentTimeMillis(), "1.0");
        assertEquals(1, serverView.getId());
    }

    @Test
    public void testGetName() {
        ServerView serverView = new ServerView(1, "Server", true, System.currentTimeMillis(), "1.0");
        assertEquals("Server", serverView.getName());
    }

    @Test
    public void testIsConnected() {
        ServerView serverView = new ServerView(1, "Server", true, System.currentTimeMillis(), "1.0");
        assertTrue(serverView.isConnected());
    }

    @Test
    public void testGetServerTime() {
        long currentTime = System.currentTimeMillis();
        ServerView serverView = new ServerView(1, "Server", true, currentTime, "1.0");
        assertEquals(currentTime, serverView.getServerTime());
    }

    @Test
    public void testGetVersion() {
        ServerView serverView = new ServerView(1, "Server", true, System.currentTimeMillis(), "1.0");
        assertEquals("1.0", serverView.getVersion());
    }
}
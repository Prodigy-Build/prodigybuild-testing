// Unit test for ServerView class

import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class ServerViewTest {

    @Test
    public void testGetterMethods() {
        ServerView serverView = new ServerView(1, "Server 1", true, 1234567890L, "1.0");
        assertEquals(1, serverView.getId());
        assertEquals("Server 1", serverView.getName());
        assertEquals(true, serverView.isConnected());
        assertEquals(1234567890L, serverView.getServerTime());
        assertEquals("1.0", serverView.getVersion());
    }
}
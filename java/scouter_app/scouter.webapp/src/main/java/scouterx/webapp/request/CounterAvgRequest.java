```java
import org.junit.jupiter.api.Test;
import scouterx.webapp.framework.client.server.ServerManager;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.Mockito.*;

public class CounterAvgRequestTest {

    @Test
    public void setServerId_whenServerIdIsSet_shouldUpdateServerId() {
        // given
        int serverId = 1;
        ServerManager serverManager = mock(ServerManager.class);
        when(serverManager.getServerIfNullDefault(serverId)).thenReturn(new Server());

        CounterAvgRequest request = new CounterAvgRequest();
        request.setServerId(serverId);

        // when
        int actualServerId = request.getServerId();

        // then
        assertEquals(serverId, actualServerId);
    }

    private static class ServerManager {
        private static final ServerManager INSTANCE = new ServerManager();

        public static ServerManager getInstance() {
            return INSTANCE;
        }

        public Server getServerIfNullDefault(int serverId) {
            // implementation not required for testing
            return null;
        }
    }

    private static class Server {
        public int getId() {
            // implementation not required for testing
            return 0;
        }
    }
}
```
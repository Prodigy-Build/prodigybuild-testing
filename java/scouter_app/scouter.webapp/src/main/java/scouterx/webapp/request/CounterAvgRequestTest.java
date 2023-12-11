@RunWith(MockitoJUnitRunner.class)
public class CounterAvgRequestTest {

    @Test
    public void testSetServerId() {
        // mock ServerManager
        ServerManager serverManager = Mockito.mock(ServerManager.class);
        Mockito.when(serverManager.getServerIfNullDefault(1)).thenReturn(new Server(1));

        // create CounterAvgRequest instance
        CounterAvgRequest request = new CounterAvgRequest();

        // set mock ServerManager
        Whitebox.setInternalState(ServerManager.class, serverManager);

        // set serverId using setServerId method
        request.setServerId(1);

        // verify that serverId is correctly set
        Assert.assertEquals(1, request.getServerId());
    }
}
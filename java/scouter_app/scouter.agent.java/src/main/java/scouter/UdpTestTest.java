package scouter;

import org.junit.Test;
import org.mockito.Mockito;

import scouter.agent.netio.data.net.DataUdpAgent;

public class UdpTest {

	@Test
	public void testMain() {
		String[] args = new String[0];
		DataUdpAgent dataUdpAgentMock = Mockito.mock(DataUdpAgent.class);
		Mockito.doNothing().when(dataUdpAgentMock).main(args);
		
		UdpTest.main(args);
		
		Mockito.verify(dataUdpAgentMock).main(args);
	}

}
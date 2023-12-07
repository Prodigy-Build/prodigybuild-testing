package scouter;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.runners.MockitoJUnitRunner;
import scouter.agent.netio.data.DataProxy;
import scouter.agent.trace.TraceApiCall;
import scouter.agent.trace.TraceContext;
import scouter.agent.trace.TraceContextManager;
import scouter.agent.trace.TraceMain;
import scouter.lang.pack.XLogTypes;
import scouter.util.KeyGen;

import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

@RunWith(MockitoJUnitRunner.class)
public class AnyTraceTest {

    @Mock
    private TraceContext traceContext;

    @InjectMocks
    private AnyTrace anyTrace;

    @Test
    public void message_shouldCallTraceMainAddMessage() {
        String name = "test message";
        TraceMain traceMain = mock(TraceMain.class);

        anyTrace.message(name);

        verify(traceMain).addMessage(name);
    }

    @Test
    public void startService_shouldCallTraceMainStartService() {
        String name = "test service";

        anyTrace.startService(name);

        verify(TraceMain.class).startService(name, null, null, null, null, null, XLogTypes.APP_SERVICE);
    }

    @Test
    public void setServiceName_shouldCallTraceMainSetSpringControllerName() {
        String name = "test service name";

        anyTrace.setServiceName(name);

        verify(TraceMain.class).setSpringControllerName(name);
    }

    @Test
    public void serviceError_shouldCallDataProxySendErrorWhenTraceContextIsNotNullAndErrorIsNotZero() {
        String emsg = "Test error message";
        when(TraceContextManager.getContext()).thenReturn(traceContext);
        when(traceContext.getError()).thenReturn(1);

        anyTrace.serviceError(emsg);

        verify(DataProxy.class).sendError(emsg);
    }

    @Test
    public void endService_shouldCallTraceMainEndService() {
        Object stat = mock(Object.class);
        Throwable thr = mock(Throwable.class);

        anyTrace.endService(stat, thr);

        verify(TraceMain.class).endService(stat, null, thr);
    }

    @Test
    public void startMethod_shouldCallTraceMainStartMethod() {
        int hash = 123;
        String classMethodName = "testMethod";

        anyTrace.startMethod(hash, classMethodName);

        verify(TraceMain.class).startMethod(hash, classMethodName);
    }

    @Test
    public void endMethod_shouldCallTraceMainEndMethod() {
        Object stat = mock(Object.class);
        Throwable thr = mock(Throwable.class);

        anyTrace.endMethod(stat, thr);

        verify(TraceMain.class).endMethod(stat, thr);
    }

    @Test
    public void createTxid_shouldCallKeyGenNext() {
        anyTrace.createTxid();

        verify(KeyGen.class).next();
    }

    @Test
    public void startApicall_shouldCallTraceApiCallStartApicall() {
        String name = "test apicall";
        long apiTxid = 123;

        anyTrace.startApicall(name, apiTxid);

        verify(TraceApiCall.class).startApicall(name, apiTxid);
    }

    @Test
    public void setApicallName_shouldUpdateApicallNameWhenTraceContextIsNotNull() {
        String name = "test apicall name";
        when(TraceContextManager.getContext()).thenReturn(traceContext);
        when(traceContext.getApicall_name()).thenReturn("existing name");

        anyTrace.setApicallName(name);

        verify(traceContext).setApicall_name(name);
    }

    @Test
    public void endApicall_shouldCallTraceApiCallEndApicall() {
        Object stat = mock(Object.class);
        Throwable thr = mock(Throwable.class);

        anyTrace.endApicall(stat, thr);

        verify(TraceApiCall.class).endApicall(stat, null, thr);
    }

    @Test
    public void desc_shouldUpdateDescWhenTraceContextIsNotNull() {
        String desc = "test desc";
        when(TraceContextManager.getContext()).thenReturn(traceContext);

        anyTrace.desc(desc);

        verify(traceContext).setDesc(desc);
    }

    @Test
    public void login_shouldUpdateLoginWhenTraceContextIsNotNull() {
        String login = "test login";
        when(TraceContextManager.getContext()).thenReturn(traceContext);

        anyTrace.login(login);

        verify(traceContext).setLogin(login);
    }
}
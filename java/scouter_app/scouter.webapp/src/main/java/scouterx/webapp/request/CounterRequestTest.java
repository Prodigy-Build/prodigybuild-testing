The new code with unit tests is:

```
//Unit tests are written using JUnit 5 and Mockito

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import scouterx.webapp.framework.client.server.Server;
import scouterx.webapp.framework.client.server.ServerManager;
import scouterx.webapp.framework.exception.ErrorState;
import scouterx.webapp.request.CounterRequest;

class CounterRequestTest {

    @Mock
    ServerManager serverManager;

    @BeforeEach
    void setup() {
        MockitoAnnotations.openMocks(this);
    }

    @Test
    void validate_withStartEndTimes_shouldNotThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setStartTimeMillis(System.currentTimeMillis() - 1000);
        counterRequest.setEndTimeMillis(System.currentTimeMillis());

        Assertions.assertDoesNotThrow(() -> counterRequest.validate());
    }

    @Test
    void validate_withStartEndTimesLessThanZero_shouldThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setStartTimeMillis(-1000);
        counterRequest.setEndTimeMillis(-500);

        Assertions.assertThrows(ErrorState.BizException.class, () -> counterRequest.validate());
    }

    @Test
    void validate_withStartEndTimesGreaterThanLimit_shouldThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        long startTimeMillis = System.currentTimeMillis() - (counterRequest.getLimitRangeSec() + 1) * 1000;
        long endTimeMillis = System.currentTimeMillis();
        counterRequest.setStartTimeMillis(startTimeMillis);
        counterRequest.setEndTimeMillis(endTimeMillis);

        Assertions.assertThrows(ErrorState.BizException.class, () -> counterRequest.validate());
    }

    @Test
    void validate_withStartTimeMillisAndEndTimeMillis_shouldNotThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        long startTimeMillis = System.currentTimeMillis() - 1000;
        long endTimeMillis = System.currentTimeMillis();
        counterRequest.setStartTimeMillis(startTimeMillis);
        counterRequest.setEndTimeMillis(endTimeMillis);

        Assertions.assertDoesNotThrow(() -> counterRequest.validate());
    }

    @Test
    void validate_withStartTimeMillisAndEndTimeMillisLessThanZero_shouldThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setStartTimeMillis(-1000);
        counterRequest.setEndTimeMillis(-500);

        Assertions.assertThrows(ErrorState.BizException.class, () -> counterRequest.validate());
    }

    @Test
    void validate_withStartYmdHmsAndEndYmdHms_shouldNotThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setStartYmdHms("20211231235959");
        counterRequest.setEndYmdHms("20220101000000");

        Assertions.assertDoesNotThrow(() -> counterRequest.validate());
    }

    @Test
    void validate_withStartYmdHmsOnly_shouldThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setStartYmdHms("20211231235959");

        Assertions.assertThrows(ErrorState.BizException.class, () -> counterRequest.validate());
    }

    @Test
    void validate_withEndYmdHmsOnly_shouldThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setEndYmdHms("20220101000000");

        Assertions.assertThrows(ErrorState.BizException.class, () -> counterRequest.validate());
    }

    @Test
    void validate_withStartYmdHmsAndStartTimeMillis_shouldThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setStartYmdHms("20211231235959");
        counterRequest.setStartTimeMillis(System.currentTimeMillis());

        Assertions.assertThrows(ErrorState.BizException.class, () -> counterRequest.validate());
    }

    @Test
    void validate_withEndYmdHmsAndEndTimeMillis_shouldThrowException() {
        CounterRequest counterRequest = new CounterRequest();
        counterRequest.setEndYmdHms("20220101000000");
        counterRequest.setEndTimeMillis(System.currentTimeMillis());

        Assertions.assertThrows(ErrorState.BizException.class, () -> counterRequest.validate());
    }

    @Test
    void setServerId_withValidServerId_shouldSetServerId() {
        CounterRequest counterRequest = new CounterRequest();
        int serverId = 1;

        Server server = new Server();
        server.setId(serverId);

        Mockito.when(serverManager.getServerIfNullDefault(serverId)).thenReturn(server);

        counterRequest.setServerManager(serverManager);
        counterRequest.setServerId(serverId);

        Assertions.assertEquals(serverId, counterRequest.getServerId());
    }
}
```
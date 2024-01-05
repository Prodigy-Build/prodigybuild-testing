package scouterx.webapp.request;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class CounterRequestTest {

    @Test
    public void testValidate() {
        CounterRequest request = new CounterRequest();
        request.setStartYmdHms("20220101000000");
        request.setEndYmdHms("20220102000000");
        request.validate();
        Assertions.assertEquals(1640995200000L, request.getStartTimeMillis());
        Assertions.assertEquals(1641081600000L, request.getEndTimeMillis());
    }
}
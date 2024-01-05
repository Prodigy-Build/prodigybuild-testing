import org.junit.Assert;
import org.junit.Test;

public class CommonResultViewTest {

    @Test
    public void testSuccess() {
        CommonResultView<Boolean> result = CommonResultView.success();
        Assert.assertEquals(0, result.getResultCode());
        Assert.assertEquals("success", result.getMessage());
        Assert.assertTrue(result.getResult());
    }

    @Test
    public void testSuccessWithResult() {
        String expectedResult = "result";
        CommonResultView<String> result = CommonResultView.success(expectedResult);
        Assert.assertEquals(0, result.getResultCode());
        Assert.assertEquals("success", result.getMessage());
        Assert.assertEquals(expectedResult, result.getResult());
    }

    @Test
    public void testFail() {
        int expectedResultCode = 500;
        String expectedMessage = "error";
        CommonResultView<String> result = CommonResultView.fail(expectedResultCode, expectedMessage, null);
        Assert.assertEquals(expectedResultCode, result.getResultCode());
        Assert.assertEquals(expectedMessage, result.getMessage());
        Assert.assertNull(result.getResult());
    }

    @Test
    public void testFailWithStatus() {
        int expectedStatus = 400;
        int expectedResultCode = 500;
        String expectedMessage = "error";
        CommonResultView<String> result = CommonResultView.fail(expectedStatus, expectedResultCode, expectedMessage, null);
        Assert.assertEquals(expectedStatus, result.getStatus());
        Assert.assertEquals(expectedResultCode, result.getResultCode());
        Assert.assertEquals(expectedMessage, result.getMessage());
        Assert.assertNull(result.getResult());
    }

    // Add more unit tests for other methods if needed
}
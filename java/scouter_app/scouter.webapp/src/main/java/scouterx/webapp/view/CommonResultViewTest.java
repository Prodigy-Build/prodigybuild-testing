package scouterx.webapp.view;

import com.fasterxml.jackson.core.JsonGenerator;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;
import org.slf4j.MDC;
import scouterx.webapp.framework.filter.LoggingInitServletFilter;

import javax.xml.bind.annotation.XmlRootElement;
import java.io.IOException;
import java.io.OutputStream;
import java.util.function.Consumer;

import static org.junit.jupiter.api.Assertions.assertEquals;

@XmlRootElement
@Getter
@Setter
public class CommonResultView<T> {
    private static final int SUCCESS = 0;
    private static final ObjectMapper objectMapper = new ObjectMapper().configure(JsonGenerator.Feature.WRITE_NUMBERS_AS_STRINGS, true);

    private int status = HttpStatus.OK_200;
    private String requestId;
    private int resultCode;
    private String message;
    private T result;

    public CommonResultView() {}

    public CommonResultView(int resultCode, String message, T result) {
        this.resultCode = resultCode;
        this.message = message;
        this.result = result;
        this.requestId = MDC.get(LoggingInitServletFilter.requestId);
    }

    public CommonResultView(int status, int resultCode, String message, T result) {
        this.status = status;
        this.resultCode = resultCode;
        this.message = message;
        this.result = result;
        this.requestId = MDC.get(LoggingInitServletFilter.requestId);
    }

    public static CommonResultView<Boolean> success() {
        return new CommonResultView<>(SUCCESS, "success", true);
    }

    public static <T> CommonResultView<T> success(T result) {
        return new CommonResultView<>(SUCCESS, "success", result);
    }

    public static <T> CommonResultView fail(int resultCode, String message, T result) {
        return new CommonResultView<>(HttpStatus.INTERNAL_SERVER_ERROR_500, resultCode, message, result);
    }

    public static <T> CommonResultView fail(int status, int resultCode, String message, T result) {
        return new CommonResultView<>(status, resultCode, message, result);
    }

    public static void jsonArrayStream(OutputStream os, Consumer<JsonGenerator> itemGenerator) throws IOException {
        JsonGenerator jg = objectMapper.getFactory().createGenerator(os);

        jg.writeStartObject();

        {
            jg.writeNumberField("status", HttpStatus.OK_200);
            jg.writeNumberField("resultCode", SUCCESS);
            jg.writeStringField("message", "");

            jg.writeArrayFieldStart("result");

            {
                itemGenerator.accept(jg);
            }

            jg.writeEndArray();
        }

        jg.writeEndObject();
        jg.flush();
        jg.close();
    }

    public static void jsonStream(OutputStream os, Consumer<JsonGenerator> jsonItemGenerator) throws IOException {
        JsonGenerator jg = objectMapper.getFactory().createGenerator(os);

        jg.writeStartObject();

        {
            jg.writeNumberField("status", HttpStatus.OK_200);
            jg.writeNumberField("resultCode", SUCCESS);
            jg.writeStringField("message", "");

            jg.writeObjectFieldStart("result");

            {
                jsonItemGenerator.accept(jg);
            }

            jg.writeEndObject();
        }

        jg.writeEndObject();
        jg.flush();
        jg.close();
    }
}

public class CommonResultViewTest {

    @Test
    public void success_ReturnsCommonResultViewWithStatus0AndTrue() {
        CommonResultView<Boolean> result = CommonResultView.success();
        assertEquals(0, result.getStatus());
        assertEquals(true, result.getResult());
    }

    @Test
    public void success_ReturnsCommonResultViewWithStatus0AndResult() {
        String expectedResult = "Test Result";
        CommonResultView<String> result = CommonResultView.success(expectedResult);
        assertEquals(0, result.getStatus());
        assertEquals(expectedResult, result.getResult());
    }

    @Test
    public void fail_ReturnsCommonResultViewWithInternalServerErrorAndResult() {
        int expectedStatus = 500;
        int expectedCode = 100;
        String expectedMessage = "Test Error";
        String expectedResult = "Test Result";
        CommonResultView<String> result = CommonResultView.fail(expectedCode, expectedMessage, expectedResult);
        assertEquals(expectedStatus, result.getStatus());
        assertEquals(expectedCode, result.getResultCode());
        assertEquals(expectedMessage, result.getMessage());
        assertEquals(expectedResult, result.getResult());
    }

    @Test
    public void fail_ReturnsCommonResultViewWithCustomStatusAndResult() {
        int expectedStatus = 400;
        int expectedCode = 100;
        String expectedMessage = "Test Error";
        String expectedResult = "Test Result";
        CommonResultView<String> result = CommonResultView.fail(expectedStatus, expectedCode, expectedMessage, expectedResult);
        assertEquals(expectedStatus, result.getStatus());
        assertEquals(expectedCode, result.getResultCode());
        assertEquals(expectedMessage, result.getMessage());
        assertEquals(expectedResult, result.getResult());
    }

    @Test
    public void jsonArrayStream_WritesJsonArrayWithGivenItemGenerator() throws IOException {
        OutputStream mockOutputStream = Mockito.mock(OutputStream.class);
        JsonGenerator mockJsonGenerator = Mockito.mock(JsonGenerator.class);
        
        Mockito.when(objectMapper.getFactory().createGenerator(mockOutputStream)).thenReturn(mockJsonGenerator);
        
        Consumer<JsonGenerator> itemGenerator = gen -> {};
        
        CommonResultView.jsonArrayStream(mockOutputStream, itemGenerator);
        
        Mockito.verify(mockJsonGenerator).writeStartObject();
        Mockito.verify(mockJsonGenerator).writeNumberField("status", HttpStatus.OK_200);
        Mockito.verify(mockJsonGenerator).writeNumberField("resultCode", 0);
        Mockito.verify(mockJsonGenerator).writeStringField("message", "");
        Mockito.verify(mockJsonGenerator).writeArrayFieldStart("result");
        Mockito.verify(mockJsonGenerator).writeEndArray();
        Mockito.verify(mockJsonGenerator).writeEndObject();
        Mockito.verify(mockJsonGenerator).flush();
        Mockito.verify(mockJsonGenerator).close();
    }

    @Test
    public void jsonStream_WritesJsonObjectWithGivenItemGenerator() throws IOException {
        OutputStream mockOutputStream = Mockito.mock(OutputStream.class);
        JsonGenerator mockJsonGenerator = Mockito.mock(JsonGenerator.class);
        
        Mockito.when(objectMapper.getFactory().createGenerator(mockOutputStream)).thenReturn(mockJsonGenerator);
        
        Consumer<JsonGenerator> jsonItemGenerator = gen -> {};
        
        CommonResultView.jsonStream(mockOutputStream, jsonItemGenerator);
        
        Mockito.verify(mockJsonGenerator).writeStartObject();
        Mockito.verify(mockJsonGenerator).writeNumberField("status", HttpStatus.OK_200);
        Mockito.verify(mockJsonGenerator).writeNumberField("resultCode", 0);
        Mockito.verify(mockJsonGenerator).writeStringField("message", "");
        Mockito.verify(mockJsonGenerator).writeObjectFieldStart("result");
        Mockito.verify(mockJsonGenerator).writeEndObject();
        Mockito.verify(mockJsonGenerator).writeEndObject();
        Mockito.verify(mockJsonGenerator).flush();
        Mockito.verify(mockJsonGenerator).close();
    }
}
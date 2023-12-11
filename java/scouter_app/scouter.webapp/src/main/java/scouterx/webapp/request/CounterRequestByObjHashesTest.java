package scouterx.webapp.request;

import org.junit.Test;

import javax.validation.ConstraintViolation;
import javax.validation.Validation;
import javax.validation.Validator;
import javax.validation.ValidatorFactory;
import javax.ws.rs.QueryParam;
import java.util.Set;

import static org.junit.Assert.assertEquals;

public class CounterRequestByObjHashesTest {

    private Validator validator;

    public CounterRequestByObjHashesTest() {
        ValidatorFactory factory = Validation.buildDefaultValidatorFactory();
        validator = factory.getValidator();
    }

    @Test
    public void testSetObjHashesValid() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        Set<Integer> objHashes = Set.of(1, 2, 3);
        request.setObjHashes(objHashes);

        assertEquals(objHashes, request.getObjHashes());
    }

    @Test
    public void testSetObjHashesQueryParam() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        String objHashes = "1,2,3";
        request.setObjHashes(objHashes);

        Set<Integer> expectedObjHashes = Set.of(1, 2, 3);
        assertEquals(expectedObjHashes, request.getObjHashes());
    }

    @Test(expected = NullPointerException.class)
    public void testSetObjHashesNull() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        request.setObjHashes((String) null);
    }

    @Test
    public void testSetObjHashesNullPointerException() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        String objHashes = null;
        request.setObjHashes(objHashes);

        Set<ConstraintViolation<CounterRequestByObjHashes>> violations = validator.validate(request);
        assertEquals(1, violations.size());
        assertEquals("must not be null", violations.iterator().next().getMessage());
    }
}
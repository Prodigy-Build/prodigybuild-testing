package scouterx.webapp.request;

import org.junit.Before;
import org.junit.Test;

import javax.validation.ConstraintViolation;
import javax.validation.Validation;
import javax.validation.Validator;
import javax.validation.ValidatorFactory;
import javax.ws.rs.QueryParam;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static org.junit.Assert.assertEquals;

public class CounterRequestByObjHashesTest {

    private Validator validator;

    @Before
    public void setUp() {
        ValidatorFactory factory = Validation.buildDefaultValidatorFactory();
        validator = factory.getValidator();
    }

    @Test
    public void testSetObjHashes() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        Set<Integer> objHashes = new HashSet<>();
        objHashes.add(1);
        objHashes.add(2);
        objHashes.add(3);

        request.setObjHashes(objHashes);

        assertEquals(objHashes, request.getObjHashes());
    }

    @Test
    public void testSetObjHashesString() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        String objHashes = "1,2,3";

        request.setObjHashes(objHashes);

        Set<Integer> expectedObjHashes = new HashSet<>();
        expectedObjHashes.add(1);
        expectedObjHashes.add(2);
        expectedObjHashes.add(3);

        assertEquals(expectedObjHashes, request.getObjHashes());
    }

    @Test
    public void testSetObjHashesStringWithSpaces() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        String objHashes = "1, 2, 3";

        request.setObjHashes(objHashes);

        Set<Integer> expectedObjHashes = new HashSet<>();
        expectedObjHashes.add(1);
        expectedObjHashes.add(2);
        expectedObjHashes.add(3);

        assertEquals(expectedObjHashes, request.getObjHashes());
    }

    @Test
    public void testSetObjHashesStringWithDuplicateValues() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        String objHashes = "1,2,1,3,2";

        request.setObjHashes(objHashes);

        Set<Integer> expectedObjHashes = new HashSet<>();
        expectedObjHashes.add(1);
        expectedObjHashes.add(2);
        expectedObjHashes.add(3);

        assertEquals(expectedObjHashes, request.getObjHashes());
    }

    @Test
    public void testSetObjHashesStringWithInvalidValues() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        String objHashes = "1,2,3,invalid";

        request.setObjHashes(objHashes);

        Set<Integer> expectedObjHashes = new HashSet<>();
        expectedObjHashes.add(1);
        expectedObjHashes.add(2);
        expectedObjHashes.add(3);

        assertEquals(expectedObjHashes, request.getObjHashes());
    }

    @Test
    public void testObjHashesNotNull() {
        CounterRequestByObjHashes request = new CounterRequestByObjHashes();
        request.setObjHashes((Set<Integer>) null);

        Set<ConstraintViolation<CounterRequestByObjHashes>> violations = validator.validate(request);
        assertEquals(1, violations.size());
    }
}
```java
import org.junit.jupiter.api.Test;

import javax.validation.ConstraintViolation;
import javax.validation.Validation;
import javax.validation.Validator;
import javax.validation.ValidatorFactory;
import javax.validation.constraints.NotNull;

import static org.junit.jupiter.api.Assertions.*;

public class CounterAvgRequestByTypeTest {

    private final Validator validator;

    public CounterAvgRequestByTypeTest() {
        ValidatorFactory factory = Validation.buildDefaultValidatorFactory();
        validator = factory.getValidator();
    }

    @Test
    public void testObjTypeNotNull() {
        CounterAvgRequestByType request = new CounterAvgRequestByType();
        request.setObjType(null);

        Set<ConstraintViolation<CounterAvgRequestByType>> violations = validator.validate(request);
        assertFalse(violations.isEmpty());
    }

    @Test
    public void testObjTypeNotNull() {
        CounterAvgRequestByType request = new CounterAvgRequestByType();
        request.setObjType("example");

        Set<ConstraintViolation<CounterAvgRequestByType>> violations = validator.validate(request);
        assertTrue(violations.isEmpty());
    }
}
```
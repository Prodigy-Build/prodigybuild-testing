package reactor.core.publisher;

import org.junit.jupiter.api.Test;
import scouter.agent.util.Tuple;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class ScouterOptimizableOperatorProxyTest {

    @Test
    public void test_nameOnCheckpoint_withOptimizableOperator() {
        // Arrange
        OptimizableOperator<?, ?> operator = new MonoOnAssembly<>(new FluxOnAssembly<>());
        int maxScanDepth = 5;

        // Act
        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(operator, maxScanDepth);

        // Assert
        assertEquals(ScouterOptimizableOperatorProxy.EMPTYOBJ, result);
    }

    @Test
    public void test_nameOnCheckpoint_withNonOptimizableOperator() {
        // Arrange
        Object operator = new Object();
        int maxScanDepth = 5;

        // Act
        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(operator, maxScanDepth);

        // Assert
        assertEquals(ScouterOptimizableOperatorProxy.EMPTYOBJ, result);
    }

    @Test
    public void test_findCloseAssembly_withOptimizableOperator() {
        // Arrange
        OptimizableOperator<?, ?> operator = new MonoOnAssembly<>(new FluxOnAssembly<>());
        int maxScanDepth = 5;

        // Act
        OptimizableOperator<?, ?> result = ScouterOptimizableOperatorProxy.findCloseAssembly(operator, maxScanDepth);

        // Assert
        assertEquals(operator, result);
    }

    @Test
    public void test_findCloseAssembly_withNonOptimizableOperator() {
        // Arrange
        Object operator = new Object();
        int maxScanDepth = 5;

        // Act
        OptimizableOperator<?, ?> result = ScouterOptimizableOperatorProxy.findCloseAssembly(operator, maxScanDepth);

        // Assert
        assertEquals(null, result);
    }

    @Test
    public void test_appendSources4Dump_withOptimizableOperator() {
        // Arrange
        StringBuilder builder = new StringBuilder();
        OptimizableOperator<?, ?> operator = new MonoOnAssembly<>(new FluxOnAssembly<>());
        int maxScanDepth = 5;

        // Act
        ScouterOptimizableOperatorProxy.appendSources4Dump(operator, builder, maxScanDepth);

        // Assert
        assertEquals("", builder.toString());
    }

    @Test
    public void test_appendSources4Dump_withNonOptimizableOperator() {
        // Arrange
        StringBuilder builder = new StringBuilder();
        Object operator = new Object();
        int maxScanDepth = 5;

        // Act
        ScouterOptimizableOperatorProxy.appendSources4Dump(operator, builder, maxScanDepth);

        // Assert
        assertEquals("", builder.toString());
    }
}
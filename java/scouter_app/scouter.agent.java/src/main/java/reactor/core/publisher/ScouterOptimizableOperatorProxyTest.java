@RunWith(MockitoJUnitRunner.class)
public class ScouterOptimizableOperatorProxyTest {

    @Mock
    private OptimizableOperator<?, ?> operator;

    @Mock
    private MonoOnAssembly monoOnAssembly;

    @Mock
    private FluxOnAssembly fluxOnAssembly;

    @Before
    public void setup() {
        MockitoAnnotations.initMocks(this);
    }

    @Test
    public void testFindCloseAssembly_shouldReturnNull_whenMaxScanDepthExceeded() {
        int maxScanDepth = 5;
        when(operator.nextOptimizableSource()).thenReturn(operator);

        OptimizableOperator<?, ?> result = ScouterOptimizableOperatorProxy.findCloseAssembly(operator, maxScanDepth);

        assertNull(result);
    }

    @Test
    public void testFindCloseAssembly_shouldReturnNull_whenNoCloseAssemblyFound() {
        int maxScanDepth = 3;
        when(operator.nextOptimizableSource()).thenReturn(null);

        OptimizableOperator<?, ?> result = ScouterOptimizableOperatorProxy.findCloseAssembly(operator, maxScanDepth);

        assertNull(result);
    }

    @Test
    public void testFindCloseAssembly_shouldReturnMonoOnAssembly_whenMonoOnAssemblyFound() {
        int maxScanDepth = 3;
        when(operator.nextOptimizableSource()).thenReturn(monoOnAssembly);

        OptimizableOperator<?, ?> result = ScouterOptimizableOperatorProxy.findCloseAssembly(operator, maxScanDepth);

        assertEquals(monoOnAssembly, result);
    }

    @Test
    public void testFindCloseAssembly_shouldReturnFluxOnAssembly_whenFluxOnAssemblyFound() {
        int maxScanDepth = 3;
        when(operator.nextOptimizableSource()).thenReturn(fluxOnAssembly);

        OptimizableOperator<?, ?> result = ScouterOptimizableOperatorProxy.findCloseAssembly(operator, maxScanDepth);

        assertEquals(fluxOnAssembly, result);
    }

    @Test
    public void testNameOnCheckpoint_shouldReturnEmptyTupleStringLongPair_whenOptimizableOperatorNotAccessibleAndFirst() {
        Object candidate = new Object();
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = false;
        ScouterOptimizableOperatorProxy.first = true;

        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(candidate, maxScanDepth);

        assertEquals(ScouterOptimizableOperatorProxy.EMPTYOBJ, result);
    }

    @Test
    public void testNameOnCheckpoint_shouldReturnEmptyTupleStringLongPair_whenOptimizableOperatorNotAccessible() {
        Object candidate = new Object();
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = false;
        ScouterOptimizableOperatorProxy.first = false;

        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(candidate, maxScanDepth);

        assertEquals(ScouterOptimizableOperatorProxy.EMPTYOBJ, result);
    }

    @Test
    public void testNameOnCheckpoint_shouldReturnEmptyTupleStringLongPair_whenCandidateNotInstanceOfOptimizableOperator() {
        Object candidate = new Object();
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;

        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(candidate, maxScanDepth);

        assertEquals(ScouterOptimizableOperatorProxy.EMPTYOBJ, result);
    }

    @Test
    public void testNameOnCheckpoint_shouldReturnEmptyTupleStringLongPair_whenCloseAssemblyIsNull() {
        when(operator.nextOptimizableSource()).thenReturn(null);
        Object candidate = operator;
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;

        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(candidate, maxScanDepth);

        assertEquals(ScouterOptimizableOperatorProxy.EMPTYOBJ, result);
    }

    @Test
    public void testNameOnCheckpoint_shouldReturnTupleStringLongPair_whenCloseAssemblyIsMonoOnAssembly() {
        when(operator.nextOptimizableSource()).thenReturn(monoOnAssembly);
        when(monoOnAssembly.stacktrace).thenReturn(fluxOnAssembly);
        when(fluxOnAssembly.checkpointed).thenReturn(true);
        when(fluxOnAssembly.cached).thenReturn("cached");
        when(fluxOnAssembly.hashCode()).thenReturn(123);
        Object candidate = operator;
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;

        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(candidate, maxScanDepth);

        Tuple.StringLongPair expected = new Tuple.StringLongPair("cached", 123);
        assertEquals(expected, result);
    }

    @Test
    public void testNameOnCheckpoint_shouldReturnTupleStringLongPair_whenCloseAssemblyIsFluxOnAssembly() {
        when(operator.nextOptimizableSource()).thenReturn(fluxOnAssembly);
        when(fluxOnAssembly.snapshotStack).thenReturn(monoOnAssembly);
        when(monoOnAssembly.checkpointed).thenReturn(true);
        when(monoOnAssembly.cached).thenReturn("cached");
        when(monoOnAssembly.hashCode()).thenReturn(123);
        Object candidate = operator;
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;

        Tuple.StringLongPair result = ScouterOptimizableOperatorProxy.nameOnCheckpoint(candidate, maxScanDepth);

        Tuple.StringLongPair expected = new Tuple.StringLongPair("cached", 123);
        assertEquals(expected, result);
    }

    @Test
    public void testAppendSources4Dump_shouldNotDoAnything_whenOptimizableOperatorNotAccessibleAndFirst() {
        StringBuilder builder = new StringBuilder();
        Object candidate = new Object();
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = false;
        ScouterOptimizableOperatorProxy.first = true;

        ScouterOptimizableOperatorProxy.appendSources4Dump(candidate, builder, maxScanDepth);

        assertEquals("", builder.toString());
    }

    @Test
    public void testAppendSources4Dump_shouldNotDoAnything_whenOptimizableOperatorNotAccessible() {
        StringBuilder builder = new StringBuilder();
        Object candidate = new Object();
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = false;
        ScouterOptimizableOperatorProxy.first = false;

        ScouterOptimizableOperatorProxy.appendSources4Dump(candidate, builder, maxScanDepth);

        assertEquals("", builder.toString());
    }

    @Test
    public void testAppendSources4Dump_shouldNotDoAnything_whenCandidateNotInstanceOfOptimizableOperator() {
        StringBuilder builder = new StringBuilder();
        Object candidate = new Object();
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;

        ScouterOptimizableOperatorProxy.appendSources4Dump(candidate, builder, maxScanDepth);

        assertEquals("", builder.toString());
    }

    @Test
    public void testAppendSources4Dump_shouldNotDoAnything_whenCloseAssemblyIsNull() {
        StringBuilder builder = new StringBuilder();
        Object candidate = operator;
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;
        when(operator.nextOptimizableSource()).thenReturn(null);

        ScouterOptimizableOperatorProxy.appendSources4Dump(candidate, builder, maxScanDepth);

        assertEquals("", builder.toString());
    }

    @Test
    public void testAppendSources4Dump_shouldAppendSources_whenCloseAssemblyIsMonoOnAssembly() {
        StringBuilder builder = new StringBuilder();
        Object candidate = operator;
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;
        when(operator.nextOptimizableSource()).thenReturn(monoOnAssembly);
        when(monoOnAssembly.toString()).thenReturn("checkpoint");
        when(monoOnAssembly.nextOptimizableSource()).thenReturn(null);

        ScouterOptimizableOperatorProxy.appendSources4Dump(candidate, builder, maxScanDepth);

        assertEquals(" (<-) checkpoint", builder.toString());
    }

    @Test
    public void testAppendSources4Dump_shouldAppendSources_whenCloseAssemblyIsFluxOnAssembly() {
        StringBuilder builder = new StringBuilder();
        Object candidate = operator;
        int maxScanDepth = 5;
        ScouterOptimizableOperatorProxy.accessible = true;
        ScouterOptimizableOperatorProxy.first = false;
        when(operator.nextOptimizableSource()).thenReturn(fluxOnAssembly);
        when(fluxOnAssembly.toString()).thenReturn("checkpoint");
        when(fluxOnAssembly.nextOptimizableSource()).thenReturn(operator);

        ScouterOptimizableOperatorProxy.appendSources4Dump(candidate, builder, maxScanDepth);

        assertEquals(" (<-) checkpoint (<-) ", builder.toString());
    }
}
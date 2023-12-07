package scouterx.webapp.request;

import org.junit.jupiter.api.Test;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import static org.junit.jupiter.api.Assertions.*;

public class DictionaryRequestTest {

    @Test
    public void testSetDictSets() {
        DictionaryRequest request = new DictionaryRequest();
        request.setDictSets("[service:10001,service:10002,obj:20001,sql:55555]");
        
        Map<String, Set<SDictionaryText>> expectedDictSets = new HashMap<>();
        Set<SDictionaryText> serviceSet = new HashSet<>();
        serviceSet.add(new SDictionaryText("service", 10001, null));
        serviceSet.add(new SDictionaryText("service", 10002, null));
        Set<SDictionaryText> objSet = new HashSet<>();
        objSet.add(new SDictionaryText("obj", 20001, null));
        Set<SDictionaryText> sqlSet = new HashSet<>();
        sqlSet.add(new SDictionaryText("sql", 55555, null));
        
        expectedDictSets.put("service", serviceSet);
        expectedDictSets.put("obj", objSet);
        expectedDictSets.put("sql", sqlSet);
        
        assertEquals(expectedDictSets, request.getDictSets());
    }

    @Test
    public void testSetServerId() {
        DictionaryRequest request = new DictionaryRequest();
        request.setServerId(12345);
        
        assertEquals(12345, request.getServerId());
    }
}
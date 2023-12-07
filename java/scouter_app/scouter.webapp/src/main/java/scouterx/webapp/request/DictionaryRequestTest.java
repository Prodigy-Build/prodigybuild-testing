// Unit tests for DictionaryRequest class

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.runners.MockitoJUnitRunner;
import scouterx.webapp.framework.client.server.ServerManager;
import scouterx.webapp.model.scouter.SDictionaryText;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

@RunWith(MockitoJUnitRunner.class)
public class DictionaryRequestTest {

    @Mock
    private ServerManager serverManager;

    @Test
    public void testSetDictSets() {
        // Given
        DictionaryRequest dictionaryRequest = new DictionaryRequest();
        // Create a mock dictKeys string
        String dictKeys = "[service:10001,service:10002,obj:20001,sql:55555]";

        // When
        dictionaryRequest.setDictSets(dictKeys);

        // Then
        Map<String, Set<SDictionaryText>> expectedDictSets = new HashMap<>();
        Set<SDictionaryText> serviceDictSet = new HashSet<>();
        serviceDictSet.add(new SDictionaryText("service", 10001, null));
        serviceDictSet.add(new SDictionaryText("service", 10002, null));
        Set<SDictionaryText> objDictSet = new HashSet<>();
        objDictSet.add(new SDictionaryText("obj", 20001, null));
        Set<SDictionaryText> sqlDictSet = new HashSet<>();
        sqlDictSet.add(new SDictionaryText("sql", 55555, null));
        expectedDictSets.put("service", serviceDictSet);
        expectedDictSets.put("obj", objDictSet);
        expectedDictSets.put("sql", sqlDictSet);

        Assert.assertEquals(expectedDictSets, dictionaryRequest.getDictSets());
    }

    @Test
    public void testSetServerId() {
        // Given
        DictionaryRequest dictionaryRequest = new DictionaryRequest();
        int serverId = 12345;

        // When
        dictionaryRequest.setServerId(serverId);

        // Then
        Assert.assertEquals(serverManager.getInstance().getServerIfNullDefault(serverId).getId(), dictionaryRequest.getServerId());
    }
}
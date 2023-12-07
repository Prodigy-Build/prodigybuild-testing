public class BearerTokenViewTest {
    
    @Test
    public void testGetterAndSetter() {
        boolean success = true;
        String bearerToken = "sampleToken";
        
        BearerTokenView bearerTokenView = new BearerTokenView(success, bearerToken);
        
        assertEquals(success, bearerTokenView.isSuccess());
        assertEquals(bearerToken, bearerTokenView.getBearerToken());
        
        boolean newSuccess = false;
        String newBearerToken = "newToken";
        
        bearerTokenView.setSuccess(newSuccess);
        bearerTokenView.setBearerToken(newBearerToken);
        
        assertEquals(newSuccess, bearerTokenView.isSuccess());
        assertEquals(newBearerToken, bearerTokenView.getBearerToken());
    }
    
}
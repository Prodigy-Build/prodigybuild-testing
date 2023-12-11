package scouterx.webapp.request;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import scouterx.webapp.framework.util.ZZ;

import javax.validation.constraints.NotNull;
import javax.ws.rs.QueryParam;
import java.util.Set;

@Getter
@Setter
@ToString
public class CounterRequestByObjHashes extends CounterRequest {
    @NotNull
    Set<Integer> objHashes;

    @QueryParam("objHashes")
    public void setObjHashes(String objHashes) {
        this.objHashes = ZZ.splitParamAsIntegerSet(objHashes);
    }

    public void setObjHashes(Set<Integer> objHashes) {
        this.objHashes = objHashes;
    }
}
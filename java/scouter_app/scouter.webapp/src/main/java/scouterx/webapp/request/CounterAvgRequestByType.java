/*
 *  Copyright 2015 the original author or authors.
 *  @https://github.com/scouter-project/scouter
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

package scouterx.webapp.request;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotNull;
import javax.ws.rs.PathParam;

@Getter
@Setter
@ToString
public class CounterAvgRequestByType extends CounterAvgRequest {
    @NotNull
    @PathParam("objType")
    private String objType;

    // Add unit tests for CounterAvgRequestByType
    public class CounterAvgRequestByTypeTests {
        
        // Test getObjType method
        @Test
        public void testGetObjType() {
            CounterAvgRequestByType request = new CounterAvgRequestByType();
            request.setObjType("testObjType");
            assertEquals("testObjType", request.getObjType());
        }
    }
}
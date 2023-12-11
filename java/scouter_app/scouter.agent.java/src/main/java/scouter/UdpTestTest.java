/**
 *  Copyright 2015 Scouter Project.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); 
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License. 
 *  
 *   @author skyworker
 */

package scouter;

import org.junit.Test;
import static org.junit.Assert.*;

import scouter.agent.netio.data.net.DataUdpAgent;

public class UdpTest {

    @Test
    public void testDataUdpAgentMain() {
        String[] args = {}; // Replace with test data
        DataUdpAgent.main(args);
        // Add assertions if needed
    }
}
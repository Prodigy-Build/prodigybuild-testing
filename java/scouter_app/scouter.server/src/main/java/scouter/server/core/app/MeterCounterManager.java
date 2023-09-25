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

package scouter.server.core.app;

import scouter.util.LinkedMap;

/**
 * TODO: Write unit tests
 *
 * This class manages the MeterCounter objects by creating or retrieving them based on a key.
 * A MeterCounter represents a counter for a specific object hash and counter name.
 * The MeterCounterManager uses a LinkedMap to store the MeterCounter objects.
 * Each key consists of an object hash (int) and a counter name (String).
 *
 * This class is a singleton class.
 * To get the instance of this class, use the getInstance() method.
 *
 * To get a MeterCounter object, use the getMeterCounter() method.
 * If the MeterCounter object does not exist, a new MeterCounter object is created and added to the map.
 */
public class MeterCounterManager {
    private static MeterCounterManager instance = new MeterCounterManager();

    private LinkedMap<Key, MeterCounter> meterCounterMap = new LinkedMap<Key, MeterCounter>().setMax(10000);

    public static class Key {
        public int objHash;
        public String counterName;

        public Key(int objHash, String counterName) {
            this.objHash = objHash;
            this.counterName = counterName;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Key) {
                Key k = (Key) obj;
                return this.objHash == ((Key) obj).objHash && this.counterName.equals(((Key) obj).counterName);
            }
            return false;
        }

        @Override
        public int hashCode() {
            return objHash ^ counterName.hashCode();
        }
    }

    public static MeterCounterManager getInstance() {
        return instance;
    }

    //without syncronize, but it's ok in the key scope.
    public MeterCounter getMeterCounter(int objHash, String counterName) {
        Key key = new Key(objHash, counterName);
        MeterCounter meterCounter = meterCounterMap.get(key);

        if (meterCounter == null) {
            meterCounter = new MeterCounter();
            meterCounterMap.put(key, meterCounter);
        }

        return meterCounter;
    }
}
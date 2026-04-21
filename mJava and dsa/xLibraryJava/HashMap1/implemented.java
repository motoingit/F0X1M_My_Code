package xLibraryJava.HashMap1;

public import java.util.ArrayList;
import java.util.LinkedList;

class HashMapCode {

    // Generic HashMap implementation (like templates in C++)
    static class HashMap<Key, Value> {

        // ── Inner node: holds one key-value pair ──────────────────────────────
        private class Node {
            Key key;
            Value value;

            public Node(Key key, Value value) {
                this.key   = key;
                this.value = value;
            }
        }

        private int nNodes;                    // total entries currently stored
        private int nBuckets;                  // current number of buckets
        private LinkedList<Node>[] buckets;    // array of chains (separate chaining)

        // ── Constructor ────────────────────────────────────────────────────────
        @SuppressWarnings("unchecked")
        public HashMap() {
            this.nBuckets = 4;
            this.nNodes   = 0;
            this.buckets  = new LinkedList[nBuckets];   // use field, not literal 4
            for (int i = 0; i < nBuckets; i++) {
                this.buckets[i] = new LinkedList<>();
            }
        }

        // ── Hash function ──────────────────────────────────────────────────────
        // hashCode() can return negative values or very large ints,
        // so Math.abs + modulo maps it into [0, nBuckets)
        private int hashFunction(Key key) {
            return Math.abs(key.hashCode()) % nBuckets;
        }

        // ── Search within a single bucket's linked list ────────────────────────
        // Returns the index inside the LinkedList, or -1 if not found.
        // FIX: use .equals() instead of == for correct key comparison
        private int searchInLL(Key key, int bucketIdx) {
            LinkedList<Node> ll = buckets[bucketIdx];
            for (int i = 0; i < ll.size(); i++) {
                if (ll.get(i).key.equals(key)) {
                    return i;
                }
            }
            return -1;
        }

        // ── Rehash ─────────────────────────────────────────────────────────────
        // Called when load factor (nNodes / nBuckets) exceeds 2.0.
        // Doubles bucket count and reinserts all existing nodes.
        // FIX: use a private helper putForRehash() that does NOT touch nNodes,
        //      because we're moving existing entries, not adding new ones.
        @SuppressWarnings("unchecked")
        private void rehash() {
            LinkedList<Node>[] oldBuckets = buckets;
            nBuckets *= 2;                                  // update field first
            buckets = new LinkedList[nBuckets];
            for (int i = 0; i < nBuckets; i++) {
                buckets[i] = new LinkedList<>();
            }

            // reinsert every node without changing nNodes
            for (LinkedList<Node> ll : oldBuckets) {
                for (Node node : ll) {
                    putForRehash(node.key, node.value);
                }
            }
        }

        // Internal put used only during rehash — skips nNodes bookkeeping
        private void putForRehash(Key key, Value value) {
            int bucketIdx = hashFunction(key);
            buckets[bucketIdx].add(new Node(key, value));
        }

        // ── put(key, value) ────────────────────────────────────────────────────
        // Insert a new entry or update an existing key's value.
        // FIX: nNodes++ moved inside the "not exists" branch only;
        //      the duplicate increment at the end is removed.
        public void put(Key key, Value value) {
            int bucketIdx = hashFunction(key);
            int dataIdx   = searchInLL(key, bucketIdx);

            if (dataIdx == -1) {
                // key does not exist → add a new node
                buckets[bucketIdx].add(new Node(key, value));
                nNodes++;                                   // increment exactly once
            } else {
                // key already exists → just update the value
                buckets[bucketIdx].get(dataIdx).value = value;
                // nNodes unchanged — no new entry was added
            }

            // rehash if load factor exceeds threshold
            double lambda = (double) nNodes / nBuckets;
            if (lambda > 2.0) {
                rehash();
            }
        }

        // ── get(key) ───────────────────────────────────────────────────────────
        // Returns the value for the key, or null if not found.
        public Value get(Key key) {
            int bucketIdx = hashFunction(key);
            int dataIdx   = searchInLL(key, bucketIdx);

            if (dataIdx == -1) {
                return null;
            }
            return buckets[bucketIdx].get(dataIdx).value;
        }

        // ── containsKey(key) ───────────────────────────────────────────────────
        // Returns true if the key exists, false otherwise.
        public boolean containsKey(Key key) {
            int bucketIdx = hashFunction(key);
            return searchInLL(key, bucketIdx) != -1;
        }

        // ── remove(key) ────────────────────────────────────────────────────────
        // Removes the entry for the key and returns its value, or null if absent.
        public Value remove(Key key) {
            int bucketIdx = hashFunction(key);
            int dataIdx   = searchInLL(key, bucketIdx);

            if (dataIdx == -1) {
                return null;                                // key not found, no-op
            }

            Node removed = buckets[bucketIdx].remove(dataIdx);
            nNodes--;
            return removed.value;
        }

        // ── keySet() ───────────────────────────────────────────────────────────
        // Returns a list of all keys across all buckets.
        public ArrayList<Key> keySet() {
            ArrayList<Key> keys = new ArrayList<>();
            for (LinkedList<Node> ll : buckets) {
                for (Node node : ll) {
                    keys.add(node.key);
                }
            }
            return keys;
        }

        // ── isEmpty() ─────────────────────────────────────────────────────────
        // FIX: was missing a return statement — would not compile.
        public boolean isEmpty() {
            return nNodes == 0;
        }

        // ── size() ────────────────────────────────────────────────────────────
        public int size() {
            return nNodes;
        }
    }

    // ── Driver ─────────────────────────────────────────────────────────────────
    public static void main(String[] args) {
        HashMap<String, Integer> map = new HashMap<>();

        map.put("US",     30);
        map.put("India",  140);
        map.put("Russia", 15);
        map.put("India",  145);  // update — should replace 140 with 145

        System.out.println("Size: " + map.size());               // 3
        System.out.println("Empty? " + map.isEmpty());           // false
        System.out.println("Contains Russia? " + map.containsKey("Russia")); // true

        System.out.println("\nAll entries:");
        ArrayList<String> keys = map.keySet();
        for (String key : keys) {
            System.out.println("  " + key + " → " + map.get(key));
        }

        map.remove("Russia");
        System.out.println("\nAfter removing Russia:");
        System.out.println("Contains Russia? " + map.containsKey("Russia")); // false
        System.out.println("Size: " + map.size());               // 2
    }
}

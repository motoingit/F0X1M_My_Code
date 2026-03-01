import java.util.ArrayList;
import java.util.Collections;

public class MaxHeap {

    //global dynamic array
    private ArrayList<Integer> heap = new ArrayList<>();

    // ---------- INSERT ----------
    public void insert(int val) {
        heap.add(val);
        int i = heap.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap.get(i) > heap.get(parent)) {
                Collections.swap(heap, i, parent);
                i = parent;
            } else {
                break;
            }
        }
    }

    // ---------- DELETE (remove max) ----------
    public Integer remove() {
        if (heap.isEmpty()) return null;

        Integer removed = heap.get(0);
        Integer last = heap.remove(heap.size() - 1);

        if (!heap.isEmpty()) {
            heap.set(0, last);
            heapifyDown(0);
        }

        return removed;
    }

    // ---------- HEAPIFY DOWN ----------
    private void heapifyDown(int i) {
        int size = heap.size();

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap.get(left) > heap.get(largest))
                largest = left;

            if (right < size && heap.get(right) > heap.get(largest))
                largest = right;

            if (largest == i)
                break;

            Collections.swap(heap, i, largest);
            i = largest;
        }
    }

    // ---------- PRINT ----------
    public void printHeap() {
        System.out.println(heap);
    }

    // ---------- MAIN ----------
    public static void main(String[] args) {
        MaxHeap h = new MaxHeap();

        h.insert(10);
        h.insert(40);
        h.insert(30);
        h.insert(60);
        h.insert(20);

        h.printHeap();           // [60, 40, 30, 10, 20]
        System.out.println(h.remove()); // 60
        h.printHeap();           // [40, 20, 30, 10]
    }
}

class SharedBox {
    private int value;
    private boolean hasValue = false;  // flag: is there an unconsumed value?

    // Producer calls this
    public synchronized void produce(int val) {
        while (hasValue) {          // box is full, WAIT
            try { wait(); } catch (Exception e) {}
        }
        this.value = val;
        hasValue = true;            // mark box as full
        System.out.println("Produced: " + val);
        notify();                   // wake up the Consumer
    }

    // Consumer calls this
    public synchronized void consume() {
        while (!hasValue) {         // box is empty, WAIT
            try { wait(); } catch (Exception e) {}
        }
        System.out.println("Consumed: " + value);
        hasValue = false;           // mark box as empty
        notify();                   // wake up the Producer
    }
}

class Producer implements Runnable {
    SharedBox box;

    Producer(SharedBox box) { this.box = box; }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            box.produce(i);
        }
    }
}

class Consumer implements Runnable {
    SharedBox box;

    Consumer(SharedBox box) { this.box = box; }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            box.consume();
        }
    }
}

public class j19 {
    public static void main(String[] args) {
        SharedBox box = new SharedBox();
        new Thread(new Producer(box)).start();
        new Thread(new Consumer(box)).start();
    }
}

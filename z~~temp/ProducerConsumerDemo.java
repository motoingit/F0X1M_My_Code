import java.util.*;

public class ProducerConsumerDemo {

    // Shared flag to signal completion
    static volatile boolean productionDone = false;

    public static void main(String[] args) {

        Queue<Integer> buffer = new LinkedList<>();
        int maxSize = 5;

        Producer producer = new Producer(buffer, maxSize);
        Consumer consumer = new Consumer(buffer, maxSize);

        producer.start();
        consumer.start();
    }
}


// 🔹 PRODUCER CLASS
class Producer extends Thread {

    private Queue<Integer> buffer;
    private int maxSize;

    public Producer(Queue<Integer> buffer, int maxSize) {
        this.buffer = buffer;
        this.maxSize = maxSize;
    }

    @Override
    public void run() {
        int value = 0;
        int maxItems = 20;

        while (value < maxItems) {
            synchronized (buffer) {

                while (buffer.size() == maxSize) {
                    try {
                        buffer.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

                System.out.println("Produced: " + value);
                buffer.add(value++);
                buffer.notifyAll();
            }

            try {
                Thread.sleep(500); // slow down producer
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Signal that production is done
        ProducerConsumerDemo.productionDone = true;

        synchronized (buffer) {
            buffer.notifyAll(); // wake up consumer if waiting
        }
    }
}


// 🔹 CONSUMER CLASS
class Consumer extends Thread {

    private Queue<Integer> buffer;
    private int maxSize;

    public Consumer(Queue<Integer> buffer, int maxSize) {
        this.buffer = buffer;
        this.maxSize = maxSize;
    }

    @Override
    public void run() {

        while (true) {
            synchronized (buffer) {

                while (buffer.isEmpty()) {
                    if (ProducerConsumerDemo.productionDone) {
                        return; // exit safely
                    }

                    try {
                        buffer.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

                int value = buffer.poll();
                System.out.println("Consumed: " + value);
                buffer.notifyAll();
            }

            try {
                Thread.sleep(800); // slow down consumer
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

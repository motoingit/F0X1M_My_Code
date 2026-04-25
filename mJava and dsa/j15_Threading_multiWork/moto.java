import java.util.concurrent.atomic.AtomicInteger;
/*
Today we have *covered Synchronisation and Inter Thread Commutation* , those who have missed today's class and lab kindly ask them to prepare these concepts before coming to the next class where we will be discussing *Producer and Consumer Problem*.
*/
public class moto {

    public static void main(String[] args) throws InterruptedException {

        System.out.println("----- WITHOUT SYNCHRONIZATION -----");
        testUnsafe();

        System.out.println("\n----- WITH SYNCHRONIZATION -----");
        testSynchronized();

        System.out.println("\n----- USING ATOMIC INTEGER -----");
        testAtomic();
    }

    // ❌ 1. Race Condition Demo
    static void testUnsafe() throws InterruptedException {
        UnsafeCounter obj = new UnsafeCounter();

        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 100000; i++) obj.increment();
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 100000; i++) obj.increment();
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final Count (Unsafe): " + obj.count);
    }

    // 🔐 2. Synchronized Version
    static void testSynchronized() throws InterruptedException {
        SafeCounter obj = new SafeCounter();

        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 100000; i++) obj.increment();
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 100000; i++) obj.increment();
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final Count (Synchronized): " + obj.count);
    }

    // ⚡ 3. Atomic Version
    static void testAtomic() throws InterruptedException {
        AtomicCounter obj = new AtomicCounter();

        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 100000; i++) obj.increment();
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 100000; i++) obj.increment();
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Final Count (Atomic): " + obj.count.get());
    }
}


// ❌ No synchronization → race condition
class UnsafeCounter {
    int count = 0;

    void increment() {
        count++; // NOT thread-safe
    }
}


// 🔐 Using synchronized → safe but slower
class SafeCounter {
    int count = 0;

    synchronized void increment() {
        count++; // thread-safe
    }
}


// ⚡ Atomic → best modern approach
class AtomicCounter {
    AtomicInteger count = new AtomicInteger(0);

    void increment() {
        count.incrementAndGet(); // thread-safe & efficient
    }
}

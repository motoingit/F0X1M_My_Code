// ============================================================
//  ThreadComparison.java
//  Demonstrates: Sequential execution  vs  Multithreaded execution
// ============================================================

class Task {
    private final String name;
    private final int durationMs;   // simulated work duration

    public Task(String name, int durationMs) {
        this.name = name;
        this.durationMs = durationMs;
    }

    /** Simulates some work by sleeping for 'durationMs' milliseconds */
    public void execute() {
        System.out.println("  [" + name + "] started  on thread: "
                + Thread.currentThread().getName());
        try {
            Thread.sleep(durationMs);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        System.out.println("  [" + name + "] finished on thread: "
                + Thread.currentThread().getName());
    }

    public String getName()    { return name; }
    public int getDuration()   { return durationMs; }
}

// ── Sequential Executor ──────────────────────────────────────
class ClassSeq {
    public void run(Task[] tasks) {
        System.out.println("\n===== SEQUENTIAL EXECUTION =====");
        long start = System.currentTimeMillis();

        for (Task task : tasks) {
            task.execute();            // one after another, same thread
        }

        long elapsed = System.currentTimeMillis() - start;
        System.out.println("  >> Sequential total time: " + elapsed + " ms");
    }
}

// ── Multithreaded Executor ───────────────────────────────────
class ClassMulti {
    public void run(Task[] tasks) throws InterruptedException {
        System.out.println("\n===== MULTITHREADED EXECUTION =====");
        long start = System.currentTimeMillis();

        Thread[] threads = new Thread[tasks.length];

        // Create one thread per task
        for (int i = 0; i < tasks.length; i++) {
            final Task task = tasks[i];
            threads[i] = new Thread(task::execute, "Thread-" + (i + 1));
        }

        // Start ALL threads simultaneously
        for (Thread t : threads) {
            t.start();
        }

        // Wait for every thread to finish
        for (Thread t : threads) {
            t.join();
        }

        long elapsed = System.currentTimeMillis() - start;
        System.out.println("  >> Multithreaded total time: " + elapsed + " ms");
    }
}

// ────────────── Main / Demo ────────────────────────────────
public class mohit {
    public static void main(String[] args) throws InterruptedException {

        // Define tasks with name and simulated work duration (milliseconds)
        Task[] tasks = {
            new Task("Task-A", 1000),   // 1 second
            new Task("Task-B", 1500),   // 1.5 seconds
            new Task("Task-C", 800),    // 0.8 seconds
            new Task("Task-D", 1200)    // 1.2 seconds
        };

        int totalTimes = 0;
        for (Task t : tasks) totalTimes += t.getDuration();

        System.out.println("╔══════════════════════════════════════════════╗");
        System.out.println("║   Sequential vs Multithreaded Execution Demo ║");
        System.out.println("╚══════════════════════════════════════════════╝");
        System.out.println("Tasks: " + tasks.length
                + "  |  Sum of durations: " + totalTimes + " ms");

        // ── Run Sequential ──
        ClassSeq seq = new ClassSeq();
        seq.run(tasks);

        // ── Run Multithreaded ──
        ClassMulti multi = new ClassMulti();
        multi.run(tasks);

        // ── Summary ─────────────────────────────────────────
        System.out.println("\n========== SUMMARY ==========");
        System.out.println("Sequential   : runs tasks ONE BY ONE on the main thread.");
        System.out.println("               Total time ≈ sum of all task durations.");
        System.out.println();
        System.out.println("Multithreaded: runs ALL tasks at the SAME TIME, each on");
        System.out.println("               its own thread.");
        System.out.println("               Total time ≈ duration of the LONGEST task.");
        System.out.println("==============================");
    }
}

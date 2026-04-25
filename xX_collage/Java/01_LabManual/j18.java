class MyThread extends Thread {
    int count = 0;

    MyThread(String name) {
        super(name); // set thread name
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            count++;
            System.out.println(getName() + " executing, count = " + count);

            try {
                Thread.sleep(500); // 500 ms gap
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class j18 {
    public static void main(String[] args) throws InterruptedException {

        MyThread csThread = new MyThread("CSThread");
        MyThread itThread = new MyThread("ITThread");

        csThread.start();
        itThread.start();

        // Wait for both to finish
        csThread.join();
        itThread.join();

        System.out.println("Both threads finished execution.");
    }
}

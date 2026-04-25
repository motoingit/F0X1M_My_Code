/* Ques:  TypeHere 

Create 2 threads:
	•	Thread A → prints even numbers (1–10)
	•	Thread B → prints odd numbers (1–10)
    
*/ 

class Task implements Runnable{
    static int count = 0;
    String id;

    Task(String id){
        count++;
        this.id = id;
        System.out.println(String.format("[%s] is Created , [%d] is total Count", id, count));
    }
    
    @Override
    public void run() {
        for (int i = 0; i < 5; i=+2) {
            System.out.println(String.format("[%s] is Running", this.id));
            try{
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        
        System.out.println(String.format("[%s] is Complete !", this.id));
    };
}

public class Main{
    public static void main(String[] args) {
        Task t1 = new Task("task-1");
        Task t2 = new Task("task-2");

        Thread task1 = new Thread(t1, "Worker-1");
        Thread task2 = new Thread(t2, "Worker-2");

        task1.start();
        task2.start();

        System.out.println(Thread.currentThread().getName());

    }
}

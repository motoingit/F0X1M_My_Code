/* Ques: Abstract Class */ 

abstract class Perimeter{
    abstract public void perimeterSquare(int s);
    abstract public void perimeterRectangle(int l, int b);
    abstract public void perimeterCircle(int r);
}

class CalculatePerimeter extends Perimeter{
    public void perimeterCircle(int r){
        System.out.println("Area of Circle : " + 10 * r * r);
    }
    public void perimeterRectangle(int l, int b){
        System.out.println("Area of Rectangle : " + l * b);
    }
    public void perimeterSquare(int r){
        System.out.println("Area of Square : " + r * r);
    }
}

public class Main{
    public static void main(String[] args) {
        CalculatePerimeter obj = new CalculatePerimeter();
        obj.perimeterCircle(10);
    }
}

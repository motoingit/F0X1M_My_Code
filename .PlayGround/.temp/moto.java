
class Phone{ //*  */
    public void executeVibration(){
        System.out.println("Ringing...");
    }
    public void executeCalling(){
        System.out.println("Calling...");
    }
}

abstract class Shape{
    protected Float area;
    protected Float perimeter;

    public Float getArea() {
        return area;
    }
    public Float getPerimeter() {
        return perimeter;
    }
    public void setArea(Float area) {
        this.area = area;
    }
    public void setPerimeter(Float perimeter) {
        this.perimeter = perimeter;
    }
}

class Circle extends Shape{
    private Float radius;

    Circle(Float radius){
        this.radius = radius;
    }

    @Override
    public void setArea(Float area) {
        super.setArea(area);
    }
}

class Square{
    private Float side;
    public Float getSide() {
        return side;
    }
    public void setSide(Float side) {
        this.side = side;
    }
    public float giveArea() {
        return side*side;
    }
    public float giveParameter() {
        return side*4;
    }
    public void getDetails(){
        System.out.println("Side : ");
        System.out.println("Side : ");
        System.out.println("Side : ");
    }
}

public class moto{
    public static void main(String[] args) {
        // Phone p1 = new Phone();
        // p1.executeVibration();
        // p1.executeCalling();

        // Square s1 = new Square();
        // s1.setSide(9f);
        // s1.getDetails();

        // 
    }
}

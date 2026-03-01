
abstract class BaseArea{
    public final float PI = 3.14f;

    public void areaSquare(float side){
        System.out.println("Area of Square (PARENT) : " + side*side);
    }
    public void areaCircle(float radius){
        System.out.println("Area of Circle (PARENT) : " + PI*radius);
    }
    public void areaTriangle(float height, float base ){
        System.out.println("Area of Triangle (PARENT) : " + 0.5*height*base);
    }
}

class ChildArea extends BaseArea{
    @Override
    public void areaSquare(float side){
        System.out.println("Area of Square (CHILD) : " + side*side);
    }
    @Override
    public void areaCircle(float radius){
        System.out.println("Area of Circle (CHILD) : " + PI * radius * radius);
    }
    @Override
    public void areaTriangle(float height, float base ){
        System.out.println("Area of Triangle (CHILD) : " + 0.5*height*base);
    }
}

public class j11_Overriding {
    public static void main(String[] args) {
        BaseArea obj = new ChildArea(); //! Resolved at runtime
        obj.areaCircle(10);
    }    
}

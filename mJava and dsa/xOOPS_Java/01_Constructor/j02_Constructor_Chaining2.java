//? After Inheritence Learning */

//* Base Class */
abstract class Shape{

    protected Float area;
    protected Float peri;

    Shape(){
        this.area = 0f;
        this.peri = 0f;
    }

    public void printDetails(){
        System.out.println("Area : " + area);
        System.out.println("Perimeter : " + peri);
    }

    public void setArea(Float area) {
        this.area = area;
    }

    public void setPeri(Float peri) {
        this.peri = peri;
    }

    abstract void calcArea();
    abstract void calcPeri();
}

//* Child */
class Traingle extends Shape{
    protected Float s1;
    protected Float s2;
    protected Float s3;

    Traingle(){
        super();
        this.s1 = 0f;
        this.s2 = 0f;
        this.s3 = 0f;
    }

    public void printDetails(){
        super.printDetails();
        System.out.println(String.format("Side1 %.2f, Side2 %.2f, Side3 %.2f !!!", s1, s2, s3));
    }

    public void setSide(Float s1, Float s2, Float s3) {
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
    }

    @Override
    public void calcArea() {
        float periTemp = this.peri / 2f;
        this.area = (float) Math.sqrt(periTemp * (periTemp - s1) * (periTemp - s2) * (periTemp - s3));
    }

    @Override
    public void calcPeri() {
        this.peri = (s1 + s2 + s3);
    }
}

//*Child-Child */
class Iso_Triangle extends Traingle {
    Iso_Triangle(){
        super();
    }

    @Override
    public void printDetails(){
        System.out.println("Area : " + area);
        System.out.println("Perimeter : " + peri);
        System.out.println(String.format("Side %.2f !!!", s1, s2, s3));
    }
}

//* Main */
public class j02_Constructor_Chaining2{
    public static void main(String[] args) {
        Iso_Triangle s1 = new Iso_Triangle();
        s1.setSide(5f, 5f, 5f);
        s1.calcPeri();
        s1.calcArea();
        s1.printDetails();
    }
}

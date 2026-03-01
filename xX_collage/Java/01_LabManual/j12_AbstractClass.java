
abstract class Temperature{
    public float temp;
    public void setTemp(float temp){
        this.temp = temp;
    }
    abstract public float changeTemp(float temp); //abstract method
}

class F_Temperature extends Temperature{
    @Override
    public float changeTemp(float temp) { //? lets assume it changes to the C --> F
        return (float)(9.0 / 5) * temp + 32;
    }
}

class C_Temperature extends Temperature{
    @Override
    public float changeTemp(float temp) {//? lets assume it changes to the F --> C
        return (float) (5.0 / 9) * (temp - 32);
    }
}

public class j12_AbstractClass{
    public static void main(String[] args) {
        F_Temperature fahranheitTemp = new F_Temperature();
        fahranheitTemp.setTemp(100);
        C_Temperature celsiusTemp = new C_Temperature();
        celsiusTemp.setTemp(200);

        System.out.println("Initially : Celsius=" + celsiusTemp.temp + " Faranite="+fahranheitTemp.temp);

        System.out.println("On Conversion: CelsiusTOfaranite=" + fahranheitTemp.changeTemp(celsiusTemp.temp) + " FaraniteTOcelsius="+celsiusTemp.changeTemp(fahranheitTemp.temp));
    }
}

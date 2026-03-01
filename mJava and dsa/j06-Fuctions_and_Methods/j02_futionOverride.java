
class Product{
    public void getProduct(){
        System.out.println("This is Product 1 !");
    }
    public void getProduct(int a){
        System.out.println("This is Product 2 !");
    }
    public void getProduct(float b){
        System.out.println("This is Product 3 !");
    }
}

public class j02_futionOverride{
    public static void main(String[] args) {
        Product obj = new Product();

        obj.getProduct();
        obj.getProduct(2);
        obj.getProduct(3.5f);
    }
}

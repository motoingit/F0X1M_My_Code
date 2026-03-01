/*
///* Question : 
  
///? Assumption : 
 - Product is Abstract class giving 5% of discount from the orinal Price
 - Electronics is the Derived class giving and 10% additional DIscount
 - Clothes is the Derived class giving and 5% additional DIscount
*/

abstract class Product{
    protected String productId;
    protected Float price;

    Product(String productId, Float price){
        this.productId = productId;
        this.price = price;
    }

    public float calculateDiscount(){
        float finalPrice = price;
        //
        finalPrice -= 10; //* discountLogic */
        //
        return finalPrice;
    }
}

class Electronics extends Product{
    Electronics(String productId, Float price){
        super(productId, price);
    }

    @Override
    public float calculateDiscount() {
        float finalPrice = price;
        //
        finalPrice -= 90;
        //
        return finalPrice;
    }
}
class Clothing extends Product{

    Clothing(String productId, Float price){
        super(productId, price);
    }

    @Override
    public float calculateDiscount() {
        float finalPrice = price;
        //
        finalPrice -= 30;
        //
        return finalPrice;
    }
}


public class j01{
    public static void main(String[] args) {
        Product objE1 = new Electronics("Hunter1", 990f);

        float user1_bill = objE1.calculateDiscount();
        System.out.println(user1_bill);
    }
}

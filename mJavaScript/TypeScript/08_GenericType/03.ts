function anotherFuction <T, U>(val1: T, val2: U): object {
    return{
        val1,
        val2
    }
}

anotherFuction(3,"3");


// CASsw 2

interface Database{
    connection: string,
    username: string,
    password: string,
}

function anotherFuction2 <T, U extends Database>(val1: T, val2: U): object {
    return{
        val1,
        val2
    }
}

anotherFuction(3,{});




//case3
//! sir siad that in this case the class will do some work for  ading products and some work for  the books so just basic works for th

interface Quiz{
    name: string,
    type: string,
}

interface Course{
    name: string,
    author: string,
    subject: string,
}

class Syllable<T>{
    public cart: T[] = []
    addToCart(product: T){
        this.cart.push(product);
    }
}


function sum(a,b){
    console.log(a+b);
}

function calculator(a, b, sumCallback){
    sumCallback(a,b);
}


function hello(){
    console.log("je;;p")
}
//! asycronnus 
setTimeout(hello,3000)




//* callback sycronus example
calculator(2,4,sum);
// calculator(2,4,sum()); //! esa ni karte mahashay
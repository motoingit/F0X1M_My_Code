
// this can be tricky
function getSearchProduct <T> (product: T[]): T { //todo: dont confuse here the return type is not array but one elemnt of array (number)n
    return product[3];
}


// 
const getMoreSearchProduct = <T>(product: T[]): T =>{
    //do some database calc
    return product[3];
}

// 
const getMoreSearchProduct = <T,>(product: T[]): T =>{ //todo: the comma is used by people to just pointout  that this is not the jsx but generic
    //do some database calc
    return product[3];
}

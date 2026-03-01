// we know typeof

//but now lets go for instance of //! this user for new created (DMA) var



function logValue (x: Date | String){
    if(x instanceof Date){
        console.log(x.toUTCString());
    } else {
        console.log(x.toUpperCase());
    }
}




//todo: Now lets see TYPE PRIDICATES

type Fish = {
    swim: ()=> void
}
type Bird = {
    fly: ()=> void
}


                                    //todo: SAMPLE 1

function isFish1(pet: Fish | Bird){
    return (pet as Fish).swim !== undefined ;
}
function ifFoodFish1(food: Fish | Bird){ //! Buggy code
    if(isFish1(food)){
        food     //! if you hover here you see the type script still confucesd
        return "Fish Food"
    }else{
        food
        return "Bird Food"
    }
}


                                    //todo: SAMPLE 2
function isFish2(pet: Fish | Bird): pet is Fish{ //* just this change and boom, no more confusion
    return (pet as Fish).swim !== undefined ;
}
function ifFoodFish2(food: Fish | Bird){ //* optimal code
    if(isFish2(food)){
        food     //! if you hover here you see the type script still confucesd
        return "Fish Food"
    }else{
        food
        return "Bird Food"
    }
}


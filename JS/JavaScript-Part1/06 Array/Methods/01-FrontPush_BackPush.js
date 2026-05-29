
                     //todo ->>>>>>>>>>>>>>>>> BODY 1
{       //* -----------------> * 1. push() & pop()  → END of array  //*
    let arrNumber = [];
    arrNumber.push(10);
    arrNumber.push(20);
    arrNumber.push(30);
    arrNumber.push(40);

    // [ 10, 20, 30, 40 ]
    console.log("Initial array :", arrNumber);

//? push
    console.log(`Now this is return on pushing(noArgs) : ${arrNumber.push()}`)   //? push() returns the Size of the new array !
    arrNumber.push();   //! noting happen on no parameters

    arrNumber.push(50); // [ 10, 20, 30, 40, *50 ]
    //! arrNumber.push(60,70,80, . . . . and So on); 

    console.log("\nAfter push(50):", arrNumber);

//? pop
    //* on pop() it return the last value which is deleted
    console.log(`Now this is return on popping : ${arrNumber.pop()}`);
    console.log("After pop():", arrNumber);
}



                    //todo ->>>>>>>>>>>>>>>>> BODY 2
{//* -----> 2. unshift() & shift() → START of array ------------>
                //!! mutate ARAY
    let arrNumber = [];
    arrNumber.unshift(10);   //! this add from the start
    arrNumber.unshift(20);
    arrNumber.unshift(30);
    arrNumber.unshift(40);

    // [ 10, 20, 30, 40 ]
    console.log("Initial array :", arrNumber);

    console.log(`Now this is return on unshift : ${arrNumber.unshift(0)}`);
    console.log("\nAfter unshift(0):", arrNumber);

    console.log(`Now this is return on shift : ${arrNumber.shift()}`);
    console.log("After shift():", arrNumber);
}
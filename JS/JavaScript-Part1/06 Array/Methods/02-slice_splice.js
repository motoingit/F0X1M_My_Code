
        //todo ------>> Body one
{                   //? slice() → Copy part of array (NON-mutating)
    let arrNumber = [];
    arrNumber.push(10);
    arrNumber.push(20);
    arrNumber.push(30);
    arrNumber.push(40);
    arrNumber.push(60);
    arrNumber.push(70);
    arrNumber.push(80);

    // [ 10, 20, 30, 40, 60, 70, 80 ]
    console.log("Initial array :", arrNumber); 

//* slice()                                               [                  )
    let sliced1 = arrNumber.slice(2, 5);     //? [ 10, 20, 30**, 40**, 60**, 70, 8 ]
    console.log("\nSlice [2,5):", sliced1);
    console.log("Original array unchanged:", arrNumber);

    //! last is -1 and then -2 second last not 0 ok
    let sliced2 = arrNumber.slice(2, -2);     //? [ 10, 20, 30**, 40**, 60**, 70, 8 ]
    console.log("\nSlice [2,5):", sliced2);
}





                //todo ------>> Body 2
{       //* --------->> splice() → Add / Remove (MUTATING)
        //!         MUTATION ON THE ORIGNAL ARRAy  *******************
    let arrNumber = [];
    arrNumber.push(10);
    arrNumber.push(20);
    arrNumber.push(30);
    arrNumber.push(40);
    arrNumber.push(60);
    arrNumber.push(70);
    arrNumber.push(80);

    // [ 10, 20, 30, 40, 60, 70, 80 ]
    console.log("Initial array :", arrNumber); 

    //* spice(x, n)          remove {n} element(s) starting from index {x}
    arrNumber.splice(2, 3); //? [ 10, 20, 30*, 40*, 60*, 70, 80 ]
    console.log("\nAfter splice remove:", arrNumber);

    // [ 10, 20, 70, 80 ]
    console.log("Now array :", arrNumber); 

    // spice(x)          remove element(s) starting from index {x}
    arrNumber.splice(1);
    console.log("After splice insert:", arrNumber);
}


                //todo ------>> Body 3
{       //! splice part 2
    let arrNumber = [];
    arrNumber.push(10);
    arrNumber.push(20);
    arrNumber.push(30);
    arrNumber.push(40);
    arrNumber.push(60);
    arrNumber.push(70);
    arrNumber.push(80);

    // [ 10, 20, 30, 40, 60, 70, 80 ]
    console.log("Initial array :", arrNumber); 

    //* spice(x, n, z)          remove {n} element(s) starting from index {x} and add {z} element(s)
    arrNumber.splice(2, 3, 25); //? [ 10, 20, 30*, 40*, 60*, 70, 80 ]
    console.log("\nAfter splice remove:", arrNumber);

    //[ 10, 20, 25, 70, 80 ]
    console.log(`Now this is return on splicing : ${arrNumber.splice(2,0, -1,-2,-3)}`)
    console.log("\nAfter splice As {Inserting}:", arrNumber);

    // [10, 20, -1, -2, -3, 25, 70, 80]
    console.log(`Now this is return on splicing {inserting multiple} : ${arrNumber.splice(0,0, "mellow", 'Yellow')}`)
    console.log("\nAfter splice As {Inserting}:", arrNumber);

    /**
     *  splice(); do noting and splice dont return anything
     *  splice(x); delete all from x indx
     *  splice(x,n); delete n element from x idx;
     *  splice (x,0,n1,n2,n3 . . . ..) ; point on x and delete noting and add before x {n1,n2 . .. .. }
     *  splice (x, n, n1 n2 n3) ; point on x ad delete n elemnets from there and add the n's
     */

}



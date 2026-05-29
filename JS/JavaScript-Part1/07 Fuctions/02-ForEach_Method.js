
//! fumction can be pased like an paraments in the diffrent fuction *************

let array = ["mona","mo23na","mo5na","mo6na","mo8na",];

array.forEach(
    function printVal(val) {
        console.log(val);
    }
)

//todo --> (val, idx, arr)
// here aray os already
array.forEach( 
    (val) => { //* this is callBackfuction (Full Body)
        console.log(val);
})

/**
 * This for each loop is the higher order Fuction
 * 
 */

//! higher order fuction is the fuction returning fuction or taking fuction as paramerter


//? why we use for each if we have for of
//arr
//   .filter(n => n > 10)
//   .forEach(n => console.log(n)); //! u can nest the forofloop like this
//?forEach is safer for beginners ()


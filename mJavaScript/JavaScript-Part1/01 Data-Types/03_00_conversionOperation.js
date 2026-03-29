

/*'
from frontend you never know the type
const {score} = req.body // no garenty
*/

let score1 = 33;

console.log(typeof score1)
console.log(typeof(score1))

let valueInNumber1 = Number(score1); //* garentied number

////////////////////


let score2 = "33av";
let valueInNumber2 = Number(score2); //! what the heck

console.log(typeof score2)
console.log(valueInNumber2); //* NaN
//* The Value: NaN stands for "Not a Number." It represents an undefined or unrepresentable numerical result.

//! this NaN is anotehr special type
//? thats why we have typescript

////////////////////

let score3 = null
console.log(typeof(score3))



////////////////////////////////////////////////////////////////////////

//* "33" -> 33
//* "33ab" -> NaN
//* null -> 0
//* true -> 1

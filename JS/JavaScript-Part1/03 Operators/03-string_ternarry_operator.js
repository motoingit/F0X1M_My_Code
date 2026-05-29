
//! ================================================
//! 5. String Operators
//! Used for concatenation or merging
//! ================================================

let first = "Java";
let second = "Script";
console.log("Concatenation:", first + second); // "JavaScript"



//! ================================================
//! 6. Ternary Operator (Inline Condition)
//! Acts as short if-else
//! ================================================

let age = 18;
let result = (age >= 18 ? "Eligible" : "Not Eligible");
console.log("Ternary Output:", result);



//! ================================================
//! 7. Type Operators
//! typeof → checks datatype
//! instanceof → checks object instance
//! ================================================

console.log("Type of first:", typeof first); // string
console.log("Type of a:", typeof a);         // number

let arr = [];
//* this [x istanceof Y] is the verifiing operator like thing {is arr varable is constructed with the Array class}
console.log("arr instanceof Array:", arr instanceof Array); // true

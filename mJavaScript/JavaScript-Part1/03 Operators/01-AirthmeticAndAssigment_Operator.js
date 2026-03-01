
//! ================================================
//! 1. Arithmetic Operators
//! Used for mathematical computation
//! ================================================

let a = 10;
let b = 3;

console.log("Addition:", a + b);          // 13
console.log("Subtraction:", 70 - 30);       // 40
console.log("Multiplication:", a * b);    // 30
console.log("Division:", a / b);          // 3.333...

//? Modulus (Remainder)
console.log("Modulus:", a % b);          // 1

//? Exponentiation x^y
console.log("Power:", a ** b);           // 1000

//? Increment
console.log("a = ", a);            // 11
console.log("Increment pre :", a++);            // 11
console.log("Increment now :", a);            // 11
console.log("Increment pre :", ++a);            // 11
console.log("Increment now :", a);            // 11

//? Decrement
b--;
console.log("Decrement:", b);            // 2



//! ================================================
//! 2. Assignment Operators
//! Store or update values
//! ================================================

let x = 10; // assingment

x **= 5; // same as x **= 5
console.log("x after **= :", x);

x %= 3; // same as x = x * 2
console.log("x after %= :", x);

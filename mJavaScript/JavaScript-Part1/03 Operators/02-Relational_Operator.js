 //! ================================================
 //! 3. Comparison / Relational Operators
 //! Used for evaluating logical relationships
 //! Produces Boolean output
 //! ================================================

let p = 20;
let q = "20";

//? Equal (value comparison)
console.log("p == q:", p == q); // true //! inmplicity convert p to sting

//? Strict Equal (value + type)
console.log("p === q:", p === q); // false

//? Not equal
console.log("p != q:", p != q); // false

//? Strict not equal
console.log("p !== q:", p !== q); // true

//? Greater / Less operations
console.log("p > 10:", p > 10); // true
console.log("p < 10:", p < 10); // false
console.log("p >= 20:", p >= 20); // true
console.log("p <= 15:", p <= 15); // false



//! ================================================
//! 4. Logical Operators
//! Returns Boolean based on conditions
//! ================================================

let cond1 = true;
let cond2 = false;

//? Logical AND
console.log("cond1 && cond2:", cond1 && cond2); // false

//? Logical OR
console.log("cond1 || cond2:", cond1 || cond2); // true

//? Logical NOT
console.log("!cond1:", !cond1); // false


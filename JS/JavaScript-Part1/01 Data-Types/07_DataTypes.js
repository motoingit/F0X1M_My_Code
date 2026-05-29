
/**
 * JAVASCRIPT DATA TYPES & CATEGORIZATION
 * JavaScript is a DYNAMICALLY TYPED language: Meaning Types are associated with values, not variables.
**/

/*
 * SUMMARY OF TYPEOF RETURNS:
 * 1. Number    => "number"
 * 2. String    => "string"
 * 3. Boolean   => "boolean"
 * 
 * 4. undefined => "undefined"
 * 7. null      => "object" (The historical bug)
 * 
 * 5. Symbol    => "symbol"
 * 6. BigInt    => "bigint"
 * 
 * 8. Array     => "object"
 * 9. Object    => "object"
 * 10. Function => "function" (Technically a 'callable object')
 */




// ==========================================
// 1. PRIMITIVE TYPES (Stored in STACK)
// ==========================================
// Primitives are immutable and passed by value.

const score = 100;             // Number
const scoreMy = 10.34;         // Number (JS doesn't differentiate int/float)
const isLogged = false;        // Boolean




// The "typeof null" Mystery
const outsideTemp = null; 
console.log(typeof outsideTemp); 
/* * TODO Answer: Why "object"? 
 * This is a historical bug in the first version of JavaScript. 
 * Values were stored in 32-bit units, with a type tag in the first few bits. 
 * The tag for objects was 000. null was represented as the NULL pointer (all zeros), 
 * so it was mistakenly identified as an object. It was never fixed to avoid breaking the web.
 */




let myUndefined1;              // Defaults to undefined (implict value / defualt value)
let myUndefined2 = undefined;  // Explicitly undefined




// Symbols: Guaranteed to be unique even with the same description
const id1 = Symbol('123');
const id2 = Symbol('123');
// todo: still i have doubt ?
console.log(id1 === id2);      // false (They are unique identifiers)





// BigInt: Used for numbers larger than 2^53 - 1
const bigNumber = 234234324234234234n; // The 'n' suffix defines a BigInt





// ==========================================
// 2. REFERENCE TYPES (Non-Primitive - Stored in HEAP)
// ==========================================
// These are objects and are passed by reference.

// A) Arrays
const heros = ["shaktiman", "motoMan"];

// B) Objects
const villan = {
    name: "Shakalaka",
    age: 800,
};



// C) Functions
// Functions are "First-class citizens" and technically "Function Objects"
function myNormalFunction(x) {
    console.log(x);
}

// Function Expression
let myFun1 = function myFuntion(x) {
    console.log(x);
};

// Anonymous Function Expression
let myFun2 = function(x) {
    console.log(x);
};

console.log(typeof myFun1); // Returns "function" (but internally it's an object)

//Note: primitive type also called fuction and funtion type also called object funtion, and non primitive to hai hi object

//https://262.ecma-international.org/5.1/#sec-11.4.3

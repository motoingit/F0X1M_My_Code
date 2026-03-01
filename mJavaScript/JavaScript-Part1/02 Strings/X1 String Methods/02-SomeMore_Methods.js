

let str = "Mohit Nautiyal";

console.log("Original String:", `"${str}"`); //? to see the no of space - cleanAndSmmoth
console.log("Length:", str.length);



// ========================================================================
//! look slice bracket colsely . . .. .
//* 4. slice [start, end) → Returns part of string
//* - start: required index
// ** - end: optional (excluded) 
//? slice can only be start also, and the end defaultly done like till end
// ========================================================================

let sliced1 = str.slice(0, 6);
let sliced2 = str.slice(6);
let sliced3 = str.slice();

console.log("\n=== slice(start, end) ===");
console.log("slice(0, 6):", sliced1);  // Output: "Mohit"
console.log("{Default till end}slice(6):", sliced2);  // Output: "Nautiyal"
console.log("{Default Like Orignal}slice():", sliced3);  // Output: "Mohit Nautiyal"


// ========================================================================
//* 5. concat(str2) → Joins two strings together
//? str1.concat(str2);  === str1 + str2
// ========================================================================

let str1 = "Hello";
let str2 = "World";

console.log("\n=== concat() ===");
console.log(str1.concat(str2));    // Output: "HelloWorld"
console.log(str1 + str2);    // Output: "HelloWorld"


// ========================================================================
//* 6. replace(searchVal, newVal)
//* - replaces FIRST occurrence of searchVal
// ========================================================================

let intro = "I am Mohit";
console.log("\n=== replace() ===");
console.log(intro.replace("Mohit", "Batman"));  
// Output: "I am Batman"



// ========================================================================
//* 7. charAt(index) → Returns the character at given index
// ========================================================================

let fullName = "Mohit";

console.log("\n=== charAt() ===");
console.log("charAt(0):", fullName.charAt(0));  // Output: M
console.log("charAt(3):", fullName.charAt(3));  // Output: i

// ======================================================================
//! forEach LOOP IN JAVASCRIPT (ARRAY METHOD)
//? Used to execute a callback function for EACH element of an array
// ======================================================================


/*
--------------------------------------------------------------------------
WHAT IS forEach?
--------------------------------------------------------------------------
- forEach is a BUILT-IN array method
- It loops through each element of an array
- It executes a CALLBACK FUNCTION once per element
- It DOES NOT return a new array
- It is used for SIDE EFFECTS (printing, updating UI, logging, etc.)
--------------------------------------------------------------------------
*/


// ======================================================================
//* 1. BASIC SYNTAX
// ======================================================================

/*
array.forEach(function(value, index, array) {
    // code to run for each element
});
*/

let arr = [10, 20, 30];

arr.forEach(function (val) {
    console.log(val);
});
// Output:
// 10
// 20
// 30


// ======================================================================
//* 2. CALLBACK FUNCTION (IMPORTANT THEORY)
// ======================================================================

/*
A CALLBACK FUNCTION is:
- A function passed as an argument to another function
- forEach internally CALLS this function for every element
*/

let names = ["Mohit", "Rahul", "Ankit"];

names.forEach(function (name) {
    console.log("Hello", name);
});
// Output:
// Hello Mohit
// Hello Rahul
// Hello Ankit


// ======================================================================
//* 3. Arrow Function Version (MODERN & RECOMMENDED)
// ======================================================================

names.forEach(name => {
    console.log(name.toUpperCase());
});
// Output:
// MOHIT
// RAHUL
// ANKIT


// ======================================================================
//* 4. Using index parameter
// ======================================================================

names.forEach((value, index) => {
    console.log(`Index ${index} → ${value}`);
});
// Output:
// Index 0 → Mohit
// Index 1 → Rahul
// Index 2 → Ankit


// ======================================================================
//* 5. Using all three parameters
// ======================================================================

names.forEach((value, index, array) => {
    console.log(value, "from", array);
});
// Output:
// Mohit from [ "Mohit", "Rahul", "Ankit" ]
// Rahul from [ "Mohit", "Rahul", "Ankit" ]
// Ankit from [ "Mohit", "Rahul", "Ankit" ]


// ======================================================================
//* 6. forEach DOES NOT RETURN ANYTHING
// ======================================================================

let nums = [1, 2, 3];

let result = nums.forEach(n => n * 2);

console.log(result);
// Output:
// undefined

/*
Reason:
- forEach is meant for execution, NOT transformation
- If you need a new array → use map()
*/


// ======================================================================
//* 7. forEach vs map (VERY IMPORTANT DIFFERENCE)
// ======================================================================

let doubled = nums.map(n => n * 2);
console.log(doubled);
// Output:
// [2, 4, 6]


// ======================================================================
//* 8. You CANNOT use break or continue in forEach
// ======================================================================

/*
nums.forEach(n => {
    if (n === 2) break;   // ❌ ERROR
});
*/

/*
Rule:
- If you need break / continue → DO NOT use forEach
- Use for / for...of instead
*/


// ======================================================================
//* 9. forEach with objects inside array (REAL WORLD)
// ======================================================================

let students = [
    { name: "Mohit", cgpa: 8.5 },
    { name: "Rahul", cgpa: 7.9 },
    { name: "Ankit", cgpa: 8.1 }
];

students.forEach(student => {
    console.log(student.name, "→ CGPA:", student.cgpa);
});
// Output:
// Mohit → CGPA: 8.5
// Rahul → CGPA: 7.9
// Ankit → CGPA: 8.1


// ======================================================================
//* 10. WHEN TO USE forEach (THEORY)
// ======================================================================

/*
USE forEach WHEN:
✔ Printing values
✔ Logging data
✔ Updating DOM
✔ Side effects
✔ Readability is priority

DO NOT USE forEach WHEN:
✖ You need a return value
✖ You need break / continue
✖ You want a transformed array
*/


// ======================================================================
//* 11. INTERNAL WORKING (CONCEPTUAL)
// ======================================================================

/*
forEach internally does something like:

for (let i = 0; i < array.length; i++) {
    callback(array[i], i, array);
}
*/


// ======================================================================
//! END OF forEach LOOP THEORY FILE
// ======================================================================

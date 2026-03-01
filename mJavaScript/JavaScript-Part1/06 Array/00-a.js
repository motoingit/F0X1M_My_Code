// ======================================================================
//! ARRAYS IN JAVASCRIPT
//? An array is an ordered collection of items stored in a single variable
//? Indexing starts from 0
// ======================================================================


// ======================================================================
//* 1. Creating Arrays
// ======================================================================

// Array of strings
let heroes = ["ironman", "hulk", "thor", "batman"];
console.log("Heroes:", heroes);

// Array of numbers
let marks = [96, 75, 48, 83, 66];
console.log("Marks:", marks);

// Mixed-type array (allowed in JS, but not recommended for structured data)
let info = ["rahul", 86, "Delhi"];
console.log("Mixed Info:", info);


// ======================================================================
//* 2. Accessing Array Elements
//*    Access using index (0-based)
// ======================================================================

console.log("First hero:", heroes[0]);     // ironman
console.log("Last hero:", heroes[3]);      // batman
console.log("Second mark:", marks[1]);     // 75


// ======================================================================
//* 3. Length of Array
//*    length is a PROPERTY, not a function
// ======================================================================

console.log("Heroes length:", heroes.length);
console.log("Marks length:", marks.length);


// ======================================================================
//* 4. Looping Through Arrays
// ======================================================================

// Using for loop (index-based)
console.log("\n-- for loop --");
for (let i = 0; i < heroes.length; i++) {
    console.log(i, heroes[i]);
}

// Using for...of (value-based)
console.log("\n-- for...of loop --");
for (let hero of heroes) {
    console.log(hero);
}


// ======================================================================
//* 5. Adding Elements to Array
// ======================================================================

let arr = [];

// push() → add at end (MOST USED)
arr.push(10);
arr.push(20);
arr.push(30);
console.log("After push:", arr);

// unshift() → add at start
arr.unshift(5);
console.log("After unshift:", arr);

// index assignment
arr[4] = 40;
console.log("After index assignment:", arr);


// ======================================================================
//* 6. Removing Elements from Array
// ======================================================================

// pop() → remove from end
arr.pop();
console.log("After pop:", arr);

// shift() → remove from start
arr.shift();
console.log("After shift:", arr);


// ======================================================================
//* 7. IMPORTANT DESIGN RULE (VERY IMPORTANT)
// ======================================================================

// ❌ BAD PRACTICE: using array for structured data
let badStudent = ["Mohit", 21, "Dehradun", 8.5];
console.log("Bad student design:", badStudent);

// Problems:
// - No meaning of index
// - Hard to read and maintain
// - Error-prone


// ✅ GOOD PRACTICE: use OBJECT for structured data
let student = {
    name: "Mohit",
    age: 21,
    city: "Dehradun",
    cgpa: 8.5
};
console.log("Good student design:", student);


// ======================================================================
//* 8. BEST REAL-WORLD PATTERN
//*    Array of Objects
// ======================================================================

let students = [
    { name: "Mohit", age: 21, city: "Dehradun", cgpa: 8.5 },
    { name: "Rahul", age: 22, city: "Delhi", cgpa: 7.9 },
    { name: "Ankit", age: 20, city: "Mumbai", cgpa: 8.1 }
];

console.log("\n-- Students List --");
for (let s of students) {
    console.log(s.name, "|", s.city, "| CGPA:", s.cgpa);
}


// ======================================================================
//* 9. Array Characteristics (Theory)
// ======================================================================

// ✔ Arrays are NON-PRIMITIVE (reference type)
// ✔ Arrays are mutable (can be changed)
// ✔ Arrays can store any data type
// ✔ Arrays are indexed collections
// ✔ typeof array → "object"

console.log("Type of heroes:", typeof heroes); // object
console.log("Is array?", Array.isArray(heroes)); // todo: true
console.log("Is array?", heroes instanceof Array); //! true


// ======================================================================
//! END OF ARRAYS THEORY + CODE
// ======================================================================

// ======================================================================
//! ARRAY METHODS IN JAVASCRIPT — HANDS-ON PRACTICE FILE
//? Focus: Understanding + Usage + Output
// ======================================================================


// ======================================================================
//* BASE ARRAY (used across examples)
// ======================================================================

let arrNumber = [10, 20, 30, 40, 50];
let fruits  = ["apple", "banana", "mango", "apple"];

console.log("Initial numbers:", arrNumber);
console.log("Initial fruits:", fruits);


// ======================================================================
//* 1. push() & pop()  → END of array
// ======================================================================

arrNumber.push(60);
console.log("\nAfter push(60):", arrNumber);

arrNumber.pop();
console.log("After pop():", arrNumber);


// ======================================================================
//* 2. unshift() & shift() → START of array
// ======================================================================

arrNumber.unshift(5);
console.log("\nAfter unshift(5):", arrNumber);

arrNumber.shift();
console.log("After shift():", arrNumber);


// ======================================================================
//* 3. slice() → Copy part of array (NON-mutating)
// ======================================================================

let sliced = arrNumber.slice(1, 4);
console.log("\nSlice (1,4):", sliced);
console.log("Original array unchanged:", arrNumber);


// ======================================================================
//* 4. splice() → Add / Remove (MUTATING)
// ======================================================================

// remove 1 element from index 2
arrNumber.splice(2, 1);
console.log("\nAfter splice remove:", arrNumber);

// insert element at index 2
arrNumber.splice(2, 0, 99);
console.log("After splice insert:", arrNumber);








       //! not dicoved yet  >>>

// ======================================================================
//* 5. forEach() → Loop (NO return value)
// ======================================================================

console.log("\nforEach output:");
arrNumber.forEach((value, index) => {
    console.log(`Index ${index} → ${value}`);
});


// ======================================================================
//* 6. map() → Transform array (RETURNS new array)
// ======================================================================

let doubled = arrNumber.map(n => n * 2);
console.log("\nmap() doubled:", doubled);
console.log("Original remains:", arrNumber);


// ======================================================================
//* 7. filter() → Select elements based on condition
// ======================================================================

let greaterThan30 = arrNumber.filter(n => n > 30);
console.log("\nfilter (>30):", greaterThan30);


// ======================================================================
//* 8. reduce() → Reduce array to single value
// ======================================================================

let sum = arrNumber.reduce((total, n) => total + n, 0);
console.log("\nreduce() sum:", sum);


// ======================================================================
//* 9. find() & findIndex()
// ======================================================================

let found = arrNumber.find(n => n > 30);
let foundIndex = arrNumber.findIndex(n => n > 30);

console.log("\nfind (>30):", found);
console.log("findIndex (>30):", foundIndex);


// ======================================================================
//* 10. includes(), indexOf(), lastIndexOf()
// ======================================================================

console.log("\nincludes('apple'):", fruits.includes("apple"));
console.log("indexOf('apple'):", fruits.indexOf("apple"));
console.log("lastIndexOf('apple'):", fruits.lastIndexOf("apple"));


// ======================================================================
//* 11. some() & every()
// ======================================================================

console.log("\nsome (>40):", arrNumber.some(n => n > 40));
console.log("every (>0):", arrNumber.every(n => n > 0));


// ======================================================================
//* 12. sort() & reverse()
// ======================================================================

let unsorted = [40, 10, 100, 30];
console.log("\nUnsorted:", unsorted);

// numeric sort
unsorted.sort((a, b) => a - b);
console.log("Sorted:", unsorted);

unsorted.reverse();
console.log("Reversed:", unsorted);


// ======================================================================
//* 13. concat() → Merge arrays
// ======================================================================

let merged = arrNumber.concat([70, 80]);
console.log("\nConcatenated:", merged);


// ======================================================================
//* 14. flat() & flatMap()
// ======================================================================

let nested = [1, [2, [3, 4]]];
console.log("\nflat():", nested.flat(2));

let flatMapped = arrNumber.flatMap(n => [n, n * 2]);
console.log("flatMap():", flatMapped);


// ======================================================================
//* 15. join() & toString()
// ======================================================================

console.log("\njoin('-'):", fruits.join("-"));
console.log("toString():", fruits.toString());


// ======================================================================
//* 16. Array.isArray()
// ======================================================================

console.log("\nArray.isArray(numbers):", Array.isArray(arrNumber));
console.log("Array.isArray({}):", Array.isArray({}));


// ======================================================================
//! END OF arrayMethods.js
// ======================================================================

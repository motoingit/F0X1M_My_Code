        // ========================================================================
        //! STRING METHODS IN JAVASCRIPT
        //? Built-in functions used to manipulate and transform strings
        // ========================================================================


                            //! stringMethods doest affect orignalSTRING



                            

let str = "   Mohit Nautiyal   ";

console.log("Original String:", `"${str}"`); //? to see the no of space - cleanAndSmmoth
console.log("Length:", str.length);


// ========================================================================
//* 1. toUpperCase() → Converts string to UPPERCASE
//* if aleadyUpper then leavit
// ========================================================================

console.log("\n=== toUpperCase() ===");
console.log(str.toUpperCase());     // Output: "   MOHIT NAUTIYAL   "


// ========================================================================
//* 2. toLowerCase() → Converts string to lowercase
// ========================================================================

console.log("\n=== toLowerCase() ===");
console.log(str.toLowerCase());     // Output: "   mohit nautiyal   "


// ========================================================================
//* 3. trim() → Removes leading and trailing whitespaces
// ========================================================================

console.log("\n=== trim() ===");
console.log(`"${str.trim()}"`);     // Output: "Mohit Nautiyal"




console.log("Original String still Untouched :", `"${str}"`); //? to see the no of space - cleanAndSmmoth
console.log("Length:", str.length);
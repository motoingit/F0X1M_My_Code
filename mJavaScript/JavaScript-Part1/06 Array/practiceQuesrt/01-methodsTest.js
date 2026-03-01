/**
 * Write a JavaScript program to perform the following operations on an array:

        Create an empty array.

        Add the following company names to the array using the appropriate method:
        "BloomBerg", "Microsoft", "Uber", "Google", "IBM", "Netflix"

        Remove the first element from the array.

        Replace the company name "Uber" with "OLA".

        Add "Amazon" at the end of the array.

        Print the array after each operation.
 */

//* Step 1: Create an empty array
let array = [];


//* Step 2: Add company names using push() → adds at END
array.push("BloomBerg");
array.push("Microsoft");
array.push("uber");
array.push("Google");
array.push("Ibm");
array.push("Netflix");

console.log("Initial array:");
console.log(array);
// Output:
// ["BloomBerg", "Microsoft", "uber", "Google", "Ibm", "Netflix"]


//* Step 3: Remove first element using shift() → removes from START
array.shift();

console.log("\nAfter shift() (first element removed):");
console.log(array);
// Output:
// ["Microsoft", "uber", "Google", "Ibm", "Netflix"]


//* Step 4: Replace 1 element at index 1 using splice()
// splice(startIndex, deleteCount, newItem)
array.splice(1, 1, "OLA");

console.log("\nAfter splice(1, 1, 'OLA'):");
console.log(array);
// Output:
// ["Microsoft", "OLA", "Google", "Ibm", "Netflix"]


//* Step 5: Add new element at the end using push()
array.push("Amaozn");

console.log("\nAfter push('Amaozn'):");
console.log(array);
// Output:
// ["Microsoft", "OLA", "Google", "Ibm", "Netflix", "Amaozn"]


// ======================================================================
//! END OF ARRAY OPERATIONS DEMO
// ======================================================================

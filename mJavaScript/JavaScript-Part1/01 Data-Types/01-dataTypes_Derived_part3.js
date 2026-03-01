// ======================================================================
//! NON-PRIMITIVE DATA TYPES (REFERENCE TYPES)
//? Collection of primitives stored as references (Hybrid DataType)
// ======================================================================


// ======================================================================
//* 1. OBJECT (Base Non-Primitive Type)
//*    Arrays, Functions, Maps, Sets — all are subtypes of Object
// ======================================================================

let student = {             //! Object = Key–Value Pair Structure
    name: "Mohit",
    age: 20,
    isEnrolled: true
};

console.log("Object (full):", student);
console.log("Object (student.age):", student["age"]);     //@ Access using bracket
console.log("Object (student.isEnrolled):", student.isEnrolled); // Access using dot



// ======================================================================
//* 2. ARRAY — Ordered Collection (Index → Value)
//*    Internally: { key: index++, value }
// ======================================================================

let arr = [10, 20, 30];
console.log("Array (arr[2]):", arr[2]);   // Output: 30



// ======================================================================
//* 3. FUNCTION — Callable Object
// ======================================================================

function greet() {
    return "Hello!";
}

console.log("Function reference:", greet);     //! Prints function definition
console.log("Function call:", greet());        //! Prints returned value
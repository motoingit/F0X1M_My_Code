
//! ------------ Legacy Declaration (AVOID) -------- var x ----------------------------------------
var age = "This Variable should Be Avoided";
/*****
    var:
    - Redeclarable
    - Reassignable
    - Function-scoped ( //? or global for only its fuction
    - Risky → leaks into global space
*/
console.log(age);


//* ------------ Modern Mutable Binding -----------------------------------------------------------
let userName = "Ram";
let a; //! undefined data type
/*
    let:
    - Not redeclarable in same scope
    - Reassignable
    - Block-scoped {}
    - Use when value needs to change
*/
console.log(userName);
   

//? ------------ Immutable Binding -------------------------------------------------------
const PI = 3.14;
/*
    const:
    - Not redeclarable
    - Not reassignable
    - Block-scoped {}
    - Default choice for fixed references
    - Note: objects/arrays defined with const can mutate internally
*/

console.log(PI);



//* final nnotes ------------------------------------------------------------------------------
// ===============================================
// Best Practice:
// Use const by default, switch to let when mutation is intentional,
// avoid var for clean, scalable architecture.
// ===============================================

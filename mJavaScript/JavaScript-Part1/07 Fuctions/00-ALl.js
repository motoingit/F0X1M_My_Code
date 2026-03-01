// ======================================================================
//! FUNCTIONS IN JAVASCRIPT
//? A function is a reusable block of code designed to perform a task
// ======================================================================


// ======================================================================
//* 1. FUNCTION DEFINITION (DECLARATION)
//*    Defines a function but does NOT execute it
// ======================================================================

function greet() {
    console.log("Hello! Welcome to JavaScript functions.");
}

// At this point, nothing runs yet


// ======================================================================
//* 2. FUNCTION CALL
//*    Executes the function
// ======================================================================

greet();  
// Output:
// Hello! Welcome to JavaScript functions.


// ======================================================================
//* 3. FUNCTION WITH PARAMETERS
//*    Parameters are variables that receive values
// ======================================================================

function greetUser(name) {
    console.log("Hello", name);
}

greetUser("Mohit");
greetUser("Rahul");
// Output:
// Hello Mohit
// Hello Rahul


// ======================================================================
//* 4. FUNCTION WITH MULTIPLE PARAMETERS
// ======================================================================

function add(a, b) {
    console.log("Sum:", a + b);
}

add(10, 20);   // Sum: 30
add(5, 7);     // Sum: 12


// ======================================================================
//* 5. FUNCTION WITH RETURN VALUE
//*    return sends a value back to the caller
// ======================================================================

function multiply(x, y) {
    return x * y;
}

let result = multiply(4, 5);
console.log("Multiplication result:", result);
// Output: 20


// ======================================================================
//* 6. FUNCTION WITHOUT return
//*    If no return → function returns undefined
// ======================================================================

function sayHi() {
    console.log("Hi!");
}

let value = sayHi();
console.log("Returned value:", value);
// Output:
// Hi!
// Returned value: undefined


// ======================================================================
//* 7. FUNCTION EXPRESSION
//*    Function stored in a variable
// ======================================================================

const subtract = function (a, b) {
    return a - b;
};

console.log("Subtract:", subtract(10, 3));
// Output: 7


// ======================================================================
//* 8. ARROW FUNCTION (MODERN JS)
//*    Shorter syntax, widely used in frontend frameworks
// ======================================================================

const square = (n) => {
    return n * n;
};

console.log("Square:", square(5));
// Output: 25


//* Shorter arrow function (implicit return)
const cube = n => n * n * n;
console.log("Cube:", cube(3));
// Output: 27


// ======================================================================
//* 9. DEFAULT PARAMETERS
//*    Used when argument is missing
// ======================================================================

function welcome(name = "Guest") {
    console.log("Welcome", name);
}

welcome("Mohit");
welcome();
// Output:
// Welcome Mohit
// Welcome Guest


// ======================================================================
//* 10. FUNCTION SCOPE (BASIC IDEA)
//*    Variables declared inside function are local
// ======================================================================

function testScope() {
    let secret = "Hidden";
    console.log(secret);
}

testScope();
// console.log(secret); // ❌ Error (not accessible outside)


// ======================================================================
//* 11. FUNCTIONS ARE VALUES (VERY IMPORTANT)
//*    Functions can be passed, stored, and returned
// ======================================================================

function execute(fn) {
    fn();
}

execute(() => console.log("Function passed as value"));
// Output: Function passed as value


// ======================================================================
//* 12. WHY FUNCTIONS EXIST (THEORY)
// ======================================================================

// ✔ Code reusability
// ✔ Better structure
// ✔ Avoid repetition
// ✔ Easier debugging
// ✔ Cleaner logic


// ======================================================================
//! END OF FUNCTIONS THEORY + CODE
// ======================================================================

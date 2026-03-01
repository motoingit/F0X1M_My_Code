// ================================================================
//! ESCAPE SEQUENCES IN JAVASCRIPT
//? Escape sequences let us insert special characters inside strings
//? using a backslash `\`. These characters cannot be typed directly.
// ================================================================


//* 1. \n  → NEW LINE (moves text to next line)
console.log("=== \\n → New Line ===");
console.log("Hello\nWorld");    // Output: Hello (new line) World


//* 2. \t  → TAB SPACE (adds horizontal indentation)
console.log("\n=== \\t → Tab Space ===");
console.log("Name:\tMohit");    // Output: Name:   Mohit


//* 3. \'  → SINGLE QUOTE (to place ' inside single-quoted string)
console.log("\n=== \\' → Single Quote ===");
console.log('It\'s a sunny day');  // Output: It's a sunny day


//* 4. \"  → DOUBLE QUOTE (to place " inside double-quoted string)
console.log("\n=== \\\" → Double Quote ===");
console.log("He said \"Hello World\"");  // Output: He said "Hello World"


//* 5. \\  → BACKSLASH (prints a single \)
console.log("\n=== \\\\ → Backslash ===");
console.log("C:\\Users\\Mohit");   // Output: C:\Users\Mohit


//! used in loading and sppinnng animation in terminal
//* 6. \r  → CARRIAGE RETURN (rare, resets cursor to line start)
console.log("\n=== \\r → Carriage Return ===");
console.log("Hello\rWorld");  
// Output visually becomes: "World"


//* 7. \b  → BACKSPACE (removes previous character)
console.log("\n=== \\b → Backspace ===");
console.log("Helloo\b");    
// Output: Hello  (last 'o' removed)


//! depricated
//* 8. \f  → FORM FEED (obsolete, used in old printers) 
console.log("\n=== \\f → Form Feed ===");
console.log("Line1\fLine2");  
// Output depends on console; often shows a space or special symbol

//! depricated
//* 9. \v  → VERTICAL TAB (rare, not visually obvious in most consoles)
console.log("\n=== \\v → Vertical Tab ===");
console.log("Hello\vWorld");


// ===================================================================
//* BONUS: ESCAPE SEQUENCE IN TEMPLATE LITERALS (still works)
console.log("\n=== Escape Sequences in Template Literals ===");
console.log(`Line1\nLine2`);
// Output: 
// Line1
// Line2


//* BONUS: Literal display of escape sequences
console.log("\n=== Showing Escape Sequences as Text (Literal) ===");
console.log("\\n \\t \\\" \\\\");
// Output: \n \t \" \\
// ===================================================================

console.log("\n=== END OF ESCAPE SEQUENCE DEMO ===");

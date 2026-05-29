
// ======================================================================
//* 4. DATE — Built-in Object for Time & Date Handling
// ======================================================================

let today = new Date();
console.log("Current Date:", today);



// ======================================================================
//* 5. REGEXP — Regular Expression Object
//*    Used for pattern matching in strings
// ======================================================================

let pattern = /abc/;

console.log("RegExp literal:", pattern);
console.log("RegExp replace:", "abc123".replace(/abc/, "XYZ")); // Output: XYZ123

/*
    /abc/ is a Regular Expression literal.
    It creates a RegExp Object → type "object".
    Used for searching, matching, replacing in strings.
*/



// ======================================================================
//* 6. MAP — Key–Value Collection (Keys can be ANY DataType)
//*    More powerful than plain objects
// ======================================================================

let m = new Map();

m.set("name", "Mohit");
console.log("Map get(name):", m.get("name"));
console.log("Map size:", m.size);



// ======================================================================
//* 7. SET — Collection of UNIQUE Values Only
// ======================================================================

let s = new Set();

s.add(10);
s.add(10);     //! Duplicate ignored → Set { 10 }

s.add("Mohit");
s.add({ age: 21 });
s.add([1, 2]);

console.log("Set object:", s);
console.log("Set size (after delete & clear):");

s.delete(10);
console.log(" → Size after delete(10):", s.size);

s.clear();
console.log(" → Size after clear():", s.size);



// ======================================================================
//* 8. WEAKMAP / WEAKSET — Auto-Garbage-Collected Collections
//*    Keys MUST be objects → Prevents Memory Leaks
// ======================================================================

let wm = new WeakMap();
let obj = { name: "Mohit" };

wm.set(obj, "some data");
console.log("WeakMap get(obj):", wm.get(obj));  // "some data"

// After: obj = null;
// WeakMap auto-removes the entry → Excellent for memory management



// ======================================================================
//* 9. ERROR OBJECTS — Used for Throwing Exceptions
// ======================================================================

// Create error object
new Error("Something went wrong");

// Throwing the error:
// throw new Error("Something went wrong");

"use strict";

/*
====================================================
 IIFE — ALL-IN-ONE DEMO FILE
 Immediately Invoked Function Expressions
====================================================

Purpose:
- Show ALL common IIFE patterns in ONE place
- Highlight syntax + behavior differences
- Interview + production ready reference
====================================================
*/


/*
----------------------------------------------------
 1️⃣ CLASSIC FUNCTION IIFE (ES5)
----------------------------------------------------
- Oldest form
- Has its own `this`
- Used heavily before ES6 modules
*/

(function () {
    console.log("1️⃣ Classic Function IIFE executed");

    var secret = "hidden data";
    console.log("Inside Classic IIFE:", secret);
})();

// console.log(secret); // ❌ ReferenceError (private scope)


/*
----------------------------------------------------
 2️⃣ ARROW FUNCTION IIFE (ES6)
----------------------------------------------------
- Shorter syntax
- No own `this`
- Best for simple isolated logic
*/

(() => {
    console.log("2️⃣ Arrow Function IIFE executed");

    const value = 42;
    console.log("Inside Arrow IIFE:", value);
})();

// console.log(value); // ❌ ReferenceError


/*
----------------------------------------------------
 3️⃣ ASYNC IIFE (Modern / Industry Standard)
----------------------------------------------------
- Enables async/await immediately
- Common in startup & initialization code
*/

(async () => {
    console.log("3️⃣ Async IIFE started");

    function fakeApiCall() {
        return new Promise((resolve) => {
            setTimeout(() => resolve("API response received"), 1000);
        });
    }

    const result = await fakeApiCall();
    console.log(result);

    console.log("3️⃣ Async IIFE finished");
})();


/*
====================================================
 FINAL COMPARISON (READ THIS)
====================================================

Classic IIFE  → Full function features, legacy-heavy
Arrow IIFE    → Lightweight, no `this`
Async IIFE    → Best for real-world async flows

Rule of thumb:
- Simple isolation → Arrow IIFE
- Needs async/await → Async IIFE
- Legacy / full control → Function IIFE

====================================================
*/

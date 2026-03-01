"use strict";

/*
====================================================
 ASYNC CONTROL FLOW — COMPARISON FILE
 Callback Hell vs Promise Chain vs Async/Await
====================================================

Goal:
- Same async task
- Three different control-flow strategies
- Understand WHY modern JS prefers async/await

Simulated API: getData(id)
====================================================
*/

// ---------------------------------------------
// Common async function (simulated API call)
// ---------------------------------------------
function getData(id) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log(`Data ${id} received`);
            resolve(`SUCCESS ${id}`);
        }, 1000);
    });
}

/*
====================================================
 1️⃣ CALLBACK HELL (Legacy / Anti-Pattern)
====================================================
Problems:
- Deep nesting
- Poor readability
- Hard to debug
- Impossible to scale
*/

console.log("\n--- CALLBACK HELL ---");

function getDataWithCallback(id, callback) {
    setTimeout(() => {
        console.log(`Data ${id} received`);
        callback();
    }, 1000);
}

getDataWithCallback(1, () => {
    console.log("getting data2...");
    getDataWithCallback(2, () => {
        console.log("getting data3...");
        getDataWithCallback(3, () => {
            console.log("getting data4...");
            getDataWithCallback(4, () => {
                console.log("callback hell ends\n");
            });
        });
    });
});

/*
====================================================
 2️⃣ PROMISE CHAIN (Better, but Verbose)
====================================================
Improvements:
- Flat structure
- Error handling possible
- Still noisy for long flows
*/

setTimeout(() => {
    console.log("\n--- PROMISE CHAIN ---");

    getData(1)
        .then((res) => {
            console.log("getting data2...");
            return getData(2);
        })
        .then((res) => {
            console.log("getting data3...");
            return getData(3);
        })
        .then((res) => {
            console.log("getting data4...");
            return getData(4);
        })
        .then((res) => {
            console.log("promise chain ends\n");
        })
        .catch((err) => {
            console.error("Error:", err);
        });

}, 6000);

/*
====================================================
 3️⃣ ASYNC / AWAIT (Industry Standard)
====================================================
Advantages:
- Reads like synchronous code
- Best readability
- Best maintainability
- Preferred in production systems
*/

setTimeout(async () => {
    console.log("\n--- ASYNC / AWAIT ---");

    try {
        console.log("getting data1...");
        await getData(1);

        console.log("getting data2...");
        await getData(2);

        console.log("getting data3...");
        await getData(3);

        console.log("getting data4...");
        await getData(4);

        console.log("async/await ends\n");
    } catch (err) {
        console.error("Error:", err);
    }

}, 12000);

/*
====================================================
 FINAL TAKEAWAY (NON-NEGOTIABLE)
====================================================

Callback Hell  → ❌ Legacy, avoid
Promise Chain  → ⚠ Acceptable, but verbose
Async/Await    → ✅ Default choice in real systems

Rule of thumb:
If your async logic is more than 2 steps,
use async/await — no debate.

====================================================
*/

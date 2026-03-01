const URL = "https://dogapi.dog/api-docs/v2/swagger.json";

/* ===============================
   1️⃣ CALLBACK HELL VERSION
================================ */
function getFacts1(callback) {
  console.log("Fetching data (callback)...");

  fetch(URL)
    .then(res => res.json())
    .then(data => {
      callback(data.info.description);
    })
    .catch(err => console.error(err));
}

/* ===============================
   2️⃣ PROMISE CHAIN VERSION
================================ */
function getFacts2() {
  console.log("Fetching data (promise)...");

  fetch(URL)
    .then(res => res.json())
    .then(data => {
      document.getElementById("factPrint2").innerText =
        data.info.description;
    })
    .catch(err => console.error(err));
}

/* ===============================
   3️⃣ ASYNC / AWAIT VERSION
================================ */
async function getFacts3() {
  try {
    console.log("Fetching data (async/await)...");

    const res = await fetch(URL);
    const data = await res.json();

    document.getElementById("factPrint3").innerText =
      data.info.description;
  } catch (err) {
    console.error(err);
  }
}

/* ===============================
   EVENT LISTENERS
================================ */

document.getElementById("factGet1").addEventListener("click", () => {
  getFacts1((fact) => {
    document.getElementById("factPrint1").innerText = fact;
  });
});

document.getElementById("factGet2").addEventListener("click", getFacts2);
document.getElementById("factGet3").addEventListener("click", getFacts3);

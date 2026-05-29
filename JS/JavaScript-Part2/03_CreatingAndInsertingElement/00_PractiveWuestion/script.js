
let newBtn = document.createElement("button");
newBtn.innerText = "This is my Butn"

document.querySelector("h1").before(newBtn)

let newHeading = document.createElement("h2");
newHeading.innerText = "This is newHeading"

document.querySelector("body").append(newHeading);
let newBtn = document.createElement("button");
newBtn.innerText = "Click Me !";

//todo :  on console the inline styles are from the javascrip logic
newBtn.style.backgroundColor = "red";
newBtn.style.color = "white";


//let targetElement = document.querySelector("h1");
//targetElement.before(newBtn);
let targetElement = document.querySelector("body");
targetElement.prepend(newBtn);
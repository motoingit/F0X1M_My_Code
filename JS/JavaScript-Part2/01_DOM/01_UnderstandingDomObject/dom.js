
        //* Get element-object refrence by xMethod


//? get by ElementId
let x = document.getElementById("heading");
console.dir(x); // if id is not exist then NULL
console.log(x);
console.log('\n');

let y = document.getElementsByClassName("moto") //! elements spelling
console.dir(y); //if class is not exist then empty Elements{{(0)}}
console.log('\n');

let z = document.getElementsByTagName("span")
console.log(z);
console.log('\n');



        //* properties by a node (element, text)

let firstElements = document.querySelector("p"); //only return 1st p-block
console.dir(firstElements);

let elementsAll = document.querySelectorAll("p"); //return all p-block
console.dir(elementsAll); //Node list return

let elementsClassAll = document.querySelectorAll(".moto"); //only return 1st element
console.log(elementsClassAll)

let elementsIdAll = document.querySelectorAll("#heading")
console.log(elementsIdAll)
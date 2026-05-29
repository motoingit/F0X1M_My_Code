
//? creating the element to insert
let newBtn = document.createElement("button");
newBtn.innerText = "ClickMe!";
console.log(newBtn);


//! inserting technique (4 and these are most popular)


//appending after the  last child node
let div = document.querySelector("div");
div.append(newBtn);

//prepending before the first child node
let div2 = document.querySelector("div");
div2.prepend(newBtn);



// adding before the node
let div3 = document.querySelector("div");
div3.before(newBtn);

//adding after the node
let div4 = document.querySelector("div");
div4.before(newBtn);

//todo   - appendChild and removeChild is also there



                //todo: the newBtn can only go oneTime not many are not working simultaneurssly
                //? ans : we can use the newBtn an other


//! deleting an element;
let p = document.querySelector("p");
p.remove();

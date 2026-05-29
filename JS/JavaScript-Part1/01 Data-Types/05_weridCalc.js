

console.log(1+2*3%4);

//* why do that when you can do this
console.log((1+2)*(3%4));

//////////////////////////////////////////////

console.log(+true)
// console.log(true+) //! error
console.log(-true)
console.log(true-false)
console.log(false-true)

///////////////////////////////////////////////

console.log(+"");

///////////////////////////////////////////////


let num1, num2, num3

num1 = num2 = num3 = 2 + 2

///////////////////////////

let gameConter = 100;
gameConter++;
++gameConter;
console.log(gameConter);


let x = 3;
const y = x++;

console.log(`x:${x}, y:${y}`);
// Expected output: "x:4, y:3"

let a = 3;
const b = ++a;

console.log(`a:${a}, b:${b}`);
// Expected output: "a:4, b:4"
//*  https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Increment
////////////////////////////////

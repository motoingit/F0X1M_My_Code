const name = "hitesh"
const repoCount = 50

console.log(name + repoCount + " Value");
// OR
console.log(`${name} has ${repoCount} repos in his Account`);

const gameName = new String("Mohit")

console.log(gameName[0]); //*
console.log(gameName.__proto__); //*onbject
console.log(gameName.length); //*onbject
console.log(gameName.toLocaleUpperCase()); //*onbject
console.log(gameName.toLocaleUpperCase); //*onbject
console.log(gameName.charAt(3))
console.log(gameName.indexOf('t'));

console.log(gameName.substring(0, 4));
console.log(gameName.substring(-20, 4)); //! ignore and take -20 as 0


const newString = "Hello-World"
console.log(newString.slice(-8, 4));
console.log(newString.slice(2, 4));

const newStringOne = "     hites   dffdf  ";
console.log(`{${newStringOne}} + {${newStringOne.trim()}}`)
//wrokds with
// trimStart and trimENd

//*   %20 = " "
const url = "https://hitesh.com/hitesh%20choudhary";
console.log(url.replace('%20', '-'));

console.log(url.includes('hitesh')); //! hitesh hai kya string maei

const myString = "Hello-WOrkd-hsooo";
console.log(myString.split("-"));

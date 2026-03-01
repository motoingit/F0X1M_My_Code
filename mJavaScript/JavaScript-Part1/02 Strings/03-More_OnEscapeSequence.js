


let str = "Hello\tWorld"; //? expects 12 length

let i = 0;
for(let x of str){
    console.log(x);
    i++;
}

console.log("Size is : ", i); //* but get 11


//! as each escape sequece is just one character { its just we cant type it so we have this anatomy}
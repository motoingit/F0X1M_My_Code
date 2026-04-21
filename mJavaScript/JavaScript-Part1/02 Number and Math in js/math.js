
// +++++++++++++++ MATH Library ++++++++++++++++

console.log(Math)

console.log(Math.abs(4));
console.log(Math.abs(-4));
console.log(Math.abs(-0));
console.log(Math.abs(-10.3));

console.log(Math.round(34.32));
console.log(Math.round(34.92));

console.log(Math.floor(4.92));
console.log(Math.ceil(4.12));

console.log(Math.min(4.12, 32, 3.4, -23));
console.log(Math.max(4.12, 32, 3.4, -23));

Math.trunc()

/**
 6. Other methods
    .MAX_VALUE
    .MIN_VALUE
    .MAX_SAFE_INTEGER
    .MIN_SAFE_INTEGER
 */

// random


console.log(Math.random());
console.log(Math.random());
console.log(Math.random());

Math.random()*10 + 1 // This assures that values are atleast 1 & more than 1
(Math.random()*10) + 1 // To avoid any BODMAS rule miscalculation

// range randoms
const _Mymax = 250, _Mymin = 150;
const myRand = (Math.trunc(Math.random() * (_Mymax - _Mymin + 1))) + _Mymin;
console.log(myRand);



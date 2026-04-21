// Dates

let myDate = new Date()
console.log(myDate);
console.log(myDate.toString());
console.log(myDate.toLocaleString());
console.log(myDate.toDateString());
console.log(myDate.toLocaleDateString());
console.log(myDate.toISOString());
console.log(myDate.toJSON());

console.log(typeof myDate);

//
let myCreatedDate  = new Date(2000, 0, 23); //! month fromo 0 to 11
let myCreatedDate1  = new Date(2000, 0, 23, 5, 3); //! month fromo 0 to 11
console.log(myCreatedDate.toDateString())
console.log(myCreatedDate1.toString())

// YYYY-MM-DD
let myDat2 = new Date("2023-01-14");
// MM-DD-YYYY
let myDat3 = new Date("01-14-2023");

//! 1 jab 1970 (refrence)
let myTimeStamp = Date.now();
let myCreatedDate3 = new Date("01-14-2023");

//* now you can compare both dates (refrence)
console.log(myTimeStamp);
console.log(myCreatedDate3);

//
console.log(Math.floor(Date.now()/1000)); // now in sec

///////

let newDate = new Date();
console.log(newDate.getMonth())


///////////////////////////

//! importatnt
newDate.toLocaleString("default", {
   weekday: "long",
   day: "2-digit",
   timeZone: "America/New_York",
})

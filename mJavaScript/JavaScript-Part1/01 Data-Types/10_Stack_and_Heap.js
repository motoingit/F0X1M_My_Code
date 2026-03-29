
// stack(primiteve), heap(non-primitive)



let myName = "mohitSIngh";
let anotherName = myName; //* passed as copy
anotherName = "solo";

console.log(myName);
console.log(anotherName);


// -------------



let user = {
    email: "user@gmail.com",
    upi: "user@ybl"
}

let admin = user; //! passed as refrence
admin.email = "admin@gmail.com"

console.log(admin);
console.log(user);

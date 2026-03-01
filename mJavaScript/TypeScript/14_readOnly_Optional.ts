
type User = {
    readonly _id: string, //now you want be abale to change it
    name: string,
    email: string,
    isActive: boolean,
    creditCard ? : string, //this is optional
}

let myUser : User = {
    _id: "1234",
    name: "M",
    email: "m#m",
    isActive: false,
}

myUser.email = "Hello@";
myUser._id = "asa"; //! read only 

export {}

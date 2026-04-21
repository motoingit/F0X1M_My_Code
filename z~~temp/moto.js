

let myFun = ()=>{
    console.log(this);
}

let student = {
    name: "Mohit",
    myFun: ()=>{
        console.log(this);
    }
}

myFun();
student.myFun();

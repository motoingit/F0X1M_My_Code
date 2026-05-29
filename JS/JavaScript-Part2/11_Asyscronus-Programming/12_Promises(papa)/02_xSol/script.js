function async1(){
    return new Promise((res, err)=>{
        setTimeout(()=>{
            console.log("Data 1 is Fetched !");
            res("Successfully")
        }, 3000);
    })
}

function async2(){
    return new Promise((res, err)=>{
        setTimeout(()=>{
            console.log("Data 2 is Not Feteced !");
            err("Wheather Problem")
        }, 3000);
    })
}

//* so pronblem sol

console.log("data 1 is fething in 3sec")
let p1 = async1();
p1.then((res)=>{
    console.log("data 1 is consumed sucessfuly : ",res)
    console.log("data 2 is fething in 3sec")
    let p2= async2();
    p2.catch((err)=>{
        console.log("data 2 is not cunsumed due to : ",err);
    })
})
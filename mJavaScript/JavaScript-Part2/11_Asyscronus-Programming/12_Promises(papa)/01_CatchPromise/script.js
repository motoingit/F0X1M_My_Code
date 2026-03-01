
function getData(dataId){
    return new Promise((resolve, reject)=>{
        setTimeout(()=>{
            console.log("My name is mohit")
            // resolve("Sucess");
            reject("Harsh wheather")
        }, 5000)
    })
}


//todoo :  handinling promise returns

let promice = getData(" moto data iiiie22");
promice.then((res)=>{
    console.log("Promise Fullfiled : ", res);
})
promice.catch((err)=>{
    console.log("rejected Network Eror : ",err)
})




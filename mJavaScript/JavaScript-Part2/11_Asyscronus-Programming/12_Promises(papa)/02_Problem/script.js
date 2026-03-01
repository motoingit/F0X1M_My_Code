// promise chain

function asycronnusFuction1(){
    return new Promise((res, rej)=>{
        setTimeout(()=>{
            console.log("Some data1");
            res("Sucess");
        }, 5000)
    })
}

function asycronnusFuction2(){
    return new Promise((res, rej)=>{
        setTimeout(()=>{
            console.log("Some data2");
            res("Sucess");
        }, 10000)
    })
}
//! so here the data for both is featching simultanusly so that we  now the give noto

console.log("feteching data1 in 5sec")
let p1 = asycronnusFuction1();
p1.then((res)=>{
    console.log(res);
})


console.log("feteching data2 in 10sec")
let p2 = asycronnusFuction2();
p1.then((res)=>{
    console.log(res);
})
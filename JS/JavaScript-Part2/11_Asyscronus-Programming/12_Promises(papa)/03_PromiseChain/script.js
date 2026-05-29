function getData(dataId){ 
    return new Promise((res, err)=>{
        setTimeout(()=>{
            console.log(`Data is feteched for ${dataId}`);
            res("sucessfull")
        }, 2000)
    })
}


//todo : promise chain
getData(101).then((res)=>{
    return getData(202)
})
.then((res)=>{
    return getData(303)  
})
.then((res)=>{
    return getData(404)  
})
.then((res)=>{
    return getData(505)  
})
.then((res)=>{
    console.log(res);
})
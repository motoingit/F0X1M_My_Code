function getData(dataId, getNextData){ // avg time 2s to search data
    setTimeout(()=>{
        console.log("data : ",dataId);
        if(getNextData)
            getNextData();
    }, 2000)
}


//! call back hell - not easy to understand for vetrans
getData("Username", ()=>{ 
    getData("Password", ()=>{
        getData("OTP")
    }) 
});
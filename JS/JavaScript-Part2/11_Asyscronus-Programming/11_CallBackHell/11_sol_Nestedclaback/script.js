function getData(dataId, getNextData){ // avg time 2s to search data
    setTimeout(()=>{
        console.log("data : ",dataId);
        if(getNextData)
            getNextData();
    }, 2000)
}


// getData("Username", getData("Password")); //! this is wrong, is it execute before
getData("Username", ()=>{ //* this arrow is call back
    getData("Password") //todo here no callback so if
});
function getData(dataId){ // avg time 2s to search data
    setTimeout(()=>{
        console.log("data : ",dataId);
    }, 2000)
}


//? here i want to see these data alternativly but these are working simultaneusly
getData("Username");
getData("Password");
getData("OTP");
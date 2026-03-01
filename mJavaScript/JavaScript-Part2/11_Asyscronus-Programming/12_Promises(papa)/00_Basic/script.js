
let promise = new Promise((resolve, reject)=>{
    console.log("Im promice")
    // reject("error")
    resolve("Sucess")
})

//! in genral promeses is handled and reutnr by the otherside people.

// we juest get resetult


function getData(dataId, getNextData){
    return new Promise((resolve, reject)=>{
        setTimeout(()=>{
            console.log("")
            resolve("Sucess");
            if(getNextData){
                getNextData();
            }
        }, 5000)
    })
}





















// function getData(dataId, getNextData){ // avg time 2s to search data
//     setTimeout(()=>{
//         console.log("data : ",dataId);
//         if(getNextData)
//             getNextData();
//     }, 2000)
// }


// // getData("Username", getData("Password")); //! this is wrong, is it execute before
// getData("Username", ()=>{ //* this arrow is call back
//     getData("Password") //todo here no callback so if
// });
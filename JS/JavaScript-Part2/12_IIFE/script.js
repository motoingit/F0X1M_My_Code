
function api(){
    return new Promise((res, err)=>{
        setTimeout(()=>{
            console.log("Wheather data !");
            res(200) //* sucess indication 200
        }, 3000)
    })
}



//! this is iife, no need to call
(async function (){
    await api(); //data 1 then data 2 will featch
    await api(); //this only  works when data 1 is over
    await api();
    await api();
    await api();
    await api();
})();



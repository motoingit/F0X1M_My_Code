//* async fuction return promise
// async function hello() { 
//     console.log("hello");
// }

function api(){
    return new Promise((res, err)=>{
        setTimeout(()=>{
            console.log("Wheather data !");
            res(200) //* sucess indication 200
        }, 3000)
    })
}

async function getWeather(){
    await api(); //data 1 then data 2 will featch
    await api(); //this only  works when data 1 is over
    await api();
    await api();
    await api();
    await api();
}


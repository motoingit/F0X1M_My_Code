const darkBtn = document.querySelector("#darkMode");


//! this is form evenlistner
// darkBtn.addEventListener('click',() => {
//     console.log('someone trys to change mode black')
//     const body = document.querySelector("body")
//     body.setAttribute("style", "background-color: black")
// })

// darkBtn.addEventListener('dblclick',() => {
//     console.log('someone trys to change mode while')
//     const body = document.querySelector("body")
//     body.setAttribute("style", "background-color: white")
// })


//? second method
// let currMode = "light"
// darkBtn.addEventListener('click',() => {
//     if(currMode == "light"){
//         console.log('someone trys to change mode black')
//         const body = document.querySelector("body")
//         body.setAttribute("style", "background-color: black")
//         currMode = "dark"
//     }else{
//         console.log('someone trys to change mode while')
//         const body = document.querySelector("body")
//         body.setAttribute("style", "background-color: white")
//         currMode = "light"
//     }
// })



let currMode = "light"
darkBtn.addEventListener('click',() => {
    if(currMode == "light"){
        console.log('someone trys to change mode black')
        const body = document.querySelector("body")
        body.classList.add("dark")
        body.classList.remove("light")
        currMode = "dark"
    }else{
        console.log('someone trys to change mode while')
        const body = document.querySelector("body")
        body.classList.add("light")
        body.classList.remove("dark") //! using class list
        currMode = "light"
    }
})
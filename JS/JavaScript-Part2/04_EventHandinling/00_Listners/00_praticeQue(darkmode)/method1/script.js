const darkBtn = document.querySelector("#darkMode");


darkBtn.onclick = (evt) => {
    console.log('someone trys to change mode black')
    const body = document.querySelector("body")
    body.setAttribute("style", "background-color: black")
}
darkBtn.ondblclick = (evt) => {
    console.log('someone trys to change mode while')
    const body = document.querySelector("body")
    body.setAttribute("style", "background-color: white")
}
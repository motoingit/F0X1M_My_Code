
let div = document.body.querySelector("div")
console.dir(div)

/*
    on console:
        - div.innerText
            >'Fruilts\nMango\naango\njango'

        -div.innerHtml
            >'\n        <h1> Fruilts </h1>\n        <ul>\n            <li>Mango</li>\n            <li>aango</li>\n            <li>jango</li>\n        </ul>\n    '
*/

div.innerText = "ABCD"
//? div.innerHTML = "<div> FDFFF </div>"
/// div.textContent = "seeImage" //!this can even see the hidden content (refrence = "image.png")
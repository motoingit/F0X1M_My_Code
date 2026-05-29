const BASE_URL = 
    "https://2024-03-06.currency-api.pages.dev/v1/currencies"

//selects
const selects = document.querySelectorAll("#main-box select");

//btns
const textBtn = document.querySelector("#textBtn");
const convertBtn = document.querySelector("#convertBtn");

const msgDiv = document.querySelector("#msg");

// { //testing 1
//     console.log(dropDowns)
//     for( code in codeList){ //! this is crazzy
//         console.log(code, countryList[code])
//     }
// }

for(let select of selects){
    for(let code in codeList){
        let newOption = document.createElement("option")
        
        newOption.innerText = code
        newOption.value = code

        //& this is just for if preent
        if(select.name === 'from' && code === 'USD')
            newOption.selected = "selected";
        else if(select.name === 'to' && code === 'INR'){
            newOption.selected = "selected";
        }

        select.append(newOption);
    }

    //evt lstner
    select.addEventListener("change", (evt)=>{
        //todo: evt is a metadata object about what just happened.
        //for more visit down
        updateFlag(evt.target);  // current element {select}
    })
}
                                    //! serch more about it
function updateFlag(element){ //*this is triggered element {select}
    let currCode = element.value; //! what is this value
    let currCountryCode = codeList[currCode];

    //* crazzy bhai
    let newSrc = `https://flagsapi.com/${currCountryCode}/flat/64.png`
    let currImgElement = element.parentElement.querySelector("img");
    currImgElement.src = newSrc
}


/*
    evt.type       // "change"
    evt.target     // element that triggered the event
    evt.timeStamp  // when it happened
*/


//! hold 
convertBtn.addEventListener("click", async (evt) => { //* async
    evt.preventDefault();

    let currVal = textBtn.value;
    if(!(currVal > 0 ) || currVal == ""){
        currVal = Number(1);
        textBtn.value = "1"
        //? you can add error here
    }

    let left = selects[0].value.toLowerCase();
    let right = selects[1].value.toLowerCase();

    const newURL = `${BASE_URL}/${left}.json`;
    // console.log(selects[0].value, selects[1].value)
    let response = await fetch(newURL)
    //! add fail and sucess
    let data = await response.json();

    const rightRate = data[left][right];
    // console.log(left, right, rightRate);
    amountConv = (textBtn.value) * rightRate;

    let string = `${left} ${currVal} = ${right} ${amountConv.toFixed(2)}`;
    msgDiv.innerText = string;
})

window.addEventListener('load', );

// //exchangeRateBtn
// inputDiv.addEventListener("click", (evt) => { 
//     evt.preventDefault(); //! you can also use type="button" in button in html
//     printRate();
// })

// function printRate(){
//     let left = selects[0].value
//     let right = selects[1].value
//     // console.log(left, right)

//     codeList
// }
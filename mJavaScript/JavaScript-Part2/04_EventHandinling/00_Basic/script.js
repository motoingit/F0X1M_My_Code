/**
//? newBtn.onclick
    node.event{
    
    }
 */

    //! inline handling is lower preciedence than jsHndling
    //! if you write the twoFuction of same structure then the second one will overide first

let targetBtn = document.querySelector(".controls").children

targetBtn[0].onclick = () =>{
    console.log("you just clicked the fist chiled")

}

targetBtn[2].onmouseover = () =>{
    console.log("you just hover the thirsd chiled")
}

targetBtn[1].ondblclick = (evt) => {
    console.log(evt);
    console.log(evt.target);
    console.log(evt.type);
    console.log(evt.clientX, evt.clientY);
}
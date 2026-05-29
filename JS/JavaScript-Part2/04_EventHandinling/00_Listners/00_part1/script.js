/** Event LIstners
//?   even is just hover or x.      here call back is the handler fuction
    node.addEventListner(event, callbackFuc){
    
    }
 */

let targetBtn = document.querySelector(".controls").children
console.log(targetBtn)

 //* even handler mai tho overide hora tha but yaha ni 
 //? therefore on one event we can do multiple task
targetBtn[0].addEventListener('click',(evt)=>{
    console.log("Task1 perforemed")
    console.log(evt.type)
})

targetBtn[0].addEventListener('click',(evt)=>{
    console.log("task2 Performend {aur overide bhi ni hua}")
    console.log(evt.type)

})



//! yaad hai na vo galti ?
{
    // targetBtn[0].addEventListener = ('click',(evt)=>{
    // console.log("task2 Performend {aur overide bhi ni hua}")
    // console.log(evt.type)
    // })

        //todo: pata chala diffrnce

    // targetBtn[0].addEventListener('click',(evt)=>{
    // console.log("task2 Performend {aur overide bhi ni hua}")
    // console.log(evt.type)
    // })
}
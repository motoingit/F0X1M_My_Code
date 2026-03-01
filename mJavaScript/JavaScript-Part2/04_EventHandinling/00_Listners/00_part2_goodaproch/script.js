
let targetBtn = document.querySelector(".controls").children
 //* even handler mai tho overide hora tha but yaha ni 
 //? therefore on one event we can do multiple task

const fun1 = (evt)=>{
    console.log("Task1 perforemed")
    console.log(evt.type)
}
const fun2 = (evt)=>{
    console.log("task2 Performend {aur overide bhi ni hua}")
    console.log(evt.type)
}

targetBtn[0].addEventListener('click',fun1)
targetBtn[0].addEventListener('click',fun2)

//remove
targetBtn[0].removeEventListener('click',fun2)




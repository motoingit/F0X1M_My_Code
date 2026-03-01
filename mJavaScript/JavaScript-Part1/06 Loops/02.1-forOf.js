
let orignalPrice = []
orignalPrice.push(250)
orignalPrice.push(645)
orignalPrice.push(300)
orignalPrice.push(900)
orignalPrice.push(50)

console.log('Orignalyt :',orignalPrice)

// for(let x in orignalPrice){
//     orignalPrice[x] -=  (orignalPrice[x] / 100) * 10;
// }

//! this one is quite Wisdomy
let i = 0;
for(let val of orignalPrice){ 
    let offer = val/10;
    orignalPrice[i] -= offer;
    //* as val is copied before you even touched it logicaly
    console.log(`value after change in loop : ${val} , arr[] = ${orignalPrice[i]}`)
    i++;
}

console.log('After 10% discount :',orignalPrice)
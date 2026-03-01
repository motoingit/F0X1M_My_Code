
let arr = [1,2,3,4,5,6,7,8,9,100]
let city = ['Laknow','gie','ERER']
console.log(arr)

for(let idx = 0; idx < arr.length; idx++){
    console.log(arr[idx])
}

for(let i of arr){
    console.log(i)
}

for(let i in arr){
    console.log(arr[i])
}

for(let i of city){
    console.log(i.toUpperCase())
}



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
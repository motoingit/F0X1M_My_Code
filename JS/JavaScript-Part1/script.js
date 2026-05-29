
let arr = [1,2,3,4,5,6,7]
let obj = {
    name: 'moto',
    roll: 21,
    cgpa: 8.0,
}

for(let x in obj){
    obj[x] = 10;
}

for(let x of obj){
    console.log(x)
}
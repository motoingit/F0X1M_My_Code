const arr = []
// const arr = [1,2,3,4]

let temp;

//* Number(str) gives int
while(true){ //if temp 0 then out
    temp = Number(prompt("Enter number (0 to stop):"));
    if (temp === 0) break;              // exit condition
    arr.push(temp);
}

arr.forEach((val,idx) => {
    console.log(`Value = ${val}, ValueSqr = ${val**2}, IDX = ${idx}`)
});
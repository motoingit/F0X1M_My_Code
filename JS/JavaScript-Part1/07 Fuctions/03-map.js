
let array = [23,4,53]

//! in forEach its making changes withing the origanl aray
// map is used when the values of a data set should be modeifiend and return that copy
let newArray = array.map( (val)=> { //* retunring new array
    return val**2;
})

console.log(newArray);
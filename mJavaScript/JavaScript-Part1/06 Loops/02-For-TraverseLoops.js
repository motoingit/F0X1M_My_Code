/*
    For-Of loop :
        - traverse on uniform-containers
*/
{ //* for-of :  let {x} of {container} loop           (for each) {# ?for(let x in str) #}
    let str = prompt("Enter String : "); //! prompt return sting alqways

    for(let x of str) {
        // console.log("Character at position ", x, " is ", "hello world"[x]);
        console.log("Character is ", x);
    }

    for(let x in str) {
        // console.log("Character at position ", x, " is ", "hello world"[x]);
        console.log("Character at position ", x, " is ", str[x]);
    }
}

{ //* for-in : let {key} in {obj} :  loop with object-itself
    let student = {     //? object
        name: "Mohit",
        age: 21,
        college: "IIT Roorkee"
    };

    for(let x in student) { //? for each key in object z, iterate till all keys are done
        // console.log("Character at position ", x, " is ", "hello world"[x]);
        console.log('Student with key', x, 'has value', student[x]);
    }

    //! if you try to iterate from of , then ERROR-Non-Iterable
    // for(let x of student){
    //     console.log('Student with key', x, 'has value', student[x]);
    // }
}
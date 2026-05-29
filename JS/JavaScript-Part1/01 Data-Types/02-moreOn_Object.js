

{
    const student = {
        // const fullName : "Hitman", //! error
        fullName : "Hitman",
        age: 20,
        isPass: true,
    };

    student.fullName = "Not hitman"; //! we can change the values of the key in the object ,despite of const or not
    console.log(student.fullName);
}




{
   //? one problem
    /* //! if name of the key or variable is  like :
        Quotes are optional unless the property name contains:
    
            spaces → "first name"
            hyphens → "user-id"
            numbers at start → "1value"
            special chars
    */ //* then we use "name" which is same as {name, without quotes}
    
    const object1 = {
        name: "Mohit",
        age: 21,
        college: "IIT Roorkee"
    }
    
    const object2 = {
        'name': "Mohit",
        'age': 21,
        'college': "IIT Roorkee"
    }
}
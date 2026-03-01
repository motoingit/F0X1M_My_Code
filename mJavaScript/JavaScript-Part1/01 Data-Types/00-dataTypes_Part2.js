// ===============================================
//* JavaScript Data Types Demonstration
// ===============================================


//*! ---------------- Primitive Types ( 7 ) ----------------

//*** (1) Number >

    console.log('\n(1) Number ------------>');
    let score = 95;
    console.log("Number:", score);       //*    as score is a number so its high lighted
    console.log({score});               //?      {score} == { score: 95 }
    console.log("Type:", typeof score); //? this function is for knowing the datatype by compiler


//*** (2) String >

    console.log('\n(2) string ------------>');
    let studentName = "Mohit"; //! in console i can see datatype with "typeof x"
    let nickName = 'mohit singh'
    console.log(typeof nickName," :", nickName);



//*** (3) Boolean

    console.log('\n(3) Boolean ------------>');
    // let is = True;
    let isActive = true;
    console.log("Boolean:", isActive);
    console.log("Type:", typeof isActive);

//*** (4) Undefined
    console.log('\n(4) Undefined ------------>');
    let futureValue; // value not assigned
    console.log("Undefined:", futureValue);
    console.log("Type:", typeof futureValue);

//* 5. Null
    let emptyValue = null; //! null is absence of object (eventhough after writeing typeof NULL it said object)
    console.log("Null:", emptyValue);
    console.log("Type:", typeof emptyValue); //! object













    
// 6. BigInt (not popular)
    let bigNumber = 123456789012345678901234567890n; //* n is 
    let big = BigInt("23423798237489723894723897"); //! another method
    console.log("BigInt:", bigNumber);

// 7. Symbol (not popular)
    let uniqueKey = Symbol("id");
    console.log("Symbol:", uniqueKey);
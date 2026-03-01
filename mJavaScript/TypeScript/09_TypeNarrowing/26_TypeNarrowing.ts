function detectType(val: number | string){
    if(typeof val === "string"){
        return val.toUpperCase();
    }
    return ++val;
}

function provideId(id: string | null){
    if(!id){
        console.log("Please Provide Id");
        throw Error("Id Null");
    }
    id.toLowerCase();
}


                                //* NOW THIS CAASE



function printAll(strs: string | string[] | null) { ///! here an empty string is not covered which is same as null object
  // !!!!!!!!!!!!!!!!
  //  DON'T DO THIS!
  //   KEEP READING
  // !!!!!!!!!!!!!!!!
  if (strs) {
    if (typeof strs === "object") {
      for (const s of strs) {
        console.log(s);
      }
    } else if (typeof strs === "string") {
      console.log(strs);
    }
  }
}

// In JavaScript, constructs like if first “coerce” their conditions to booleans to make sense of them, and then choose their branches depending on whether the result is true or false. Values like

// 0
// NaN
// "" (the empty string)
// 0n (the bigint version of zero)
// null
// undefined

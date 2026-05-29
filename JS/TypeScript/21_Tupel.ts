// not like python
// but some kind or array with ristrition in Type script


// so 
let user: (string | boolean)[] = ["mc", false];
user = ["mc", false];
user = ["mc", false, true, "bc"];
//todo: but here the pattern or order is not persistement


//so we have tupel
let myTupel : [string, number, boolean] //* only three and in the same pattern
myTupel = ["dd", 122, true];
myTupel = [true, 122, "solo"]; // ye ni lega
myTupel = ["dd", 122, true]; // pattern whould be like this








//!     https://stackoverflow.com/questions/64069552/typescript-array-push-method-cant-catch-a-tuple-type-of-the-array
//M2

type Xser = [number, string];
const nw_User: Xser = [122,"hii"];
nw_User.push(true); //? not work now days ? its the problem here
// let nw_User[1] = "Hel";

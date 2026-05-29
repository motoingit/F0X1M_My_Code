
const data1 : number[] = [1.2."3"];

const data2 : string[] = [1.2."3"];

const data3 : string[] | number[] = [];   //either all no or all string - NO MIX

const data4 : (string | number)[] = [1,'2',6];   // MIX

//litrally only one 
let pi: 3.14 = 3.14; //only this val


let seatAllotment: "Aisle" | "Middle" | "Window";
seatAllotment = "Middle";
seatAllotment = "private"; //now allowed only 3

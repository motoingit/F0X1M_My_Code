

            // In TS

enum SeatChoice {
    AISLE = "Mohit",
    MIDDEL = "Solo",
    WINDOW= 0,
}

const hcSeat = SeatChoice.AISLE; 



                    // IN JS

/*

"use strict";
var SeatChoice;
(function (SeatChoice) {
    SeatChoice["AISLE"] = "Mohit";
    SeatChoice["MIDDEL"] = "Solo";
    SeatChoice[SeatChoice["WINDOW"] = 0] = "WINDOW";
})(SeatChoice || (SeatChoice = {}));    //? this is the fuction call it self
const hcSeat = SeatChoice.AISLE; 

*/










/// PART 2


                        //in JS
const enum SeatChoice {
    AISLE = "Mohit",
    MIDDEL = "Solo",
    WINDOW= 0,
}

const hcSeat = SeatChoice.AISLE; 


            // in TS
/*
"use strict";
const hcSeat = "Mohit" /* SeatChoice.AISLE */;
*/

// when we have to restric the choice


//traditional
const AISLE = 0;
const MIDDEL = 0;
const WINDOW = 0;

if(seat === 0) {

}


//
enum SeatChoice {
    AISLE, //default is 0
    MIDDEL,
    WINDOW,
    FOURTH, //more option
}

//
enum SeatChoice {
    AISLE=10, 
    MIDDEL,
    WINDOW,
    FOURTH, //more option
}

//
enum SeatChoice {
    AISLE=10, 
    MIDDEL,
    WINDOW = 80,
    FOURTH, //more option
}

//
enum SeatChoice {
    AISLE = "A234", //default is 0
    MIDDEL = "B234",
    WINDOW = "C234",
    FOURTH = "DE", //more option
}

//
enum SeatChoice {
    AISLE = "A234", //default is 0
    MIDDEL = 11,
    WINDOW = "C234",
    FOURTH = "DE", //more option
}

const hcSeat  = SeatChoice.AISLE;

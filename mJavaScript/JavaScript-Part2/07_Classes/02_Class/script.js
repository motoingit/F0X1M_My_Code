class Car{
    speed = 234;
    color = "white";

    constructor(d){
        this.speed = d;
    }
    start(){
        console.log("Starting engline")
    }
    stop(){
        console.log("shutdown engine")
    }
    setBrand(brand){
        this.brandName = brand; //! even brandName dont exist it boom
    }
}

let toyoto = new Car();
toyoto.setBrand('totoya');

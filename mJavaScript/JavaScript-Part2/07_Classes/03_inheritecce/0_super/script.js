class Human{
    age = 0;
    name;
    constructor(name, age){
        this.age = age;
        this.name = name;
        console.log("Human is genrating")
    }
    eat(){
        console.log("Human is eating")
    }
    sleep(){
        console.log("Human is sleeping")
    }
}

class Enggineer extends Human{
    salary = 0 ;
    constructor(name , age , salary){
        super(name, age);
        this.salary = salary;
    }
    work(){
        super.eat();
        console.log("working");
    }
}



let eng = new Enggineer("Mohit" , 34, 30000);
console.log(eng)

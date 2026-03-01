class User{
    email:string
    name:string
    location:string = "Default" //i give this initializer
    constructor(email: string, name: string){
        this.email = email;
        this.name = name;
    }
}

const moto = new User("Mohit@213", "Mohit");

/**
 * //* in js
    class User{
        constructor(email, name){
            this.email = email;
            this.name = name;
        }
    }
*/

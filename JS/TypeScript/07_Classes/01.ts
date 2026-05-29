class Admin{

    public email:string

    //todo: there is no such thing as PRIVATE in Js verse, but in Ts (#name === private name)
    // #name //! this is also same
    private name:string

    //auto public 
    location:string = "Default" //i give this initializer

    constructor(email: string, name: string){
        this.email = email;
        this.name = name;
    }
}

let mohit = new Admin("mo@324", "Mohit");
mohit.name = "df";


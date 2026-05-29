class User{
    constructor(
        public email: string, 
        public name: string
    ){
        this.email = email;
        this.name = name;
    }

    private deleteToken(){ //this can only be acess in the class
        // token deleted
    }
}

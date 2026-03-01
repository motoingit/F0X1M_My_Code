class UserGoogle{
    private _existingId = 1; // why _underscore
    constructor(
        public email: string, 
        public name: string
    ){
        this.email = email;
        this.name = name;
    }

    // this get is keyword for getter
    get getGoogleEmail(): string{
        return `google${this.email}`
    }

    get existingId(): number{
        return this._existingId
    }

    //? typescript want even want you to set anything here but blank
    // set existingId(newData): void{} //! error if done like this

    set existingId(newData){
        //code for setting
        if(newData <= 0){
            throw new Error("should more than 0")
        }
        this._existingId = newData;
    }
}

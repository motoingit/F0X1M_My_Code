
// you aleardy know that the private member of the parenct canot  be inherited

class BaseToyota{ //* Both men and women
    private nSecret:string = "Haha";
    protected nMama:number = 10;
    constructor(
        public nSeats:number,
        public nSpaceContainer:number,
    ){
        this.nSeats = nSeats;
        this.nSpaceContainer = nSpaceContainer;
    }
}

class Toyota_Women extends BaseToyota{ //but private not inherite // but protected
    constructor(
        
        public nMirror:number
    ){
        this.nMirror = nMirror
    }
}

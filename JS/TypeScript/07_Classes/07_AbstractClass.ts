/*
=====================================================
ABSTRACT CLASS IN TYPESCRIPT
=====================================================

An abstract class is a PARTIALLY implemented class.

Key ideas:
1. You CANNOT create an object of an abstract class.
2. It can contain:
   - abstract methods (no body)
   - concrete methods (with body)
3. Child classes MUST implement all abstract methods.
4. Abstract classes are used when:
   - You want a base class with shared logic
   - But you want subclasses to decide specific behavior
=====================================================
*/

/*
-----------------------------------------------------
ABSTRACT BASE CLASS
-----------------------------------------------------
*/

abstract class Account { //todo: now this is abstract class mening cannot make instance of this class but inherit
    username: string;
    email: string;

    constructor(username: string, email: string) {
        this.username = username;
        this.email = email;
    }

    // Abstract methods (no implementation)
    abstract createAccount(): void; //! so abstact method should always be defined by child
    abstract deleteAccount(): void;

    // Concrete method (shared logic)
    displayInfo(): void {
        console.log(`User: ${this.username}, Email: ${this.email}`);
    }
}

/*
-----------------------------------------------------
CHILD CLASS 1: InstagramAccount
-----------------------------------------------------
*/

class InstagramAccount extends Account {
    constructor(
        public username: string, 
        public email: string,
        public follower: number,
    ){
        super(username, email); //! for calling the constructor from the parent
        this.follower = follower //* this cannot go above super
    }

    createAccount(): void { //! if i dont implement abstract class (in this case parenct) (ERROR then)
        console.log(`Instagram account created for ${this.username}`);
    }

    deleteAccount(): void {
        console.log(`Instagram account deleted for ${this.username}`);
    }
}

/*
-----------------------------------------------------
CHILD CLASS 2: YouTubeAccount
-----------------------------------------------------
*/

class YouTubeAccount extends Account {
    subscribers: number = 0;

    createAccount(): void {
        console.log(`YouTube channel created for ${this.username}`);
    }

    deleteAccount(): void {
        console.log(`YouTube channel deleted for ${this.username}`);
    }
}

/*
-----------------------------------------------------
USAGE
-----------------------------------------------------
*/

// ❌ NOT ALLOWED (compile-time error)
// const acc = new Account("moto", "moto@gmail.com");

// ✅ Allowed: object of concrete subclasses
const insta = new InstagramAccount("moto_ig", "moto@gmail.com");
const yt = new YouTubeAccount("moto_yt", "moto@gmail.com");

insta.createAccount();
insta.displayInfo();

yt.createAccount();
yt.displayInfo();


interface AccountGeneration {
    username: string;
    email: string;

    createAccount(): void;
    deleteAccount(): void;
}

//! implements
class InstagramAccount implements AccountGeneration { // see this is giveing eror, check on hovering class naem

    constructor(username: string, email: string) {
        this.username = username;
    }

    createAccount(): void {
        console.log(`Instagram account created for ${this.username}`);
    }

    deleteAccount(): void {
        console.log(`Instagram account deleted for ${this.username}`);
    }
}

class YouTubeAccount implements AccountGeneration { //* and this one is completly fine as more but not less
    username: string;
    email: string;
    subscribers: number;

    constructor(username: string, email: string) {
        this.username = username;
        this.email = email;
        this.subscribers = 0;
    }

    createAccount(): void {
        console.log(`YouTube channel created for ${this.username}`);
    }

    deleteAccount(): void {
        console.log(`YouTube channel deleted for ${this.username}`);
    }
}

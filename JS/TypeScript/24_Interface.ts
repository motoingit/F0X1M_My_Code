// loose form of class
// just have basic protocall
// look like Type

// interface are like something

interface User {
    readonly dbId: number,
    email: string,
    userId ? : number,
    // startTrail: () => string,
    startTrail(): string,
    getCoupon(couponName: string): number,
}

const hitesh: User = {dbId: 342343234, email: "H@gamil.com", userId: 2023,
    startTrail: () => {
        return "Your desied";
    },
    getCoupon: (name: "copn23") => {
        return 32;
    },
};


//Reopening of the interface
interface User { //! no th above code is demanding to write gihub var
    githubToken : string,
}

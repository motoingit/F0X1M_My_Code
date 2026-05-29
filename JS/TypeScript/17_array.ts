// const superHero = []
const superHero: string[] = []
superHero.push("spider-man")




const superNumber: number[] = []
superNumber.push(2)



const arrNumber: Array<number> = []
arrNumber.push(1)





type User = {
    name: string,
    email: string,
    isActive: boolean,
}

const allUsers: User[] = []
// allUsers.push("solo");//error
let user1: User = {name: "Mohit",email: "Google@",isActive: true};
allUsers.push({name: "Mohit",email: "Google@",isActive: true});


console.log("Hii")

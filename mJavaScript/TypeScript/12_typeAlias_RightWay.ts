
type User = {
    name: string,
    email: string,
    isActive: boolean,
}

function createUser(user: User): User{
    return {name: "", email: "", isActive: true,}
}

type MyString = string; //this is alias

let x = createUser ({name: "", email: "", isActive: true,}) //this is the correct way (12_Objects.ts Solved)

export {}

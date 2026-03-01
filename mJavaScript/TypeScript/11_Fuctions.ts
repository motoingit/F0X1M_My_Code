const User = {
    name: "moto",
    email: "moto@gmail.com",
    isActive: true,
}

function createUser1({name: string, isPaid: boolean}): {} // idont know this error

function createUser2({name, isPaid}: {name: string, isPaid: boolean}): {} 

function createUser3({name, isPaid}: {name: string, isPaid: boolean}): {name: string, isPaid: boolean}{
    return {name: "Solo", isPaid: true}
}

function createUser3({name, isPaid}: {name: string, isPaid: boolean}): {name: string, isPaid: boolean}{
    return {name: "Solo", isPaid: true, email: "mu@.com",}
}


function createAdmin({name: string, isPaid : boolean}):{}{
    return {name: 'Mohit', isPaid: false}
}

createUser1({name: 'Mohit', isPaid: false});



export{} //! later talk in react

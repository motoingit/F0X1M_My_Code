interface User{
    name: string,
    email: string,
}

interface Admin{
    name: string,
    email: string,
    isAdmin: boolean
}

function isAdmin(acc: User | Admin){
    if("isAdmin" in acc){ //! using in we are narroing it
        //now this confirm admin
        return isAdmin;
    }

}

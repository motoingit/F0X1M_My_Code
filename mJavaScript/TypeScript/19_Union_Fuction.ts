

function getId1(id: number | string){
    if(typeof id === "string"){
        id.toLocaleLowerCase();
    }
}

function getId2(id: number | string){
    id.toLocaleLowerCase(); // both posibility
}




// Fuctions in JS

function greet(){
    console.log("NamasteBharat\n");
}

function greetX(message){
    console.log(`Konichiwa ${message} Desuka\n`);
}

function greetN(message, n){
    for(let idx = 1; idx <= n; idx ++){
        console.log(`Arigato ${message}\n`);
    }
}

function blessing(message){
    return `Jete Raho Beta ${message}`;
    
    s = "My darling" //! this line never runs
}

function critical(string, number){ //* paraments
    return string * number;
}



greet
console.log(greet) //* arguments
greet();

greetX("CHal Bsdk");
greetN('Mohit', 10);

console.log(blessing('$100'))

console.log(critical('name',324)) //! NaN
console.log(critical('234',324))


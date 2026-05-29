
{ //* for loop
    let n = prompt("No of Greetings : ");
    
    for(let i = 1; i <= n; i++) {
        console.log("Greeeting No is : ", i);
    }
}

{ //* while loop
    let n = prompt("No of Greetings : ");
    
    while(1){ //! if you run this code it will crach your browser because it is infinite loop
        console.log("Greeeting No is : ", n);
        n--;
    }
}

{ //? Note : the while in do-while loop is out of its own Block
    let value;

    do { 
        value = prompt("Enter a number greater than 10:");
    } while (value <= 10);

    console.log("Valid input:", value);

}
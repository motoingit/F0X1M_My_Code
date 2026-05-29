
{
    
    {                       //! Problem
        //* so the do-while loop condintion is out of its own scope ************************
        let num = 100; 

        do{ 
            let inputNum = prompt("Guess Number 95 to 100 : "); 
        }while(inputNum != 100);  //!❌ ERROR → inputNum is NOT defined here

        console.log("Hurrrrrrrya");
    }

    {                       //? how to fix it
        let num = 100;

        let inputNum;
        do{
            inputNum = prompt("Guess Number 95 to 100 : ");
        }while(inputNum != 100); //! dont write !== as the prompt send sting by default

        console.log("Hurrrrrrrya");
    }


}
{
    str = 'Random String';
    console.log('Orignal String:',str);
    
    console.log(str.replace('Random', 'My'));
    
    console.log(`My origal string is still untoucehd "${str}"`);
    
    //! so the method just returns the manipulated string 
    //! they doesnt mutate the string at origanal place
    
    str = str.replace('Random', 'My'); //? this is the real deal
    console.log(`Now Reinitialization TOUCHED my string "${str}"`);

}

{
    str = 'My World';
    str[0] = 'H'; //! this dosnt work
    console.log(str);
}

{
    str = "tellMe"
    console.log(str.length); //* lenght is the property not the fuction
}
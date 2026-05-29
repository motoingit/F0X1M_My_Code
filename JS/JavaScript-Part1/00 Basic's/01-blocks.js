

//* first block
{
    let a = 10;
    console.log(a);
}

//* second block (scope)
{
    // console.log(a); //! as the first a is destroyed
    let a = 10;
    console.log(a);
}

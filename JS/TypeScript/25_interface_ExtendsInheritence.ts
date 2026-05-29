interface Admin {
    name : string,
    getName() : string,
}

// interface Owner extends Admin, anyOtherInterfaceClass{
interface Owner extends Admin{
    role: "Senior" | "Junior";
}

/** 
 //! diffrence b/w INterface and the alias (Type)
 https://www.typescriptlang.org/docs/handbook/2/everyday-types.html#differences-between-type-aliases-and-interfaces
 * 
*/

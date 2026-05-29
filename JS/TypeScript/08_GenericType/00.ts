const score1: Array<number> = [];
const score2: Array<string> = [];
// so generic we see many times but dont think in early days but now wll studiy in detail

//todo: SYNTAX
function identity<Type>(arg: Type): Type { //* Type is just a name OK ! no Rules <x>
  return arg;
}
//todo


// Lets see Cases alternatives

//* one way seems like genric
function motoOne(val: boolean|number): boolean|number{
    return val;
}

//* second way but not well definded
function motoTwo(val: any): any{
    //! if no is given so string is written
    return val;
}

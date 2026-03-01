function identity<Type>(arg: Type): Type { //* Type is just a name OK ! no Rules <x>
  return arg;
}

interface Bootle{
    brand: string,
    type: number,
}

identity<Bootle>({ brand: "Nike", type: 1 }); //todo:  THIS IS TRUE LEAGEND 

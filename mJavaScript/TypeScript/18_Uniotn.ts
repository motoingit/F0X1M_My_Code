let score :number | string | boolean  = 33
// it can be so on
//? But its very bad way to typeDefine your variable

type User = {
    name: string;
    id: number;
}

type Admin = {
    username:string;
    id:Number;
}


let mohit: User | Admin = {name:"hitesh", id:78};
mohit = {username:"hitesh", id:78};

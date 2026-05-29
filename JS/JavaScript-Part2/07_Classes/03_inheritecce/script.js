

{
    class parent{
        constructor(){
            this.name = 'mom';
        }
        setName(name){
            this.name = name;
        }
    }

    class child extends parent{

    }

    let c = new child();
    c.setName("mhot");
    console.log(c);
}

{
    class person{
        eat(){
            console.log("eat");
        }
        work(){
            console.log("not working")
        }
    }

    class enginer extends person{
        work(){ //! method overiding (child is strong)
            console.log("working")
        }
    }

    let x = new enginer()
    console.log(x);
}
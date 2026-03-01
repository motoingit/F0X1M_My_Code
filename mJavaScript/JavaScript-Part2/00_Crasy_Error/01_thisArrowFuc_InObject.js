const student1 = {
    name: 'molu',
    marks: 324,
    printMarks() {
        //* Object methods → need dynamic this
        console.log("marks : ", this.marks);
    }
}

const student2 = {
    name: 'molu',
    marks: 324,
    printMarks : () => {
        //! Arrow functions → lexical this
        console.log("marks : ", this.marks);
    }
}

/**
 * Arrow functions do not have their own this. They inherit this from the surrounding (lexical) scope. In this case, this is not the student object — it’s either window, undefined, or the module scope (depending on environment).
 */
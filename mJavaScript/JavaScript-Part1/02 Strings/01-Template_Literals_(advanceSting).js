


   //?  “Template literals provide a way to embed expressions inside strings and 
    //?   allow substitution through placeholders.”

const teacher = {
    'name' : 'Arunsh',
    'salary' : 10000,
    "Grade" : 'A',
};

//? this is SimpleString
console.log("This is Teacher Named",teacher.name,"and the salary", teacher.salary,'Haha..')


//* this is Template Literals (advanced string)
//! it uses back-upper {`} not this [']
strTemplate = `This is Teacher Named ${teacher.name} and with Salary ${teacher.salary} ! HAha..`;
console.log(strTemplate);
console.log(typeof strTemplate);

let str = `Sample template ${2+5}`; //? ivaluation haaa
console.log(str);
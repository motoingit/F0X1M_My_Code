let student = {
    name: 'Mohit',
    adg: 45,
    cgpa: 67.67,
    isPass:true,
};

console.log(student.name);
console.log(student[name]); //* confucsing isnt

for(let i in student){
    console.log(i);
    console.log(student[i]);
}
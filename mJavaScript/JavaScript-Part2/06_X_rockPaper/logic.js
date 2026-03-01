
let imgUser = document.body.querySelector("#profileUser")
let imgComp = document.body.querySelector("#profileComp")

imgUser.setAttribute('src',"https://shorturl.at/a6PsI");
imgComp.setAttribute('src',"https://shorturl.at/tYm7L");



//now

const options = ['rock', 'paper', 'sissor'];
let controlBtn = document.body.querySelectorAll('.btn')
let notify = document.body.querySelector("#msg") 

controlBtn.forEach((btn) => {
    const choice = btn.getAttribute('title');

    btn.addEventListener('click', (event) => {
        const computerChoice = getRandomChoice(options);
        console.log(computerChoice)
        if(computerChoice == choice){
            notify.textContent = ' draw'
            notify.setAttribute('style','color: black')
        }else if(computerChoice == 'sissor'){
            if(choice == 'rock'){
                notify.textContent = ' user winds'
                notify.setAttribute('style','color: green')
            }else{
                notify.textContent = ' comp winds'
                notify.setAttribute('style','color: red')
            }
        }else if(computerChoice == 'paper'){
            if(choice == 'sissor'){
                notify.textContent = ' user winds'
                notify.setAttribute('style','color: green')
            }else{
                notify.textContent = ' comp winds'
                notify.setAttribute('style','color: red')
            }
        }else {
            if(choice == 'paper'){
                notify.textContent = ' user winds'
                notify.setAttribute('style','color: green')
            }else{
                notify.textContent = ' comp winds'
                notify.setAttribute('style','color: red')
            }
        }
    });
});

//random string return
function getRandomChoice(choices) {
    const randomIndex = Math.floor(Math.random() * choices.length);
    return choices[randomIndex];
}

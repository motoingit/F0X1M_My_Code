
type cardNo = { //1
    cardNo : string,
}

type cardExpDate = { //2
    cardExpDate : string,
}

type cardDetails = cardNo & cardExpDate & { // using both type of prev
    cardName: string,
    cardActivationDate: string,
}

export {}

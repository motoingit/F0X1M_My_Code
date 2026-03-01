// Using the stable CDN for currency API
const BASE_URL = "https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies";

const dropdowns = document.querySelectorAll(".dropdown select");
const btn = document.querySelector("form button");
const fromCurr = document.querySelector(".from select");
const toCurr = document.querySelector(".to select");
const msg = document.querySelector(".msg");
const amountInput = document.querySelector(".amount input");

// Main function to initialize Dropdowns
export function setupApp(countryList) {
    for (let select of dropdowns) {
        for (let currCode in countryList) {
            let newOption = document.createElement("option");
            newOption.innerText = currCode;
            newOption.value = currCode;

            // Default selections
            if (select.name === "from" && currCode === "USD") {
                newOption.selected = "selected";
            } else if (select.name === "to" && currCode === "INR") {
                newOption.selected = "selected";
            }
            select.append(newOption);
        }

        // Listener to change flag when currency changes
        select.addEventListener("change", (evt) => {
            updateFlag(evt.target, countryList);
        });
    }

    // Listener for the Convert button
    btn.addEventListener("click", (evt) => {
        evt.preventDefault();
        getExchangeRate();
    });
}

// Function to update the Flag Image
function updateFlag(element, countryList) {
    let currCode = element.value;
    let countryCode = countryList[currCode];
    let newSrc = `https://flagsapi.com/${countryCode}/flat/64.png`;
    let img = element.parentElement.querySelector("img");
    img.src = newSrc;
}

// Function to Fetch and Display Exchange Rate
export async function getExchangeRate() {
    let amountVal = amountInput.value;
    
    // Validation: Check if empty or less than 1
    if (amountVal === "" || amountVal < 1) {
        amountVal = 1;
        amountInput.value = "1";
    }

    msg.innerText = "Getting exchange rate...";

    try {
        // Construct URL (lowercase is required for this API)
        const URL = `${BASE_URL}/${fromCurr.value.toLowerCase()}.json`;
        
        let response = await fetch(URL);
        
        if (!response.ok) {
            throw new Error("Network response was not ok");
        }

        let data = await response.json();
        let fromCode = fromCurr.value.toLowerCase();
        let toCode = toCurr.value.toLowerCase();
        
        let rate = data[fromCode][toCode];
        
        // Calculate final amount
        let finalAmount = (amountVal * rate).toFixed(2);
        
        msg.innerText = `${amountVal} ${fromCurr.value} = ${finalAmount} ${toCurr.value}`;
        
    } catch (error) {
        console.error("Error fetching data:", error);
        msg.innerText = "Error fetching exchange rates.";
    }
}
// ==================================================
// TIC TAC TOE - Beginner Friendly Logic
// ==================================================

// ---------- DOM SELECTION ----------
const gameCells = document.querySelectorAll(".cell");
const resetButton = document.getElementById("resetGameBtn");
const newGameButton = document.getElementById("newGameBtn");
const statusBox = document.getElementById("statusBox");
const statusMessage = document.getElementById("statusMessage");

// ---------- GAME STATE ----------
let isOTurn = true;
let gameActive = true;

// Winning patterns (index based)
const winningPatterns = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
];

// ---------- EVENT BINDING ----------
gameCells.forEach((cell, index) => {
    cell.addEventListener("click", () => handleCellClick(cell, index));
});

resetButton.addEventListener("click", resetGame);
newGameButton.addEventListener("click", resetGame);

// ---------- FUNCTIONS ----------

function handleCellClick(cell, index) {
    if (!gameActive) {
        console.warn("Game already ended.");
        return;
    }

    console.log(`Cell ${index} clicked`);

    cell.textContent = isOTurn ? "O" : "X";
    cell.disabled = true;

    if (checkWinner()) return;

    if (checkDraw()) {
        showStatus("It's a Draw!");
        console.log("Draw detected");
        gameActive = false;
        return;
    }

    isOTurn = !isOTurn;
}

function checkWinner() {
    for (let pattern of winningPatterns) {
        const [a, b, c] = pattern;

        const val1 = gameCells[a].textContent;
        const val2 = gameCells[b].textContent;
        const val3 = gameCells[c].textContent;

        if (val1 && val1 === val2 && val2 === val3) {
            showStatus(`Winner: ${val1}`);
            console.log(`${val1} wins`);
            gameActive = false;
            disableAllCells();
            return true;
        }
    }
    return false;
}

function checkDraw() {
    return [...gameCells].every(cell => cell.disabled);
}

function disableAllCells() {
    gameCells.forEach(cell => (cell.disabled = true));
}

function showStatus(message) {
    statusMessage.textContent = message;
    statusBox.classList.remove("hidden");
    alert(message); // beginner-friendly feedback
}

function resetGame() {
    console.log("Game reset");

    gameCells.forEach(cell => {
        cell.textContent = "";
        cell.disabled = false;
    });

    isOTurn = true;
    gameActive = true;
    statusBox.classList.add("hidden");
}

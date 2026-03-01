"""
Question : Sudoku Solve:
    Assumtions :
        - 0 for the null
        - 1 to 9 to the inputs are valid
    Constrains :
        - 9x9
"""

# 4x4 , 9x9, 16x16
#todo: for now 9x9 genration

def sampleSudoku() : #! static one input
    sudoku = [
        [8, 0, 7, 9, 3, 0, 0, 0, 0],
        [0, 4, 6, 0, 0, 2, 0, 5, 0],
        [0, 0, 0, 0, 0, 8, 7, 0, 2],
        [0, 0, 9, 7, 5, 0, 6, 0, 8],
        [0, 0, 0, 0, 1, 0, 3, 0, 0],
        [4, 5, 0, 0, 0, 6, 0, 0, 0],
        [0, 0, 0, 0, 6, 0, 0, 9, 0],
        [0, 0, 3, 0, 2, 0, 1, 0, 0],
        [0, 8, 1, 5, 0, 0, 0, 0, 4]
    ]
    return sudoku




def generateBoard() : #todo : static null board
    dimention = 9

    board = []
    for _ in range(1, dimention+1):
        row = []
        for _ in range (1, dimention+1):
            row.append(0)
        board.append(row)
    
    return board

def isCorrect(board, row, col, ch):
    for i in range(0, len(board)):
        if board[row][i] == ch: # col
            return False
        if board[i][col] == ch: # row check
            return False
    
    # grid calcu
    gRow = (row//3)*3; 
    gCol = (col//3)*3; 

    for i in range(3):
        for j in range(3):
            if board[gRow + i][gCol + j] == ch:
                return False
    return True
    

#todo : Recursive
def sudokuSolve(board, row, col) :
    if row == len(board):
        return True # so the all recursive call terminate sucessfully
    
    next_row, next_col = (row, col + 1) if col < 8 else (row + 1, 0)

    if board[row][col] != 0 :
        return sudokuSolve(board, next_row, next_col)

    for i in range (1 , 10) :
        val = i
        if isCorrect(board, row, col, val):
            board[row][col] = val
            if sudokuSolve(board, next_row, next_col) : 
                return True
            board[row][col] = 0 
            
    return False

# formatly print of the board        
def printBoard(board):
    print(end="\n")
    for row in board:
        print("| ", end = "")
        for ele in row:
            print(f"[{ele}] ", end = "")
        print("|")
    print(end="\n")

#todo: main
board = sampleSudoku()
print("Initial Board:")
printBoard(board)

if sudokuSolve(board, 0, 0):
    print("Solved Board:")
    printBoard(board)

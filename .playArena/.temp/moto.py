from typing import List


class Solution:
    def generateBoard(self, count: int) -> List[str]:
        board: List[str] = []
        for _ in range(count):
            oneRow = ""
            for _ in range(count):
                oneRow += "."
            board.append(oneRow)
        return board

    def isSafe(self, board: List[str], row: int, col: int) -> bool:
        n = len(board)
        # Check same column above
        for i in range(row):
            if board[i][col] == 'Q':
                return False

        # upper Left
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j -= 1

        # Upper Right
        i, j = row - 1, col + 1
        while i >= 0 and j < n:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j += 1

        return True

    # backtrack Function
    def solveQueenBack(self, board: List[str], solution: List[List[str]], row: int, nQueens: int):
        if row == len(board):
            solution.append(board.copy())
            return

        for col in range(nQueens):
            if self.isSafe(board, row, col):
                board[row] = board[row][:col] + "Q" + board[row][col+1:]
                self.solveQueenBack(board, solution, row + 1, nQueens)
                board[row] = board[row][:col] + "." + board[row][col+1:]
        return

    def solveNQueens(self, nQueens: int) -> List[List[str]]:
        board = self.generateBoard(nQueens)
        solution: List[List[str]] = []
        self.solveQueenBack(board, solution, 0, nQueens)
        return solution


if __name__ == '__main__':
    x = Solution()
    print(x.solveNQueens(4))

function verify_sudoku_board(board) {
    const rows = Array.from({ length: 9 }, () => new Set());
    const cols = Array.from({ length: 9 }, () => new Set());
    const boxes = Array.from({ length: 3 }, () =>
        Array.from({ length: 3 }, () => new Set())
    );

    for (let r = 0; r < 9; r++) {
        for (let c = 0; c < 9; c++) {
            const val = board[r][c];
            if (val === 0) continue;

            // For grids we can hash the r and c to check which grid element is in.
            const boxRow = Math.floor(r / 3);
            const boxCol = Math.floor(c / 3);

            if (rows[r].has(val)) return false;
            if (cols[c].has(val)) return false;
            if (boxes[boxRow][boxCol].has(val)) return false;

            rows[r].add(val);
            cols[c].add(val);
            boxes[boxRow][boxCol].add(val);
        }
    }

    return true;
}

const board =
    [[3, 0, 6, 0, 5, 8, 4, 0, 0],
    [5, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 8, 7, 0, 0, 0, 0, 3, 1],
    [1, 0, 2, 5, 0, 0, 3, 2, 0],
    [9, 0, 0, 8, 6, 3, 0, 0, 5],
    [0, 5, 0, 0, 9, 0, 6, 0, 0],
    [0, 1, 0, 0, 0, 0, 0, 7, 4],
    [0, 3, 0, 0, 0, 8, 2, 5, 0],
    [0, 0, 5, 2, 0, 6, 0, 0, 0]]

console.log(verify_sudoku_board(board));
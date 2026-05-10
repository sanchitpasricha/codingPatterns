function zero_striping(matrix) {

    if (!matrix || !matrix[0]) return;

    const m = matrix.length
    const n = matrix[0].length

    let first_row_has_zero = false
    for (let i = 0; i < n; i++) {
        if (matrix[0][i] == 0) {
            first_row_has_zero = true
            break
        }
    }
    let first_col_has_zero = false
    for (let i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            first_col_has_zero = true
            break
        }
    }

    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (first_row_has_zero) {
        for (let i = 0; i < n; i++) {
            matrix[0][i] = 0;
        }
    }

    if (first_col_has_zero) {
        for (let i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

const matrix = [[1, 2, 3, 4, 5],
[6, 0, 6, 9, 10],
[11, 12, 13, 14, 15],
[16, 17, 18, 19, 0]]

zero_striping(matrix)
console.log(matrix)
function isMatrixValid(matrix) {
    if (!matrix[0]) console.error(matrix, "has no first row.")
    const numfirstRowEntries = matrix[0].length
    for (let row of matrix) {
        if (row.length !== numfirstRowEntries) return false;
    }
    return true;
}

function areMatricesCompatible (matrixA, matrixB) {
    const numberOfColumnsA = matrixA[0].length
    const numberOfRowsB = matrixB.length

    return numberOfColumnsA == numberOfRowsB 
}

module.exports = function matrixMultiplier(matrixA, matrixB) {
    if (!isMatrixValid(matrixA) || !isMatrixValid(matrixA)) console.error("One or more of your matrices do not have the same number of entries per row.")
    if (!areMatricesCompatible(matrixA, matrixB)) console.error("There is a dimension error between these two matrices.")

    let resultantMatrix = new Array(matrixA.length)
    console.log(resultantMatrix)
    for (var rowIndex = 0; rowIndex < matrixA.length; ++rowIndex) {
        resultantMatrix[rowIndex] = new Array(matrixB[0].length)
        for (var colIndex = 0; colIndex < matrixB[0].length; ++colIndex) {
            resultantMatrix[rowIndex][colIndex] = 0
            for (var entryIndex = 0; entryIndex < matrixA[0].length; ++entryIndex) {
                resultantMatrix[rowIndex][colIndex] += matrixA[rowIndex][entryIndex] * matrixB[entryIndex][colIndex];
            }
        }
    }

    return resultantMatrix;
}
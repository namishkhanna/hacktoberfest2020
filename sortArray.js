module.exports = function sortArray(array, mode) {
    if (!array) console.error('Please provide an array')
    if (!mode) console.error('Please provide a mode of ascending or descending')
    
    return array.sort((a, b) => mode.toLowerCase() === 'ascending' ?  a - b : b - a)
}

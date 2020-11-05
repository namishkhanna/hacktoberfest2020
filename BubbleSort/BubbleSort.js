function randomArray(length) {
    let arr = new Array()
    for (let i = 0; i < length; i++) {
        arr[i] = Math.floor(Math.random() * 200)
    }
    return arr
}

function sort(arr) {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 1; j < arr.length; j++) {
            if (arr[j] < arr[j - 1]) {
                swap(arr, j, j - 1)
            }
        }
    }
}
function swap(arr, index1, index2) {
    let temp = arr[index1]
    arr[index1] = arr[index2]
    arr[index2] = temp
}

let arr = randomArray(10)
sort(arr)
console.log(arr)

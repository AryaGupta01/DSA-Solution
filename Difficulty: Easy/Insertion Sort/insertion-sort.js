//{ Driver Code Starts
// Driver code
const readline = require('readline');
const rl = readline.createInterface({input : process.stdin, output : process.stdout});

let inputLines = [];
let currentLine = 0;

rl.on('line', (line) => { inputLines.push(line.trim()); });

rl.on('close', () => { main(); });

function readLine() { return inputLines[currentLine++]; }

function main() {
    let tc = parseInt(readLine());
    while (tc > 0) {
        let arr = readLine().split(' ').map(Number);
        let ob = new Solution();
        ob.insertionSort(arr);
        console.log(arr.join(' '));
        console.log("~");
        tc--;
    }
}
// } Driver Code Ends


// User function Template for javascript

/**
 *
 * insert
 * @param {number[]} arr
 * @param {number} i
 *
 * insertionSort
 * @param {number[]} arr
 * @param {number} n
 */
class Solution {

    // Please change the array in-place
    insertionSort(arr) {
        // code here
        for(let i=0; i<arr.length;i++){
            let j=i;
            while(j>0 && arr[j]<arr[j-1]){
                let temp= arr[j]
                arr[j]=arr[j-1]
                arr[j-1]= temp
                j--;
            }
        }
    }
}
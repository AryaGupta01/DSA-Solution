//{ Driver Code Starts
// Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => { inputString += inputStdin; });

process.stdin.on("end", (_) => {
    inputString =
        inputString.trim().split("\n").map((string) => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

/* Function to print an array */
function printArray(arr, size) {
    let i;
    let s = "";
    for (i = 0; i < size; i++) {
        if (arr[i] === -0) arr[i] = 0;
        s += arr[i] + " ";
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine());
    for (let i = 0; i < t; i++) {
        let arr = readLine().trim().split(" ").map((x) => parseInt(x));
        let n = arr.length;
        let obj = new Solution();
        obj.quickSort(arr, 0, n - 1);
        printArray(arr, arr.length);
    }
}
// } Driver Code Ends


// User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} low
 * @param {number} high
 */

class Solution {
    swap(arr, i, j) {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    partition(arr, low, high) {
        // Your code here
        let pivot = arr[Math.floor((low+high)/2)];
        let i = low
        let j= high
        while(i<=j){
            while(arr[i]<arr[pivot]){
                i++;
            }
            while(arr[j]>arr[pivot]){
                j--;
            }
            if(i<j){
                this.swap(arr,i,j);
            }
            
            
        }
        this.swap(arr,low,high)
        return j;
    }

    quickSort(arr, low, high){
        // Your code here
    let pivot = arr[Math.floor((low + high) / 2)]; // Choose pivot as the middle element
    let i = low;
    let j = high;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            let temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j) {
        this.quickSort(arr, low, j);
    }
    if (i < high) {
        this.quickSort(arr, i, high);
    }
}
}
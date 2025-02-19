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
        ob.mergeSort(arr, 0, arr.length - 1);
        console.log(arr.join(' '));
        console.log("~");
        tc--;
    }
}
// } Driver Code Ends


// User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} l
 * @param {number} r
 */

class Solution {
    merge(arr,l,mid,r){
        let ans=[];
        let left = l;
        let right = mid+1;
        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
               ans.push(arr[left]);
               left++;
            }
            else{
                ans.push(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            ans.push(arr[left]);
            left++;
        }
        while(right<=r){
            ans.push(arr[right]);
            right++;
        }
        for(let i = l; i <= r; i++) {
            arr[i] = ans[i - l]
        }
        return ans;
    }
    mergeSort(arr, l, r) {
        // code here
        if(l>=r) return;
        let mid=Math.floor((l+r)/2);
        
        this.mergeSort(arr,l,mid);
        this.mergeSort(arr,mid+1,r);
        this.merge(arr,l,mid,r);
        return arr;
    }
}
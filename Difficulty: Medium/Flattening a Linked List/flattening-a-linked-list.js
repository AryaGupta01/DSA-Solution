//{ Driver Code Starts
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

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.bottom = null;
    }
}

function printList(head) {
    let result = [];
    while (head !== null) {
        result.push(head.data);
        head = head.bottom;
    }
    console.log(result.join(" "));
}

function createLinkedList(arr) {
    let dummy = new Node(0);
    let temp = dummy;
    for (let i = 0; i < arr.length; i++) {
        temp.next = arr[i];
        temp = temp.next;
    }
    return dummy.next;
}

function main() {
    let t = parseInt(readLine());
    for (let test = 0; test < t; test++) {
        const n = parseInt(readLine());
        const nodes = [];

        for (let i = 0; i < n; i++) {
            const values = readLine().split(" ").map(Number);
            let dummy = new Node(0);
            let temp = dummy;

            for (let val of values) {
                temp.bottom = new Node(val);
                temp = temp.bottom;
            }

            nodes.push(dummy.bottom);
        }

        const list = createLinkedList(nodes);
        const solution = new Solution();
        const flattenedList = solution.flatten(list);
        printList(flattenedList);
        console.log("~");
    }
}
// } Driver Code Ends


// User function Template for javascript

/*LINKED LIST NODE
class Node {
  constructor(x){
    this.data = x;
    this.next = null;
    this.bottom = null;
  }
}
*/

/**
 * @param {Node} head
 * @return {Node}
 */

class Solution {
    flatten(root) {
        // your code here
        let arr =[];
        let temp = root;
        while(temp){
            let temp2 = temp;
            while(temp2){
                arr.push(temp2.data);
                temp2=temp2.bottom;
            }
            temp=temp.next;
        }
         arr.sort((a, b) => a - b);
        if(arr.length==0) return null;
        let head = new Node(arr[0]);
        temp = head;
        for(let i=1; i<arr.length;i++){
            let newNode = new Node(arr[i]);
            temp.bottom= newNode;
            temp = temp.bottom;
        }
        return head;
    }
}
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        
        int n = arr.size();
        
        //since we wanna find the min cost will maintain
        //a priority queue to extract the two min eles of the array
        //everytime and connect them
        
        
        //time --> O(nlogn)
        //space --> O(n)
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        long long minCost = 0;
        while(pq.size() != 1){
            long long minEle = pq.top();
            pq.pop();
            long long secMinEle = pq.top();
            pq.pop();
            
            //connect these two ropes with length minEle and secMinEle
            long long cost = minEle + secMinEle;
            minCost += cost;
            pq.push(cost);
        }
        
        return minCost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends
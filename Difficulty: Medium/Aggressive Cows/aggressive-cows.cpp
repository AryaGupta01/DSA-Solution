//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    bool isP(int diff, int n, int k, vector<int> &arr){
        int cnt=1;
        int prev=arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-prev>=diff){
                cnt++;
                if(cnt==k) return 1;
                prev=arr[i];
            }else{
                continue;
            }
        }
        return 0;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int lo=0;
        int hi=stalls[n-1]-stalls[0];
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isP(mid, n, k, stalls)){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return lo-1;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        return solve(stalls.size(), k, stalls);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
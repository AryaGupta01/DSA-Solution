//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        map<int,int> freq;
        for (int i=0;i<=k;i++){
            freq[arr[i]]++;
            if (freq[arr[i]]>1) return true;
        }
        for (int i=k+1;i<arr.size();i++){
            freq[arr[i-k-1]]--;
            freq[arr[i]]++;
            if (freq[arr[i]]>1) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
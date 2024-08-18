//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        long long sum=0;
        for(int i=0; i<arr.size(); i++){
            sum =sum+(arr[i]);
        }
        if(sum%2!=0){
            return false;
        }
        long long temp=0;
        for(int i=0; i<arr.size();i++){
            temp+=arr[i];
            if(temp==sum/2){
                return true;
            }
        }
        return false;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        queue<int>pos;
        queue<int>neg;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                neg.push(arr[i]);
            }
            else{
                pos.push(arr[i]);
                
            }
        }
        while(!pos.empty() || !neg.empty()){
            if(!pos.empty()){
                ans.push_back(pos.front());
                pos.pop();
            }
            if(!neg.empty()){
                ans.push_back(neg.front());
                neg.pop();
            }
        }
        for(int i=0; i<arr.size();i++){
            arr[i]=ans[i];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
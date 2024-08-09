//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        long x=1000000007;
        long sum=0;
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size(); i++){
              arr[i]=((arr[i]%x)*i)%x;
            sum=((sum%x)+arr[i])%x;
        }
        
        return  sum%x;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int mod=1e9+7;
        sort(arr.begin(),arr.end());
        int pos=0;
        int neg=0;
        int zero=0;
        long long int posmul=1;
        long long int negmul=1;
        long long int ans=1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0)
            {
                negmul=(negmul*arr[i])%mod;
                neg++;
            }
            else if(arr[i]==0)
            {
                zero++;
            }
            else{
                posmul=(posmul*arr[i])%mod;
                pos++;
            }
        }
        if(pos>0)
        {
            ans=(ans*posmul)%mod;
        }
        if(neg>0)
        {
            if(neg==1)
            {
                if(pos>0)return ans;
                else if(zero>0){
                    return 0;
                }
                else{
                    return arr[0];
                }
            }
            if(neg%2==0)
            {
                ans=(ans*negmul)%mod;
                return ans;
            }
            else{
                for(int i=0;i<neg-1;i++)
                {
                    ans=(ans*arr[i])%mod;
                }
                return ans;
            }
        }
        if(pos==0 && neg==0)return 0;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
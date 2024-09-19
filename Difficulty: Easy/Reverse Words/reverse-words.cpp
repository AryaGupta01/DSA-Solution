//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stack<string>s;
        string temp;
        int i=0;
        while(i<str.size()){
            while(i<str.size() && str[i]!='.'){
                temp+=str[i];
                i++;
            }
            // if(str[i]=='.'){
                i++;
                s.push(temp);
                temp="";
            
        }
        string ans="";
        while(!s.empty()){
            ans+=s.top();
            // ans+=".";
            s.pop();
            if(!s.empty()){
                ans+=".";
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
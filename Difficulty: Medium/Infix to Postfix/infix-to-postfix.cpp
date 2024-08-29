//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string ans;
        int i=0;
        while(i<s.size()){
            char c= s[i];
            if(c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9'){
                ans+=c;
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(st.top()!='(' && !st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && prec(c)<=prec(st.top())){
                    ans+=st.top();
                    st.pop();
                }
             
                st.push(c);
            }
            i++;
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
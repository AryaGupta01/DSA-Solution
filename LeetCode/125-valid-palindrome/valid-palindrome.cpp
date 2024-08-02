class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        char temp;
        for(int i=0; i<s.length();i++){
            if(s[i]>='a' && s[i]<= 'z'){
                ans.push_back(s[i]);
            }
            else if(s[i]>='A' && s[i] <= 'Z'){
                temp=s[i];
                ans.push_back(s[i]-'A'+'a');
            }
            else if(s[i]>='0' && s[i] <= '9'){
                // temp=s[i];
                ans.push_back(s[i]);
            }
            
        }
        int len =ans.size();
        for(int i=0; i<len/2;i++){
            if(ans[i] != ans[len-i-1]){
                return 0;
            }
        }
        return 1;
        
    }
};
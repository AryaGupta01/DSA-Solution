class Solution {
public:
    bool isPalindrome(int x) {
        long ans=0;
        long y=x;
        while(y>0){
            ans=(ans*10)+(y%10);
            y=y/10;
        }
        if(ans==x) return true;
        return false;
    }
};
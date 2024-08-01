class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int count =0;
        for(int i=0; i<details.size();i++){
            string a="";
            a=details[i];
            char tens = a[11];
            char ones = a[12];
            if (tens > '6' || (tens == '6' && ones > '0')) {
               count++;
            }
        }
        return count;
    }
};
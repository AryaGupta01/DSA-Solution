class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum=0;
        int n=skill.size();
        for(int i=0;i<skill.size();i++){
            sum=sum+skill[i];
        }
        if (sum%(n/2)!=0) return -1;
        int skillValue=sum/(n/2);
        sort(skill.begin(),skill.end());
        long long chemistry=0;
        long long l,r;
        for(int i=0;i<(n/2);i++){
            l=skill[i];
            r=skill[n-1-i];
            if(l+r!=skillValue) return -1;
            chemistry=chemistry+(l*r);
        }

        return chemistry;

        // return 0;
    }
};
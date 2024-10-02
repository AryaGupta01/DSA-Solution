class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp= arr;
        unordered_map<int, int> valueToRank;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        for(int i=0; i<temp.size();i++){
            valueToRank[temp[i]]=i+1;
        }
        for(int i=0; i<arr.size();i++){
            arr[i]=valueToRank[arr[i]];
        }
        return arr;

    }
};
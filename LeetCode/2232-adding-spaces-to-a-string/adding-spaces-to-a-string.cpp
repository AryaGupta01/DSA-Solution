class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
int start = 0;

for (int space : spaces) {
    result += s.substr(start, space - start) + " ";
    start = space;
}
result += s.substr(start);
return result;
    }
};
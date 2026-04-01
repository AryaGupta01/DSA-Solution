class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int, int, char, int>> robots;
        
        // Store (position, health, direction, original index)
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st; // store indices of robots in 'robots'
        
        for (int i = 0; i < n; i++) {
            auto& [pos, health, dir, idx] = robots[i];
            
            if (dir == 'R') {
                st.push(i);
            } else {
                // dir == 'L'
                while (!st.empty() && health > 0) {
                    int topIdx = st.top();
                    auto& [pos2, health2, dir2, idx2] = robots[topIdx];
                    
                    if (health2 < health) {
                        // R robot dies
                        st.pop();
                        health--;
                        health2 = 0;
                    } 
                    else if (health2 > health) {
                        // L robot dies
                        health2--;
                        health = 0;
                        break;
                    } 
                    else {
                        // both die
                        st.pop();
                        health2 = 0;
                        health = 0;
                        break;
                    }
                }
            }
        }
        
        // Collect survivors
        vector<pair<int, int>> result; // {original index, health}
        
        for (auto& [pos, health, dir, idx] : robots) {
            if (health > 0) {
                result.push_back({idx, health});
            }
        }
        
        // Sort by original index
        sort(result.begin(), result.end());
        
        vector<int> ans;
        for (auto& [idx, health] : result) {
            ans.push_back(health);
        }
        
        return ans;
    }
};
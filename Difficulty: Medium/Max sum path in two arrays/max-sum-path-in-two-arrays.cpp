//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int result = 0;

        // Traverse both arrays simultaneously
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            } 
            else if (arr1[i] > arr2[j]) {
                sum2 += arr2[j++];
            } 
            else {  // When arr1[i] == arr2[j]
                // Add maximum sum of both paths till now and the common element
                result += max(sum1, sum2) + arr1[i];
                // Reset sums
                sum1 = 0;
                sum2 = 0;
                // Move both pointers
                i++;
                j++;
            }
        }

        // If there are remaining elements in arr1
        while (i < arr1.size()) {
            sum1 += arr1[i++];
        }

        // If there are remaining elements in arr2
        while (j < arr2.size()) {
            sum2 += arr2[j++];
        }

        // Add the maximum of the remaining sums to the result
        result += max(sum1, sum2);

        return result;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
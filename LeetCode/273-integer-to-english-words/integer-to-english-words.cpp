#include <string>  
#include <vector>  
#include <algorithm> // For std::remove_if  

class Solution {  
public:  
    std::string numberToWords(int num) {  
        if (num == 0) return "Zero";  

        std::vector<std::string> below_20 = {  
            "", "One", "Two", "Three", "Four", "Five",   
            "Six", "Seven", "Eight", "Nine", "Ten",   
            "Eleven", "Twelve", "Thirteen", "Fourteen",   
            "Fifteen", "Sixteen", "Seventeen", "Eighteen",   
            "Nineteen"  
        };  
        std::vector<std::string> tens = {  
            "", "", "Twenty", "Thirty", "Forty",   
            "Fifty", "Sixty", "Seventy", "Eighty",   
            "Ninety"  
        };  
        std::vector<std::string> thousands = {  
            "", "Thousand", "Million", "Billion"  
        };  

        std::string words;  
        int i = 0;  

        while (num > 0) {  
            if (num % 1000 != 0) {  
                words = helper(num % 1000, below_20, tens) + thousands[i] + " " + words;  
            }  
            num /= 1000;  
            i++;  
        }  

        // Trim the trailing space  
        if (!words.empty()) {  
            words.erase(words.find_last_not_of(' ') + 1);  
        }  

        return words;  
    }  

private:  
    std::string helper(int num, const std::vector<std::string>& below_20, const std::vector<std::string>& tens) {  
        std::string words;  

        if (num >= 100) {  
            words += below_20[num / 100] + " Hundred ";  
            num %= 100;  
        }  
        if (num >= 20) {  
            words += tens[num / 10] + " ";  
            num %= 10;  
        }  
        if (num > 0) {  
            words += below_20[num] + " ";  
        }  

        return words;  
    }  
};
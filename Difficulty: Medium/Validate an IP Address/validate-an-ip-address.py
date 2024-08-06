#User function Template for python3
class Solution:
    def isValid(self, s):
        import re
        digits = r"0|(?:[1-9]\d{0,2})"
        match = re.match(
            r"^({digits})\.({digits})\.({digits})\.({digits})$".format(digits=digits), s)
        if match is None:
            return False
        for i in range(1, 5):
            if not 0 <= int(match.group(i)) <= 255:
                return False
        return True


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        ob = Solution()
        if (ob.isValid(s)):
            print("true")
        else:
            print("false")

# } Driver Code Ends
#  最长回文子串

> language : Cpp

这题要用动态规划思想，要找的是回文串，它之所以是回文串，就要满足：`设Sub[i:j]是从i~j的子串 \`
$$
S[i] == S[j](S是给定字符串) ,\\

当Sub[i:j] 是回文时，\\
Sub[i+1 : j-1]一定也满足回文。\\
\\
状态转移方程：\\
Sub[i:j] = P[i+1:j-1] \land (S[i] == S[j])
$$



```cpp
string longestPalindrome(string s) {
    size_t n{s.size()};
    int maxLength{1},begin{0};
    
    vector<vector<int>> dp(n, vector<int> (n));
    
    
```

二位数组如下表示：
$$
条件：\\
s.size() = 1 \quad 即为回文\\
maxLength = j - i + 1
$$
假设`s = "ababc"`则有以下内容( 行数为 i，列数为 j )

|      | 0    | 1    | 2    | 3    | 4    |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 0    | 1    | 0    | 1    | 0    | 1    |
| 1    |      | 1    | 0    | 1    | 0    |
| 2    |      |      | 1    | 0    | 1    |
| 3    |      |      |      | 1    | 0    |
| 4    |      |      |      |      | 1    |



```cpp
    for (int i = n - 1; i >= 0; i--) { //从后往前

        for (int j = i; j < n; j++) {
			//即需要查找左下角是否为1，并判断当前字符串长度是否>1
            if (s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1]) ){ 
                dp[i][j] = true; //=1

                if (j - i + 1 >= maxLength){
                    begin = i;
                    maxLength = j - i + 1;
                }
            }
        }
    }
    return s.substr(begin,maxLength);
}
```
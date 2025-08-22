// 10. Regular Expression Matching
//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
//
class Solution {
public:
    bool isMatch(string s, string p) { return dfs(0, 0, s, p); }
    bool dfs(int i, int j, string &s, string &p) {
        if (i >= s.length() && j >= p.length())
            return true;
        if (j >= p.length())
            return false;
        bool match = (i < s.length() && ((s[i] == p[j]) || p[j] == '.'));
        if ((j + 1) < p.length() && p[j + 1] == '*') {
            return ((dfs(i,j+2,s,p)||(match && dfs(i+1,j,s,p))));
        }
        if (match)
            return dfs(i + 1, j + 1, s, p);
        return false;
    }
};

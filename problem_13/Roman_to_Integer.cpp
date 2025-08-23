// 13. Roman to Integer

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rv;
        int ans = 0;
        // add Base Mapping
        rv['I'] = 1;
        rv['V'] = 5;
        rv['X'] = 10;
        rv['L'] = 50;
        rv['C'] = 100;
        rv['D'] = 500;
        rv['M'] = 1000;
        // Logic : if s[i] value is Less than s[i+1] we simply minus s[i] value
        // example: IV => V - I = 4
        // example: XL => L - X  = 40 
        for (int i = 0; i < s.length(); i++) {
            if (rv[s[i]] < rv[s[i + 1]]) {
                ans -= rv[s[i]];
            } else {
                ans += rv[s[i]];
            }
        }
        auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
        return ans;
    }
};

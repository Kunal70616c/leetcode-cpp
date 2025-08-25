// 12. Integer to Roman

class Solution {
public:
    string intToRoman(int num) {
        multimap<int, string, greater<int>> rv = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        string res = "";
        for (auto& p : rv) {
            if (num / p.first) {
                int count = num / p.first;
                for (int i = 0; i < count; i++) {
                    res += p.second;
                }
                num = num % p.first;
            }
        }
        return res;
    }
};

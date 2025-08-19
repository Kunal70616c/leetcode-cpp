// 9. Palindrome Number
//Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution {
public:
    bool isPalindrome(int x) {
        long int og = x;
        long int nn = 0;
        while(x!=0){
            nn *=10; 
            nn += (x % 10);
            x = x/10;
        }
        if(nn == og && nn >= 0){
            return true;
        }
        else{
            return false;
        }
        
    }
};



// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.
// **Note: challanging one practice another time

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        // Obtain lengths of strings after alteration        
        int k = backspace(s);
        int p = backspace(t);

        // Length do not match
        if (k != p) return false;

        // Find discrepancies between the two strings
        for (int i = 0; i < k; i++) {
            if (s[i] != t[i]) return false;
        }

        // Found match
        return true;
    }
    
    
    // Modify previous if there is a '#'
    // instead of deleting the character we can 
    // alter strings such that if 2 strings are 
    // similar they should have the same alteration
    int backspace(string& s){
        /*
            whole string: ab#c
            a k=0, k=1
            ab k=1, k=2
            ab# k=2, k=1
            ac#
        */

        int k = 0;
        for(char c:s){
            if(c!='#'){
                // Add c to s[k] then increment
                s[k++] = c;
            } else if (k>0){
                // Go back one char and modify if not #
                k--;
            }
        }

        return k;
    }

};














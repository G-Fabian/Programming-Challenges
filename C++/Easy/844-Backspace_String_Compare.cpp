// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.4

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        char* ptr1 = nullptr;
        char* ptr2;

        s = eraseIt(s);
        t = eraseIt(t);

        cout<<s<<" "<<t<<endl;

        if(s==t) return true;
        else return false;
    }

    string eraseIt(string s){
        
        for(int i=0; i<s.size()-1; i++){

            if(s[i+1]=='#'){
                s.erase (i,2);
            }
        }
        
        return s;
    }

};


// s = "a#c", t = "b"

// a #
// c end
// return c


// b end
// return b

// (ab)##
// a(b#)#
// (a#)
// return nothing

// (c#)d#
// (d#)
// return nothing
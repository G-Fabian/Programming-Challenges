class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int k = backspace(s);

        cout<<s<<endl;

        int p = backspace(t);

        cout<<t<<endl;

        if (k != p) return false;

        for (int i = 0; i < k; i++) {
            if (s[i] != t[i]) return false;
        }

        return true;
    }

    int backspace(string& s){

        int k = 0;

        /*
        whole string: ab#c
        a k=0, k=1
        ab k=1, k=2
        ab# k=2, k=1
        ac#

        */

        for(char c:s){
            if(c!='#'){
                s[k++] = c;
            } else if (k>0){
                k--;
            }
        }

        return k;
    }

};


// s = "a#c", t = "b"

// a #
// # c
// c end
// return c


// b end
// return b

// ab##
// ab##
// 
// return nothing

// (c#)d#
// (d#)
// return nothing

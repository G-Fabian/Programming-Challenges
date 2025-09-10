// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.4

// Constraints:

// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string a = backspace(s);
        string b = backspace(t);

        cout<<"Final s: "<< a <<endl;
        cout<<"Final t: "<< b <<endl;
        if(a==b) return true;
        else return false;
    }

    string backspace(string s){

        string::iterator it = s.begin();
        string::iterator it2 = s.begin();
        
        it2++;

        string test;
        while(it != s.end()){
            cout<<"it: "<<*it<<endl;
            cout<<"it2: "<<*it2<<endl;

            if(*it == '#' || *it2 == '#')
                cout<<"backspace"<<endl;
            else
                test+=*it;

            it++;
            it2++;
        }

        return test;
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
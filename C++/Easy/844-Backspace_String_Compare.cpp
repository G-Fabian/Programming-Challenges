class Solution {


// Possible solution go backwards
public:
    bool backspaceCompare(string s, string t) {
        
        string a = backspace(s);
        string b = backspace(t);

        cout<<"Final s: "<< a <<endl;
        cout<<"Final t: "<< b <<endl;
        if(a==b) return true;
        else return false;
        // return true;
    }

    string backspace(string s){

        string::iterator it = s.begin();
        string::iterator it2 = s.begin();
        
        it2++;

        string test = s;
        while(it != s.end() && it2 != s.end()){
            cout<<"Debug: "<<*it<< " " <<*it2<<endl;

            if(*it2 == '#'){
                s.erase(it2);
                cout<<"a: "<<s<<endl;
                s.erase(it);
                cout<<"b: "<<s<<endl;
                it--;
                it2--;
            }else{
                it++;
                it2++;
            }
        }

        return s;
    }

};

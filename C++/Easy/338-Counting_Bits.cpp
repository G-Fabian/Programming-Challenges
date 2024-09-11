// 338. Counting Bits
// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> a (n+1);

        for(int i=0; i<=n; i++){
            int count=0;
            int num=i;

            // & Calculation determines to continue the loop
            // since each binary number increases by only 1
            // we count each time the num decrease until it hits num=0
            // were there is no ones. 
            while(num!=0){
                num = (num&(num-1));
                count++;
            }

            // Store the count of current iterator
            a[i] = count;
        }

        // Old Solution
        // convert2binary(n,a);
        // reverse(a.begin(), a.end());

        return a;
    }


    // Old solution
    int convert2binary(int n, vector<int>& a){
       
        int remainder;
        int quotient = n;

        // Base case
        if(n<0){ return 0; }

        int total=0;
        while(quotient != 0){
            remainder = quotient % 2;
            if(remainder==1){ total++; }
            quotient = quotient/2;
        }

        a.push_back(total);

       return convert2binary(n-1, a);
    }

    
};
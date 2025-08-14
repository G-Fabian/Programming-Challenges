// You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

// Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        // Binary Seach with a modification to only find smallest character 
        // in letters that is lexicographically greater than target

        int mid;
        int low = 0;
        int high = letters.size() - 1;
        int pos = -1;

        while(low<=high){
            // Calculate the middle of letters[] index
            mid = (low + high) / 2;

            if(letters[mid] > target){
                high = mid - 1;  // Remove upper half of array
                pos = mid;       // Update current postion of letter > target
            }
            else{
                low = mid + 1;   // Remove lower half of array
            }
        }

        // If solution exists return letter else return letters[0]
        return (pos != -1) ? letters[pos] : letters[0];
    }
};

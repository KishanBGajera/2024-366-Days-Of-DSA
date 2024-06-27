#include <iostream>
using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int longestCommonPrefixLength = 0;
        int s1Len = s1.length(), s2Len = s2.length(), s3Len = s3.length();

        for(int i = 0; i < s1Len; i++){
            if(s1[i] == s2[i] && s2[i] == s3[i]){
                longestCommonPrefixLength++;
            }
            else{
                break;
            }
        }

        return longestCommonPrefixLength ? s1Len + s2Len + s3Len - 3 * longestCommonPrefixLength : -1;
    }
};
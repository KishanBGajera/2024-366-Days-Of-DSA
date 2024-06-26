#include<iostream>
// #include<stdlib.h>

int min(int a, int b, int c){
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

void printArray(int **arr, int r, int c){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}

class Solution{
public:
    int minDistance(std::string word1, std::string word2){
        int len1 = (int)word1.size();
        int len2 = (int)word2.size();

        int **dp = (int**)malloc(sizeof(int*) * (len1 + 1));
        for (int i = 0; i <= len1; i++)
        {
            dp[i] = (int*)malloc(sizeof(int) * (len2 + 1));
        }
        
        // Initialize dp array
        for(int i = 0; i <= len1; i++)
            dp[i][len2] = len1 - i;
        for(int j = 0; j <= len2; j++)
            dp[len1][j] = len2 - j;

        for(int i = len1 - 1; i >= 0; i--){
            for(int j = len2 - 1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]);
                }
            }
        }

        printArray(dp, len1 + 1, len2 + 1);

        int result = dp[0][0];

        // Free allocated memory
        for (int i = 0; i <= len1; i++)
        {
            free(dp[i]);
        }
        free(dp);

        return result;
    }
};

int main(){
    Solution s = Solution();
    std::cout << s.minDistance("abd", "acd") << std::endl << std::endl;
    std::cout << s.minDistance("apple", "app") << std::endl << std::endl;
    std::cout << s.minDistance("kishan","gajera") << std::endl;
    return 0;
}

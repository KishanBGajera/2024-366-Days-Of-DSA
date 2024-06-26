#include <iostream>
using namespace std;

class Solution {
public:
    string encode(string en){
        int count = 1;
        string new_en = "";

        for(int i = 0; i < en.size(); i++){
            if(i == en.size() - 1 || en[i] != en[i + 1]){
                new_en += to_string(count);
                new_en += en[i];
                count = 1;
            }
            else{
                count++;
            }
        }

        return new_en;
    }

    string countAndSay(int n) {
        string prev, current;
        prev = '1';    

        for(int i = 1; i < n; i++){
            current = this->encode(prev);
            prev = current;
        }

        return prev;
    }
};
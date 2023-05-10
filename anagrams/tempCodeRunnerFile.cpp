#include <iostream>
#include <map>
#include <string>

bool isAnagram(const std::string& str1, const std::string& str2)
{
    std::map<char, int> counts;

    for (char c : str1){
        counts[c]++;
    }
    for (char c : str2){
        counts[c]--;
    }


    for(auto pair : counts) {
        if(pair.second != 0){
            return false;
        }
    }


    return true;
}


int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    if(isAnagram(str1, str2)) {
        std::cout << str1 << " and " << str2 << " are anagrams" << "\n";
    }else {
        std::cout << str1 << " and " << str2 << " are not anagrams" << "\n";
    }


    return 0;
}
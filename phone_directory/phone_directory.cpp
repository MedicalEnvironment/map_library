#include <iostream>
#include <string>
#include <map>
#include <vector>

// use multimap to allow multiple entries for same last name
std::multimap<std::string, std::string> phone_to_name;
std::multimap<std::string, std::string> name_to_phone;

void addEntry(const std::string& number, const std::string& name) {
    phone_to_name.insert({number, name});
    name_to_phone.insert({name, number});
}

void findName(const std::string& number) {
    auto range = phone_to_name.equal_range(number);
    for(auto i = range.first; i != range.second; ++i) {
        std::cout << i->second << '\n';
    }
}

void findNumbers(const std::string& name) {
    auto range = name_to_phone.equal_range(name);
    for(auto i = range.first; i != range.second; ++i) {
        std::cout << i->second << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::string command;
    while(std::cin >> command) {
        if(command.size() == 8) {  // if it's a phone number
            std::string name;
            std::cin >> name;
            addEntry(command, name);
        } else if(command[2] == '-') {  // if it's a phone number
            findName(command);
        } else {  // if it's a name
            findNumbers(command);
        }
    }

    return 0;
}

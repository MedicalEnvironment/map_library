#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<std::string, int> queue;
    std::string input;

    while(std::cin >> input) {
        if(input == "Next") {
            if(!queue.empty()) {
                std::cout << queue.begin()->first << "\n";
                if (--queue.begin()->second == 0) {
                    queue.erase(queue.begin());
                }
            } else {
                std::cout << "No one in the queue!\n";
            }
        } else {
            queue[input]++;
        }
    }

    return 0;
}

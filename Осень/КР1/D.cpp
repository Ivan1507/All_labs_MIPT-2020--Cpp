#include <iostream>
#include <string>
#include <regex>

std::string GetRegex() {
	std::string pat="123";
	std::regex rs{pat};
	return static_cast<std::string>(rs);
}
int main() {
    std::string div5reg = GetRegex();
    std::regex div5(div5reg, std::regex_constants::nosubs | std::regex_constants::ECMAScript);
    if(!std::regex_match("1111", div5)) { // 1111bin = 15dec
        std::cout << "Test failed\n";
    
    } else {
        std::cout << "Test passed\n";
    }
}

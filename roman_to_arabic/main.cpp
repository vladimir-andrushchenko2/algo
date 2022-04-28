#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <regex>

const std::unordered_map<char, int> roman_symbol_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

bool IsValidRomanNumeral(const std::string& roman) {
    const std::regex roman_regex("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
    
    return std::regex_match(roman, roman_regex);
}

size_t RomanToArabic(std::string_view roman) {
    size_t output = roman_symbol_to_int.at(roman.back());
    
    int reverse_index = static_cast<int>(roman.size()) - 2;
    
    for (; reverse_index >= 0; --reverse_index) {
        int val = roman_symbol_to_int.at(roman[reverse_index]);
        
        if (val * 4 < output) {
            output -= val;
        } else {
            output += val;
        }
    }
    
    return output;
}

int main() {
    std::string line;
    
    std::getline(std::cin, line);
    
    if (IsValidRomanNumeral(line)) {
        std::cout << RomanToArabic(line);
    } else {
        std::cout << -1;
    }
    
    std::cout << '\n';
    
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

int ReadInt(std::istream& input) {
    int value;

    input >> value >> std::ws;

    return value;
}

std::vector<int> ReadValues(std::istream& input, int n_values) {
    std::vector<int> output;

    for (int i = 0; i < n_values; ++i) {
        input >> output.emplace_back();
    }

    return output;
}

int CountDifferencesDivisible(const std::vector<int>& values) {
    std::unordered_map<int, int> remainder_to_count;
    
    static constexpr int kDivider = 200;
    
    for (const auto& val : values) {
        ++remainder_to_count[val % kDivider];
    }
    
    size_t output{};
    
    for (const auto& [remainder, count] : remainder_to_count) {
        if (count > 1) {
//            ___n!___
//            r!(n−r)!
            output += (count * (count - 1)) / 2;
        }
    }
    
    return output;
}

int main(int argc, const char * argv[]) {
    std::cout << CountDifferencesDivisible(ReadValues(std::cin, ReadInt(std::cin))) << '\n';
    
    return 0;
}

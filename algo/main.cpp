#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

    // input >> std::ws;

    return output;
}

int MaxSumOfCardsTakenFromSides(const std::vector<int>& cards, int cards_can_be_taken) {
    int max = std::accumulate(cards.begin(), cards.begin() + cards_can_be_taken, 0);

    int current_max = max;

    int j = static_cast<int>(cards.size()) - 1;
    
    for (int i = cards_can_be_taken - 1; i >= 0; --i, --j) {
        current_max = current_max - cards.at(i) + cards.at(j);

        max = std::max(max, current_max);
    }

    return max;
}

int main() {
    int values_size = ReadInt(std::cin);
    
    int k_cards_can_be_taken = ReadInt(std::cin);

    std::vector<int> values = ReadValues(std::cin, values_size);

    int max = MaxSumOfCardsTakenFromSides(values, k_cards_can_be_taken);

    std::cout << max << '\n';
}

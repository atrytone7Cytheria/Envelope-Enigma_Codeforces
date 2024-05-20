#include <iostream>
#include <vector>
#include <unordered_set>

bool isChallengeSolvable(int n, const std::vector<int>& permutation) {
    std::unordered_set<int> visited;
    
    for (int i = 0; i < 2 * n; ++i) {
        if (visited.find(i + 1) != visited.end()) {
            continue;  // Already visited
        }
        
        int current = permutation[i] - 1;
        int length = 0;
        while (visited.find(current + 1) == visited.end()) {
            visited.insert(current + 1);
            current = permutation[current] - 1;
            ++length;
        }
        
        if (length > n) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> permutation(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        std::cin >> permutation[i];
    }
    
    if (isChallengeSolvable(n, permutation)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}

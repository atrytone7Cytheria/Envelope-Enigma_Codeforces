#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

// Function to generate a random permutation
vector<int> generatePermutation(int n) {
    vector<int> permutation(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        permutation[i] = i + 1;
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(permutation.begin(), permutation.end(), g);
    return permutation;
}

// Function to print a test case
void printTestCase(int n) {
    vector<int> permutation = generatePermutation(n);
    cout << n << endl;
    for (int i = 0; i < 2 * n; ++i) {
        if (i > 0) cout << " ";
        cout << permutation[i];
    }
    cout << " " << "\n";
}

int main() {
    srand(time(0));
    int t =30;  // Number of test cases
    
    for (int i = 0; i < t; ++i) {
        int n = rand() % 100 + 1;  // Random n from 1 to 100
        printTestCase(2*n);
    }
    return 0;
}

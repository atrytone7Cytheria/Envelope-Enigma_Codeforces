#include <iostream>
#include <vector>
#include <set>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();

    vector<int> permutation(2 * n);
    set<int> seen;
    for (int i = 0; i < 2 * n; i++) {
        permutation[i] = inf.readInt(1, 2 * n, "permutation");
        inf.readSpace();
        ensuref(!seen.count(permutation[i]), "Duplicate number in permutation!");
        seen.insert(permutation[i]);
    }
    inf.readEoln();
    ensuref(static_cast<int>(seen.size()) == 2 * n, "Invalid permutation length!");

    inf.readEof();
}

Editorial: Mark Rober's IIT Kanpur Puzzle Challenge
Problem Statement:
In the "Mark Rober's IIT Kanpur Puzzle Challenge," each team of 2n students receives T-shirts numbered from 1 to 2n. There are also 2n envelopes, each containing a letter with a number from 1 to 2n. The letters are distributed randomly. Each team member gets n attempts to find the envelope with their number without communicating with other team members after their tries. The team wins if every member finds their corresponding envelope.

Input:

An integer n (1 ≤ n ≤ 100,000) representing half the number of students.
A permutation of integers 𝑝 of length 2n representing the numbers in the envelopes.
Output:
Print "YES" if it's possible for all team members to find their envelopes; otherwise, print "NO".

Solution Approach:

To determine if the challenge is solvable, we need to analyze the cycles in the given permutation. Each cycle represents a sequence of envelopes that a person would traverse in their attempts. The key observation here is that for the challenge to be solvable, each cycle in the permutation must have a length that does not exceed 

Here's a step-by-step breakdown of the approach:

Read Input:
Read the integer n
Read the permutation of integers.

Cycle Detection:

Traverse the permutation to detect cycles.For each number, follow the chain of indices until you return to the starting number to form a cycle.Track visited numbers to avoid redundant work.
Cycle Length Check:

Ensure that each detected cycle has a length of at most 𝑛. If any cycle exceeds this length, the challenge is not solvable.
Output Result:

Print "YES" if all cycles are of length 𝑛 or less; otherwise, print "NO".
Implementation
Below is the C++ implementation of the solution:


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isChallengeSolvable(int n, const vector<int>& permutation) {
    unordered_set<int> visited;

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
    cin >> n;

    vector<int> permutation(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> permutation[i];
    }

    if (isChallengeSolvable(n, permutation)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


Explanation:
Reading Input:We read the integer 𝑛 and the permutation of 2n numbers.

Cycle Detection:

We use an unordered set visited to keep track of numbers we have already processed.
For each number, we trace the cycle by following the indices defined by the permutation until we return to the starting number.
Cycle Length Check:

For each detected cycle, we ensure that its length does not exceed 𝑛.If any cycle exceeds 𝑛, we return "NO".
Output:

If all cycles have valid lengths, we return "YES".
This approach ensures an efficient solution with a time complexity of 𝑂(2𝑛), which is sufficient given the constraints. By carefully managing cycles and their lengths, we can determine whether the team can successfully find all their corresponding envelopes.
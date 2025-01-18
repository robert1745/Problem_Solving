/* जय श्री हनुमान */
#include <bits/stdc++.h>
using namespace std;

// Function to solve Tower of Hanoi
void towerOfHanoi(int n, int from, int to, int aux, vector<pair<int, int>> &moves) {
    if (n == 0)
        return;

    // Move n-1 disks from "from" to "aux" using "to"
    towerOfHanoi(n - 1, from, aux, to, moves);

    // Move the nth disk from "from" to "to"
    moves.push_back({from, to});

    // Move n-1 disks from "aux" to "to" using "from"
    towerOfHanoi(n - 1, aux, to, from, moves);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> moves;
    towerOfHanoi(n, 1, 3, 2, moves);

  
    cout << moves.size() << "\n"; // Minimum number of moves
    for (auto &move : moves) {
        cout << move.first << " " << move.second << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> findSwappableIndices(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> elements_map;

    for (int num : A) {
        elements_map[num] = 1;
    }

    int sumA = 0, sumB = 0;
    for (int num : A) {
        sumA += num;
    }
    for (int num : B) {
        sumB += num;
    }

    int target = (sumA - sumB) / 2;

    for (int i = 0; i < B.size(); i++) {
        int complement = target + B[i];
        if (elements_map.find(complement) != elements_map.end()) {
            return make_pair(complement, B[i]);
        }
    }

    return make_pair(-1, -1);
}

int main() {
    int nA, nB, x;
    cout << "Enter size of A: " << endl;
    cin >> nA;
    cout << "Enter size of B: " << endl;
    cin >> nB;
    vector<int> A, B;
    
    for (int i = 0; i < nA; i++) {
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < nB; i++) {
        cin >> x;
        B.push_back(x);
    }

    pair<int, int> result = findSwappableIndices(A, B);

    if (result.first != -1) {
        cout << "Elements " << result.first << " from A and " << result.second << " from B can be swapped." << endl;
    } else {
        cout << "No such pair exists." << endl;
    }

    return 0;
}

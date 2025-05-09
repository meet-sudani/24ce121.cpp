#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void reverseWithStd(vector<int>& seq) {
    std::reverse(seq.begin(), seq.end());
}

void reverseManually(vector<int>& seq) {
    auto start = seq.begin();
    auto end = seq.end() - 1;

    while (start < end) {
        swap(*start, *end);
        ++start;
        --end;
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> seq(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    cout << "\nOriginal sequence: ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    reverseWithStd(seq);
    cout << "\nReversed sequence using std::reverse(): ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    cout << "\n\nEnter the elements again for manual reversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    cout << "\nOriginal sequence: ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    reverseManually(seq);
    cout << "\nReversed sequence using iterators: ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    return 0;
}


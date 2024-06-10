#include <iostream>
#include <vector>
using namespace std;
void combinations(int n, int k) {
    vector<int> current_combination(k, 0);

    int i = 0;
    while (i >= 0) {
        current_combination[i]++;

        if (current_combination[i] > n) {
            i--;
        } else if (i == k - 1) {
            for (int j = 0; j < k; ++j) {
                cout << current_combination[j] << " ";
            }
            cout << endl;
        } else {
            i++;
            current_combination[i] = current_combination[i - 1];
        }
    }
}

int main() {
    int n, k;
    cout << "n個の要素からk個を選ぶ組み合わせを生成します。" << endl;
    cout << "nの値を入力してください: ";
    cin >> n;
    cout << "kの値を入力してください: ";
    cin >> k;

    combinations(n, k);

    return 0;
}
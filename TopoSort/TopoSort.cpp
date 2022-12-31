#include <iostream>
#include <typeinfo>
using namespace std;

#define max 1000

struct Node {
    int SUC;
    Node* NEXT;
};

int main() {

    Node* TOP[max]{ nullptr };
    int COUNT[max]{ 0 };
    int QLINK[max]{ 0 };

    Node* P = nullptr;
    int F, R, N;

    // buoc 1 
    int n;
    cout << "Nhap vao tong so dinh cua do thi: ";
    cin >> n;
    N = n;
    int m;
    cout << "Nhap vao so luong cac cap j < k: ";
    cin >> m;

    // buoc 2 va buoc 3 
    cout << "Nhap vao cac cap j < k" << endl;
    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        if (j < 0) break;
        ++COUNT[k];
        P = new Node{ k, TOP[j] };
        TOP[j] = P;
    }

    // buoc 4 
    R = 0, QLINK[0] = 0;
    for (int k = 1; k <= n; k++) {
        if (COUNT[k] == 0) {
            QLINK[R] = k;
            R = k;
        }
    }
    F = QLINK[0];

    // buoc thu  5
    while (F != 0) {
        cout << F << " ";
        N = N - 1;
        P = TOP[F];
        // buoc thu 6
        while (P != nullptr) {
            --COUNT[P->SUC];
            if (COUNT[P->SUC] == 0) {
                QLINK[R] = P->SUC;
                R = P->SUC;
            }
            P = P->NEXT;
        }
        // buoc thu 7 
        F = QLINK[F];
    }

    return 0;
}

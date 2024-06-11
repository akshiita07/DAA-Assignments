/*
4. Optimal Binary Search Tree
*/

#include<iostream>
using namespace std;

// Function to calculate optimal binary search tree
void obst(int n, int *keys, int *p, int **c, int **r) {
    for (int i = 0; i <= n + 1; i++) {
        c[i] = new int[n + 1]();
    }
    for (int i = 0; i <= n; i++) {
        r[i] = new int[n + 1]();
    }

    for (int i = 1; i <= n; i++) {
        c[i][i - 1] = 0;
        c[i][i] = p[i - 1];
        r[i][i] = i;
    }
    c[n + 1][n] = 0;

    for (int d = 1; d < n; d++) {
        for (int i = 1; i <= n - d; i++) {
            int j = d + i;
            int min = INT_MAX;

            for (int R = i; R <= j; R++) {
                int cost = c[i][R - 1] + c[R + 1][j];
                if (cost < min) {
                    min = cost;
                    r[i][j] = R;
                }
            }
            c[i][j] = min + p[j - 1] + p[i - 1];
        }
    }
}

int main() {
    // n- no of keys
    // p- probability of searching key
    int n = 4;
    int keys[] = {10, 20, 30, 40};
    int p[] = {4, 2, 6, 3};
    int **c = new int*[n + 2];
    int **r = new int*[n + 1];

    obst(n, keys, p, c, r);

    cout << "Cost Table: " << endl;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nRoot Table:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Minimum Cost of Optimal Binary Search Tree: " << c[1][n] << endl;


    return 0;
}

	
//	op- 26 and obst- 30
//					10   40
//					  20


#include <iostream>


int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    int n, m; 
    const int size_n = 10; 
    const int size_m = 10; 
    
    int v[size_n][size_m]; 
    int w[size_n]; 
    int x[size_n]; 
  

    std::cout << "The output is:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            std::cout << v[i][j] << "\t";
        }
        std::cout << "\n\n";
    }


    std::cout << "\nThe optimal solution is " << v[n][m];


    std::cout << "\nThe solution vector is:\n";
    for (int i = n; i >= 1; i--) {
        if (v[i][m] != v[i - 1][m]) {
            x[i] = 1;
            m = m - w[i];
        } else {
            x[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << x[i] << "\t";
    }

    return 0;
}

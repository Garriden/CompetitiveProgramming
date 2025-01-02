/*********************
https://codeforces.com/problemset/problem/330/A

3 4
S...
....
..S.

-------

8
*************************/

#include <bits/stdc++.h>
#include <stdio.h>


int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<char> > C(n, std::vector<char>(m));
    
    for(int ii = 0; ii < n; ++ii) {
       for(int jj = 0; jj < m; ++jj) {
            std::cin >> C[ii][jj];
        } 
    }
    
    int cont = 0;
    int res = 0;

    // Comprovar fila neta.
    for(int ii = 0; ii < n; ++ii) {
       for(int jj = 0; jj < m; ++jj) {
           if(C[ii][jj] == '.') cont++;
           if(cont == m) res += m;

        } 
        cont = 0;
    }
    
    int auxCols = res;
    //std::cout << res << std::endl;
    
    // Comprovar columna neta.
    for(int jj = 0; jj < m; ++jj) {
       for(int ii = 0; ii < n; ++ii) {
           if(C[ii][jj] == '.') cont++;
           if(cont == n) res += (n - (auxCols/m));

        }
        cont = 0;
    }
    
    std::cout << res << std::endl;


    return 0;
}

#include <iostream>
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

// g++ -std=c++20 0910SortedMatrixSearch.cpp -o hola

// Depends if the Matrix is fully ordered.

// First aproach: Double binary search. Rows and columns independently.
// Time complexity: O(log(n))

// If the matrix is fully ordered.
//  translate the matrix into a single vector,
//   or translate it into row / columns and do a default binary search.
// Time complexity: O(log(n))

int BinarySearchMatrix(std::vector<std::vector<int> > M, int x)
{
    int m = M[0].size();
    int n = M.size();
    int left = 0;
    int right = m * n;

    while(left <= right) {
        int mid = (left+right) / 2;
        //std::cout << "mid: " << mid << "   M[mid]: " << M[mid / m][mid % m] << std::endl;
        //std::cout << "mid / m: " << mid / m << "   mid % m: " << mid % m << std::endl;
        if(M[mid / m][mid % m] == x) {
            return mid;
        } else if(M[mid / m][mid % m] > x) {
            right = mid - 1;
        } else { // < x
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n = 5;
    int m = 3;
    std::vector<std::vector<int> > M(n, (std::vector<int>(m, 0)));
    int x = 6;

    int cont = 0;
    for(int ii = 0; ii < n; ++ii) {
        for(int jj = 0; jj < m; ++jj) {
            M[ii][jj] = cont++;
        }
    }

    std::cout << (x == BinarySearchMatrix(M, x)) << std::endl;

    return 0;
}
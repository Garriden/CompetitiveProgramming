#include <iostream>
#include <vector>

/*
  Just iterate.
    Time complexity: O(n^2)
    But do it with 2 vectors bool.
    - Check
    - Build

    Posible memory optimization: Use the first? row/column as the bool vector I use.
*/

std::vector<std::vector<int> > ZeroMatrix(std::vector<std::vector<int> > &mat)
{
    int N = mat.size();
    int M = mat[0].size();

    std::vector<bool> zeroRow(N, false);
    std::vector<bool> zeroColumn(M, false);

    for(int ii = 0; ii < N; ++ii) {
        //if(!zeroRow[ii]) {
            for(int jj = 0; jj < M; ++jj) {
                //if(!zeroColumn[jj]) {
                    if(mat[ii][jj] == 0) {
                        zeroRow[ii] = true;
                        zeroColumn[jj] = true;
                        break;
                    }
                //}
            }
        //}
    }

    // Posible optimization, iterate the two vectors instead of the matrix.
    for(int ii = 0; ii < N; ++ii) {
        for(int jj = 0; jj < M; ++jj) {
            if(zeroRow[ii] || zeroColumn[jj]) {
                mat[ii][jj] = 0;
            }
        }
    }

    return mat;
}

void printMatrix(const std::vector<std::vector<int> > &m) 
{
    for(int ii = 0; ii < m.size(); ++ii) {
        for(int jj = 0; jj < m[ii].size(); ++jj) {
            std::cout << m[ii][jj] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    std::vector<std::vector<int>> m{{1,0,3},{4,5,0},{7,8,9},{1,2,3},{4,5,0},{7,8,9}};
    std::vector<std::vector<int>> m2{{1,2},{5,6},{9,0},{13,14,}};

    printMatrix(ZeroMatrix(m));

    return 0;
}
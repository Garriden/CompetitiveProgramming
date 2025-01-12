#include <iostream>
#include <vector>

/*
  Just iterate.
    Time complexity: O(n^2)
    - Auxiliar matrix.
    - Swap (rows + diagonal)
    - Swap layers
*/

std::vector<std::vector<int> > RotateMatrixAuxiliar(const std::vector<std::vector<int> > &m) 
{
    std::vector<std::vector<int> > maux( m.size(), std::vector<int>(m.size()) );

    for(int ii = 0; ii < m.size(); ++ii) {
        for(int jj = 0; jj < m[ii].size(); ++jj) {
            maux[m.size()-1-jj][ii] = m[ii][jj];
        }
    }

    return maux;
}

std::vector<std::vector<int> > RotateMatrixInPlace(std::vector<std::vector<int> > &m) 
{
    // Reverse rows.
    for(int ii = 0; ii < m.size(); ++ii) {
        for(int jj = 0; jj < m[ii].size()/2; ++jj) {
            int aux = m[ii][m[ii].size()-1-jj];
            m[ii][m[ii].size()-1-jj] = m[ii][jj];
            m[ii][jj] = aux;
        }
    }

    // Swap on diagonal.
    for(int ii = 0; ii < m.size(); ++ii) {
        for(int jj = ii; jj < m[ii].size(); ++jj) {
            int aux = m[ii][jj];
            m[ii][jj] = m[jj][ii];
            m[jj][ii] = aux;
        }
    }

    return m;
}

std::vector<std::vector<int> > RotateMatrixLayers(std::vector<std::vector<int> > &m)
{
    int n = m.size();
    for(int ii = 0; ii < n/2; ++ii) {

        for(int jj = ii; jj < n - ii - 1; ++jj) {
            int aux = m[ii][jj];

            //top     <-  right
            m[ii][jj] = m[jj][n-1-ii];

            //right         <-   bot rev
            m[jj][n-1-ii] = m[n-1-ii][n-1-jj];

            //bot rev      <-    left rev
            m[n-1-ii][n-1-jj] = m[n-1-jj][ii];

            //left rev    <-   top
            m[n-1-jj][ii] = aux;

        }


    }
    return m;
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
    std::vector<std::vector<int>> m{{1,2,3},{4,5,6},{7,8,9}};
    std::vector<std::vector<int>> m2{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    printMatrix(RotateMatrixLayers(m2));

    return 0;
}
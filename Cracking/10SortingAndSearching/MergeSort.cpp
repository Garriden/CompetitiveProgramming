#include <iostream>
#include <cstdint>
#include <string.h>
#include <bitset>
#include <format>
#include <vector>

// g++ -std=c++20 MergeSort.cpp -o hola

void Merge(std::vector<int> &v, int left, int mid, int right)
{
    int n1 = mid-left+1; // +1 because we have at least two numbers.
    int n2 = right-mid;

    // Create temporaly vectors.
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for(int ii = 0; ii < n1; ++ii) {
        L[ii] = v[left + ii];
    }

    for(int ii = 0; ii < n2; ++ii) {
        R[ii] = v[mid + 1 + ii]; // The same +1 before. From left to mid. from mid+1 to right.
    }
/*
    std::cout << "   ";
    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    }
    std::cout << "  L: ";
    for(int ii = 0; ii < n1; ++ii) {
        std::cout << L[ii] << " ";
    }
    std::cout << "  R: ";
    for(int ii = 0; ii < n2; ++ii) {
        std::cout << R[ii] << " ";
    } 
    std::cout << std::endl;
*/
    int l = 0;
    int r = 0;
    // Principal Function: Combine both arrays.
    while(l < n1 && r < n2) {
        if(L[l] < R[r]) {
            v[left+l+r] = L[l];
            ++l;
        } else {
            v[left+l+r] = R[r];
            ++r;
        }
    }

    while(l < n1) {
        v[left+l+r] = L[l];
        ++l;
    }

    while(r < n2) {
        v[left+l+r] = R[r];
        ++r;
    }
/*
    std::cout << "v: ";
    for(int ii = 0; ii < v.size(); ++ii) {
        std::cout << v[ii] << " ";
    } std::cout << std::endl << std::endl;
*/
}

void MergeSort(std::vector<int> &v, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;

        MergeSort(v, left, mid);
        MergeSort(v, mid+1, right);

        Merge(v, left, mid, right);
    }

}
int main()
{
    int n = 11;
    std::vector<int> v = {24, 68, 2, 69, 54, 7, 28, 18, 10, 66, 4};

    MergeSort(v, 0, n-1);

    for(int ii = 0; ii < n; ++ii) {
        std::cout << v[ii] << " ";
    } std::cout << std::endl;

    return 0;
}
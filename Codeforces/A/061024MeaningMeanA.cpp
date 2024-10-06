#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n, a;
    cin >> t;
    while(t--) {
        int sum = 0;
        cin >> n;
        int N = n;
        std::vector<int> v;
        while(n--) {
            cin >> a;
            v.push_back(a);
            //v.erase 
        }
        std::sort (v.begin(), v.end());
                   
        // for(int ii = 0; ii < N; ++ii) {
        //        cout << v[ii] << " ";
        //    }
//
        //    cout << endl;


        while(N > 1) {
            int aux = v[0] + v[1];
            v.erase(v.begin());
            v.erase(v.begin());
            v.push_back(aux/2);
            std::sort (v.begin(), v.end());
            N--;
            //for(int ii = 0; ii < N; ++ii) {
            //    cout << v[ii] << " ";
            //}
            //cout << endl;
        }

        cout << v[0] << endl;
        sum = 0;
    }

}
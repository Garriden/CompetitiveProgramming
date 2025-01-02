#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n, x, a;
    cin >> t;
    while(t--) {
        int sum = 0;
        cin >> n >> x;
        int N = n;
        std::unordered_map<int,int> map; // number, times
        while(n--) {
            cin >> a;
            bool inserted = map.insert({a,1}).second;
            if(!inserted) {
                 map[a]++;
            }
            //v.erase 
        }

int MEX = 0;
/*
for(int ii = 0; ii <= N; ++ii) {
    
    if(map[ii] == 0) {
            
            MEX = ii;
            break;

    
    }

}
*/
//cout << "MEX: " << MEX << endl;

//chedk if we can do this number.
for(int ii = 0; ii <= N; ++ii) {

 if(map[ii] > 1) {

    //cout << "possible: " << ii;
    int aux = ii+x;
    while(map[aux] > 0) { aux += x; }

      //      cout << "aux: " << aux << " ";
        
        //if(aux == MEX) {
        //    cout << "aux => MEX " << aux << " map[aux]: " << map[aux];
            //newMEX = true;
            MEX = aux;
            map[aux]++;
            map[ii]--;
            --ii;
            //break;
        //}
        aux += x;
    //}
 } else if (map[ii] == 0) {
            MEX = ii;
            break;

 }


            //if(map[ii] == 0) {
                //cout << "HOLAAAAAAAAA: " << ii << endl;
                //MEX = ii;
                //break;
            //}


}


cout << MEX << endl;
//cout << "MEX: " << MEX << endl;

    }

}
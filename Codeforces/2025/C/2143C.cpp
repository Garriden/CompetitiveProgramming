// https://codeforces.com/contest/2143/problem/C
// Div. 2
// 1500
//

// Max Tree

// g++ -o c c.cpp

// dfs and similar
// graphs
// greedy

// WA
// DAG. Directed Acyclic Graph
// Let's assign an orientation to each edge ?

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

void solve()
{
    ll n, x, y, k, l, r;
    ll a, b, p;
    std::string s;
    ll modulo = 998244353;
    ll max = 0;

    std::cin >> n;
    ll N = n;

    std::vector<ll> vu(n);
    std::vector<ll> vv(n);
    std::vector<ll> vx(n);
    std::vector<ll> vy(n);
    std::vector<bool> visited(n);
    std::vector<ll> permutationResult(n, 0);
    std::multimap<ll, ll, std::greater<ll> > xValueIndex;
    std::multimap<ll, ll, std::greater<ll> > yValueIndex;
    for(int ii = 0; ii < n - 1; ++ii) {
        std::cin >> vu[ii] >> vv[ii] >> vx[ii] >> vy[ii];
        xValueIndex.insert({vx[ii], ii});
        yValueIndex.insert({vy[ii], ii});
    }

    //std::cout << "Map x: " << std::endl;
    //for(const auto& pair : xValueIndex) {
    //    std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    //}
    //std::cout << "Map y: " << std::endl;
    //for(const auto& pair : yValueIndex) {
    //    std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    //}

    // Ordenar x, y ? Already in map

    ll left = 1;
    ll right = n;

    std::map<ll, ll>::iterator itX = xValueIndex.begin();
    std::map<ll, ll>::iterator itY = yValueIndex.begin();

    // Loop until the iterator reaches the end of the map
    while(itX != xValueIndex.end() && itY != yValueIndex.end()) {

        if(itX->first > itY->first) {
            if(!visited[itX->second]) { // visited original vector, to not compute the other y.
                visited[itX->second] = true;

                int index = itX->second;

                if(vx[index] > vy[index]) {
                    // if already index
                    if(permutationResult[vu[index] - 1] == 0) {
                        permutationResult[vu[index] - 1] = right;
                    } else {
                        permutationResult[vv[index] - 1] = right;
                    }
                } else {
                    if(permutationResult[vv[index] - 1] == 0) {
                        permutationResult[vv[index] - 1] = right;
                    } else {
                        permutationResult[vu[index] - 1] = right;
                    }
                }

                right--;


            //for(int ii = 0; ii < permutationResult.size(); ++ii) {
            //    //sum += permutationResult[ii];
            //    std::cout << permutationResult[ii] << " ";
            //} std::cout << std::endl;


            }

            ++itX;
        } else {

            if(!visited[itY->second]) { // visited original vector, to not compute the other x.
                visited[itY->second] = true;

                int index = itY->second;

                if(vx[index] > vy[index]) {
                    if(permutationResult[vu[index] - 1] == 0) {
                        permutationResult[vu[index] - 1] = right;
                    } else {
                        permutationResult[vv[index] - 1] = right;
                    }
                } else {
                    if(permutationResult[vv[index] - 1] == 0) {
                        permutationResult[vv[index] - 1] = right;
                    } else {
                        permutationResult[vu[index] - 1] = right;
                    }
                }

                right--;


                    //for(int ii = 0; ii < permutationResult.size(); ++ii) {
                    //    //sum += permutationResult[ii];
                    //    std::cout << permutationResult[ii] << " ";
                    //} std::cout << std::endl;

            }

            ++itY;
        }


    }

    //for(int ii = 0; ii < va.size(); ++ii) {
    //    std::cout << va[ii] << " ";
    //} std::cout << std::endl;

    ll sum = 0;
    for(int ii = 0; ii < permutationResult.size(); ++ii) {
        //sum += permutationResult[ii];
        if(permutationResult[ii] == 0) {
            permutationResult[ii] = 1;
        }
        std::cout << permutationResult[ii] << " ";
    } std::cout << std::endl;
    
    //std::cout << "max: " << sum << std::endl;
    //std::cout << sum << std::endl;
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}

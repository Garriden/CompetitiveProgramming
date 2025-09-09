// https://codeforces.com/contest/2139/problem/E1
// Div. 2
//

// Maple and Tree Beauty

// g++ -o c c.cpp

// Trees
// graphs
// dp

//  Time limit exceeded on test 45
// Find if any combination of levels are equal to the number of ones or zeros.
// Efficientcy: Find with recursive approach instead of 2^n combinations.

// Trick! Replace this recursive approach with Dynamic programming!
// Create a boolean array, dp[i] will be true if a sum of i can be formed.

// Wrong answer on test 50

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

bool FindLevelWithXNodes(int n, const std::unordered_map<ll, ll> &map)
{
    if(n <= 0) {
        return false;
    }

    for(auto pair : map) {
        if(pair.second == n) {
            return true;
        }
    }

    return false;
}

/*
std::unordered_set<ll> FindAllSubsets(const std::vector<ll> &v, int x)
{
    std::unordered_set<ll> allSums;
    int n = v.size();

    // Loop through all possible subsets.
    for(int ii = 0; ii < pow(2, n); ++ii) {
        ll sum = 0;

        for(int jj = 0; jj < n; ++jj) {
            if((ii >> jj) & 1) {
                sum += v[jj];

                if(sum > x) {
                    break;
                }
            }
        }
        allSums.insert(sum);
    }

    //std::cout << "AllSUms: ";
    //for(auto elem : allSums) {
    //    std::cout << elem << " ";
    //} std::cout << std::endl;

    return allSums;
}
*/

/*
void FindSubsetSumsRecursive(const std::vector<ll>& v, int index, ll sum, ll x, bool &found) 
{
    if(index == v.size()) {
        return;
    }

    if(sum == x) {
        found = true;
        //std::cout << "Found!" << std::endl;
        return;
    }

    // Optimization / Pruning.
    if(sum > x) {
        return;
    }

    if(!found) FindSubsetSumsRecursive(v, index + 1, sum + v[index], x, found); // include element.
    if(!found) FindSubsetSumsRecursive(v, index + 1, sum, x, found); // exclude element.
}

bool FindLevelWithSumXNodes(int n, const std::unordered_map<ll, ll> &map)
{
    if(n <= 0) {
        return false;
    }

    // Convert map to vector for easier iterations.
    std::vector<ll> levelFreq;
    for(auto pair : map) {
        levelFreq.push_back(pair.second);
    }

    //std::unordered_set<ll> allSubsets = FindAllSubsets(levelFreq, n);
    //return allSubsets.count(n);
    bool found = false;
    FindSubsetSumsRecursive(levelFreq, 0, 0, n, found);
    return found;
}
*/
bool FindLevelWithSumXNodes(int n, const std::unordered_map<ll, ll> &map)
{
    if(n <= 0) {
        return false;
    }

    // Convert map to vector for easier iterations.
    std::vector<ll> levelFreq;
    for(auto pair : map) {
        levelFreq.push_back(pair.second);
    }

    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for(ll ii; ii < levelFreq.size(); ++ii) {
        for(ll jj = n; jj >= levelFreq[ii]; --jj) {
            if(dp[jj - levelFreq[ii]]) {
                dp[jj] = true;
            }
        }
    }

    return dp[n];
}

void solve() {
    ll n, x, y, k, l, r, m;

    std::cin >> n >> k;
    std::vector<ll> va(n + 1);
    std::vector<ll> sonsNumber(n + 1, 0);
    std::vector<ll> depth(n + 1, 0);
    depth[1] = 1;
    int maxDepth = 0;

    for(int ii = 2; ii <= n; ++ii) {
        std::cin >> va[ii];
        sonsNumber[va[ii]]++;
        depth[ii] = depth[va[ii]] + 1;

        if(depth[ii] > maxDepth) {
            maxDepth = depth[ii];
        }
    }

    //std::cout << "Depth: " << std::endl;
    //for(int ii = 0; ii < depth.size(); ++ii) {
    //    std::cout << depth[ii] << " ";
    //} std::cout << std::endl;

    //std::cout << "Sons: " << std::endl;
    std::vector<ll> leafs;
    for(int ii = 0; ii < sonsNumber.size(); ++ii) {
        //std::cout << sonsNumber[ii] << " ";
        if(ii != 0) {
            if(sonsNumber[ii] == 0) {
                leafs.push_back(ii);
            }
        }
    }// std::cout << std::endl;

    int minDepthLeaf = INT_MAX;
    int maxDepthLeaf = 0;
    for(int ii = 0; ii < leafs.size(); ++ii) {
        if(depth[leafs[ii]] < minDepthLeaf) {
            minDepthLeaf = depth[leafs[ii]];
        }

        if(depth[leafs[ii]] > maxDepthLeaf) {
            maxDepthLeaf = depth[leafs[ii]];
        }
    }
    //std::cout << "minDepthLeaf: " << minDepthLeaf << "  / maxDepthLeaf: " << maxDepthLeaf  << std::endl;

    std::unordered_map<ll, ll> depthFreq; // key = depth, value = number of times appeared.
    for(int ii = 1; ii < n + 1; ++ii) {
        depthFreq[depth[ii]]++;
    }

    //for(auto pair : depthFreq) {
    //    std::cout << "key: " << pair.first << "  / value: " << pair.second << std::endl;
    //}

    if(k == 0 || k == n || FindLevelWithXNodes(k, depthFreq) || FindLevelWithXNodes(n - k, depthFreq)) { // Power of two.
        //std::cout << "a" << std::endl;
        std::cout << std::min(maxDepth, minDepthLeaf) << std::endl;
    } else if(FindLevelWithSumXNodes(k, depthFreq) || FindLevelWithSumXNodes(n - k, depthFreq)) { // sum of powers of two. (Power of two minus one).
        //std::cout << "b" << std::endl;
        std::cout << std::min(maxDepth, minDepthLeaf) << std::endl;
    } else {
        //std::cout << "NOT maxdepth" << std::endl;
        //--maxDepth;
        while(maxDepth > 1) {
            int newN = n - depthFreq[maxDepth];

            --maxDepth;
            if((newN <= k || newN < (n-k)) && maxDepth <= minDepthLeaf) {
                std::cout << maxDepth << std::endl;
                return;
            }
            n = newN;
        }
        std::cout << 1 << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;

    while(t --> 0) {
        solve();
    }

}

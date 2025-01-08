/*********************
https://codeforces.com/contest/1633/problem/C
C

brute force
math

4
25 4
9 20
1 1 10
25 4
12 20
1 1 10
100 1
45 2
0 4 10
9 2
69 2
4 2 7
*************************/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

void solve() {
    long long hc,dc,hm,dm,k,w,a;
    
    cin >> hc >> dc;
    cin >> hm >> dm;
    cin >> k >> w >> a;

	for(int ii = 0; ii <= k; ++ii) {
		long long newHealth = hc + (k-ii) * a;
		long long newAttack = dc + ii * w;
		long long monsterTurn, characterTurn;
		
		if(newHealth%dm == 0) monsterTurn=newHealth/dm;
		else monsterTurn=newHealth/dm + 1;
		
		if(hm%newAttack == 0) characterTurn=hm/newAttack;
		else characterTurn=hm/newAttack + 1;
				
		if(characterTurn<=monsterTurn) {
			cout << "YES" << endl;
			return;
		}
	 
    }
    cout << "NO" << endl;
          
}  

int main() {
	long long T;
	cin >> T;
	while (T--) solve();
}

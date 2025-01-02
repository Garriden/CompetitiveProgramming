#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k,i,a;
	//map<int,int>m;
	cin >> n >> k;

	vector<bool> B(100);
	vector<int> res(k);
	for(i = 0; i < 100; ++i) B[i] = false;
	for(i = 0; i < k; ++i) res[i] = -1;
	int cont = 0;
	for(i = 0; i < n; ++i) {
		cin >> a;
		//m[a] = i+1;
		if((B[a] == false) && (cont < k)) {
			res[cont] = i;
			++cont;
		}
		B[a] = true;	
	}
	
	bool YES = true;
	for(i = 0; i < k; ++i) if(res[i] == -1) YES = false;
	
	if(!YES) cout << "NO";
	else {
		cout << "YES" << endl;
		for(i = 0; i < k; ++i) cout << res[i]+1 << " ";
		/*{
			cout << (m.begin()->second) << " ";
            m.erase(m.begin());
		}*/
	}
	cout << endl;
	
}

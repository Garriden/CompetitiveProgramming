#include <bits/stdc++.h>
using namespace std;

int main() {
  	int n,n1,n2, m, i;

	cin >> n;
	
		
	vector<pair<int,int> > N(n);
	
	for(i=0;i<n;++i) {
		cin >> n1 >> n2;;
		N[i].first = n1;
		N[i].second = n2;

	}
	
	cin >> m;
	
	vector<pair<int,int> > M(m);
	
	for(i=0;i<m;++i) {
		cin >> n1 >> n2;;
		M[i].first = n1;
		M[i].second = n2;

	}
	
	sort(N.begin(), N.end());
	sort(M.begin(), M.end());
	
	/*
	for(i=0;i<n;++i) cout << N[i].first << " ";//res+= N[i].second;
	
	cout << endl;
	for(i=0;i<m;++i) cout << M[i].first << " ";//res+= M[i].seco
	cout << endl;
	*/
	int j = 0;

		for(i=0;i<n;++i) {
			
			while((N[i].first > M[j].first) && (j<m)) j++;
			
			//cout << "Ni " << N[i].first << " Mj " << M[j].first << endl;
			if(N[i].first == M[j].first) {
				if(N[i].second < M[j].second) {
					N[i].second = 0;
				}
				else M[j].second = 0;
			}
			//j = 0;
		}
		
	
	
	

	long long res = 0;
	for(i=0;i<n;++i) res+= N[i].second;
	
	cout << endl;
	for(i=0;i<m;++i) res+= M[i].second;

	cout << res << endl;
	
}

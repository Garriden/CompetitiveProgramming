#include <bits/stdc++.h>
using namespace std;

int main() {
  	int n,min1F,min2F,min3F,minaux,nn;
  	int min1S=-1,min2S=-1,min3S=-1;
  	int min1,min2,min3;
  	cin >> n;
  	
  	vector<pair<int,int> > Pos(n);
  	vector<int> > V(n);
  	int pos = 0, racha = 0;
 
  	cin >> Pos[0].first;
	cin >> Pos[1].first;
	cin >> Pos[2].first;
  	for(int i = 3; i < n; ++i) cin >> Pos[i].first;
  	
  	cin >> Pos[0].second;
	cin >> Pos[1].second;
	cin >> Pos[2].second;
  	for(int i = 3; i < n; ++i) cin >> Pos[i].second;
  	
  	
  	min1S = Pos[0].second;
  	min1F = Pos[0].first;
  	if(Pos[1].first > Pos[0].first) {
		min2S = Pos[1].second;
		min2F = Pos[1].first;
		if(min2 < min1) {
			swap(min1S,min2S);
			swap(min1F,min2F);
		}
	}
	if(Pos[2].first > Pos[1].first) {
		min3S = Pos[2].second;
		min3F = Pos[2].first;
		if(min3 < min2) {
			swap(min2S,min3S);
			swap(min2F,min3F);
		}
	}
	
	

  	for(int i = 3; i < n; ++i) {
		
		if((Pos[i].first > min1F) && (Pos[i].first < min2F)) {
			if(Pos[i].second < min1S) {
				min1S = Pos[i].second;
				min1F = Pos[i].first;
			}			
		}
		else if((Pos[i].first > min2F) && (Pos[i].first < min3F)) {
			if(Pos[i].second < min2S) {
				min2S = Pos[i].second;
				min2F = Pos[i].first;
			}			
		}
		else if(Pos[i].first > min3F) {
			if(Pos[i].second < min3S) {
				min3S = Pos[i].second;
				min3F = Pos[i].first;
			}			
		}
	}
	
	if((min1S == -1) || (min2S == -1) || (min3S == -1))cout << -1;
	else cout << min1S+min2S+min3S;
	cout << endl;
	
	cout << min1F << " " << min2F << " " << min3F << endl;
	cout << min1S << " " << min2S << " " << min3S << endl;
  	
}

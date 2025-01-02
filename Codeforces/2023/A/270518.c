#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, saux, ss;
	int res = 0, i;
	cin >> s;
	bool fora = false;
	
	ss = s.substr(0,1);
	for(int i = 1; (i < s.size()) && (!fora); ++i) {
		saux = s.substr(i,1);
		if(ss != saux) fora = true;
	}
	saux = string(s.rbegin(), s.rend());
    
    
	if(!fora) cout << 0 <<endl;
    else {
      if(s == saux) cout << s.size()-1 << endl;
      else cout << s.size() << endl;
    }
	//cout << saux << endl;
	
	
}

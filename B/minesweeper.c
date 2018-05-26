#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, i, j;
	cin >> n >> m;
	vector< vector<char> > M(n+2,vector<char>(m+2));

	int mines = 0;
	bool fora = false;

	for(i = 0; i < (n+2); ++i) {
		for(j = 0; j < (m+2); ++j) {
			if((i == 0) || (i == (n+1)) || (j == 0) || (j == (m+1))) M[i][j] = '0';
			else cin >> M[i][j];
		}		
	}
  /*
  for(i = 0; i < (n+2); ++i) {
		for(j = 0; j < (m+2); ++j) {
			cout << M[i][j];
		}		
		cout << endl;
	}
	*/
	for(i = 1; (i < (n+1)) && (!fora); ++i) {
		for(j = 1; (j < (m+1)) && (!fora); ++j) {
			if(M[i][j] != '*') {
				if(M[i+1][j] == '*') ++mines;									// nord
				if (M[i-1][j] == '*') ++mines;						// sud
				if (M[i][j+1] == '*') ++mines;						// est
				if (M[i][j-1] == '*') ++mines;						// oest
				if (M[i+1][j+1] == '*') ++mines;					// sud-est
				if (M[i-1][j-1] == '*') ++mines;					// nord-oest
				if (M[i-1][j+1] == '*') ++mines;					// nord-est
				if (M[i+1][j-1] == '*') ++mines;					// sud-oest
				
				if ((mines == 8) && (M[i][j] != '8')) fora = true;
				else if ((mines == 7) && (M[i][j] != '7')) fora = true;
				else if ((mines == 6) && (M[i][j] != '6')) fora = true;
				else if ((mines == 5) && (M[i][j] != '5')) fora = true;
				else if ((mines == 4) && (M[i][j] != '4')) fora = true;
				else if ((mines == 3) && (M[i][j] != '3')) fora = true;
				else if ((mines == 2) && (M[i][j] != '2')) fora = true;
				else if ((mines == 1) && (M[i][j] != '1')) fora = true;
				else if ((mines == 0) && (M[i][j] != '.')) fora = true;
      }
			mines = 0;
		}		
	}
	
	if(fora) cout << "NO" << endl;
	else cout << "YES" << endl;
}

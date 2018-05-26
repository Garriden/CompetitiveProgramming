#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	char c;
	int white = 0, black = 0;
	vector<vector<char> > M(8, vector<char>(8));
	for(int i = 0; i < 8;++i) {
	  for(int j = 0; j < 8;++j) {
	    cin >> c;
	    if(c == 'Q') white += 9;
	    else if(c == 'R') white += 5;
	    else if(c == 'B') white += 3;
	    else if(c == 'N') white += 3;
	    else if(c == 'P') white += 1;
	    //else if(c == 'K') white += 100;
	    else if(c == 'q') black += 9;
	    else if(c == 'r') black += 5;
	    else if(c == 'b') black += 3;
	    else if(c == 'n') black += 3;
	    else if(c == 'p') black += 1;
	    //else if(c == 'k') black += 100;
	  }
	}
	if(white > black) cout << "White" << endl;
	else if(white == black) cout << "Draw" << endl;
	else cout << "Black" << endl;
}

#include <bits/stdc++.h>
using namespace std;

void sorts(vector<string> &s, int n)
{
    for (int i=1 ;i<n; i++)
    {
        string temp = s[i];
 
        // Insert s[j] at its correct position
        int j = i - 1;
        while (j >= 0 && temp.length() < s[j].length())
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = temp;
    }
}

int main() {
	int n, i;
	cin >> n;
	string s;
	vector<string> S(n);
	 //vector<string>::iterator it;

	bool fora = false;
	for(i = 0; i < n; ++i) {
		cin >> S[i];
		//for(it = ans.begin(); it != ans.end() and (*it).find(s,0) == -1; it++);
        //ans.insert(it, s);
	}
	
	sorts(S,n);

	for(i = 0; i < n; ++i) {	
		for(int j = 0; j < i; ++j) {
			fora = S[i].find(S[j]) == std::string::npos;
			if(fora) break;
		}
		if(fora) break;
	}
	

		
	
	if(fora) cout << "NO";
	else { 
		cout << "YES" << endl;
			
		for(i = 0; i < n; ++i) cout << S[i] << endl;

	}
	cout << endl;
	
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, n1, i;
	cin >> n;
	string s, saux;
	
	vector<pair<int,int> > w(n);
	vector<int> sentarExtros(n);
	for(i=0;i<n;++i) {
		cin >> n1;
		w[i].first = n1;
		w[i].second = i+1;
		sentarExtros[i] = 0;
	}
	
	sort(w.begin(), w.end());
	/*
	cout << endl;
	for(i=0;i<n;++i) {
		cout << "first: " << w[i].first;
		cout << "  second: " << w[i].second;
		cout << endl;
	}
	*/
	int introvertidosOcupados = 0;	
	int extrovertidosSentados = 0;	
	int diferencia = 0;
	int ini = 0;
	int j1 = 0, j2 = 0;
	
	cin >> s;
	while(ini < (2*n)) {
		diferencia = introvertidosOcupados - extrovertidosSentados;
		saux = s.substr(ini,1);
		if(saux == "0") { 								//introvertido
			cout << w[introvertidosOcupados].second << " ";
			sentarExtros[j1++] = w[introvertidosOcupados].second;
			introvertidosOcupados++;	
		} else {										// extrovertido
			cout << sentarExtros[--j1] << " ";
		    extrovertidosSentados++;
		}
		
	    ++ini;
	  
	    diferencia = introvertidosOcupados - extrovertidosSentados;
	    saux = s.substr(ini,1);
		if(saux == "0") { 								//introvertido
			cout << w[introvertidosOcupados].second << " ";
			sentarExtros[j1++] = w[introvertidosOcupados].second;
			introvertidosOcupados++;	
		} else {										// extrovertido
			cout << sentarExtros[--j1] << " ";
		    extrovertidosSentados++;
		}
	    ++ini;
  }

	cout << endl;
}

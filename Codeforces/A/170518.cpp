#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool isMaximal(string s, int tam) {
	string actual, esq, dre;
	esq = s.substr(0,1);
	if(tam > 1) {
	  actual = s.substr(1,1);
      if(esq == actual) 
	    return false;
	}
	else if(esq == "0") return false;
	else return true;
		
	for(int i = 1; i < tam-2; ++i) {
		actual = s.substr(i,1);
		dre = s.substr(i+1,1);
		if(actual == "0") {
			if((esq == "0") && (dre == "0"))
			  return false;	
		} else { //actual == 1
			if((esq == "1") || (dre == "1"))
			return false;
		}
		
		esq = actual;
		actual = dre;
	}
	
	actual = s.substr(tam-2,1);
	dre = s.substr(tam-1,1);
	if(dre == actual) 
	  return false;
	
        
	return true;
}

int main() {
 int tam;
 cin >> tam;
 string s;
 cin >> s;

 if(isMaximal(s,tam))  
   printf("Yes\n");
 else printf("No\n");
}

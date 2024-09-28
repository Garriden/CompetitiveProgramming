// my first program in C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
      int a,b;
      cin >> a;
      int max = 0;
      int maxDos = 0;
       int maxPos = 0;

      for(int ii = 0; ii < a; ++ii) {
        cin >> b;
        //if(ii%2 == 0) {
          if(b > max) {
            max = b;
            maxPos = ii+1;
          } else if(b == max) {
            if((maxPos % 2) != ((ii+1) % 2)) {
              maxPos = 1;     
            }
          }
        //}


      }   

      int sise = a/2;



      if(a % 2 == 0) {
        //maxPos % 2 == 0 ++sise;
      } else { //inpar
        if(maxPos % 2 == 1) ++sise;
      }


      //cout << "hola: " <<  max + sise <<  "sise: " << sise << endl;
      cout << max + sise << endl;
    }



}
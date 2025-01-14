#include <iostream>

/*
  Just iterate. Just send s2+s2
    Time complexity: O(n)

    Posible memory optimization: Use the first? row/column as the bool vector I use.
*/

bool isSubstring(std::string s1, std::string s2)
{
    bool ret = false;

    int N = s1.size();
    int M = s2.size();
    int count = 0;

    if(N > M) { //s1 is bigger
        std::string aux = s1;
        s1 = s2;
        s2 = aux;
        N = s1.size();
        M = s2.size();
    }

    // exactly rotation?
    if(N*2 != M) {
        //std::cout << "N: " << N << "  M: " << M << std::endl;
        ret = false;
    } else {
        for(int ii = 0; ii < M; ++ii) {
            if(s2[ii] == s1[count]) {
                ++count;
            } else if(count > 0 && s1.size() != count) {
                ret = false;
                count = 0;
            }
        }

        if(count == s1.size()) {
            ret = true;
        }
    }

    return ret;
}

void print(const std::string &s1, const std::string &s2)
{
    if(isSubstring(s1, s2+s2)) {
        std::cout << s1 << " and " << s2 << " are StringRotation" << std::endl;
    } else {
       std::cout << s1 << " and " << s2 << " are NOT StringRotation." << std::endl;
    }
}


int main()
{
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";
    print(s1,s2);
    print(s2,s1);

    std::string s3 = "waterbottle";
    std::string s4 = "erbottletwat";
    print(s3,s4);

    std::string s5 = "waterbottle";
    std::string s6 = "erbottlewtat";
    print(s5,s6);

    return 0;
}
#include <iostream>

/*

*/

bool isOneAway(const std::string &s1, const std::string &s2) 
{
    if(s1 == s2) { // equal string, 0 away not one away.
        return false;
    } else {
        int n1 = s1.size();
        int n2 = s2.size();

        if(abs(n1-n2) > 1) { // 2Away or more
            return false;
        } else if(abs(n1-n2) == 1) { // Check insert or remove.
            int count1 = 0;
            int count2 = 0;

            for(int ii = 0; ii < n1; ++ii) {
                if(s1[ii+count1] != s2[ii+count2]) {
                    if(count1+count2 >= 1) {
                        return false;
                    } else {
                        if(s1[ii+count1+1] == s2[ii+count2]) {
                            ++count1;
                        } else if(s1[ii+count1] == s2[ii+count2+1]) {
                            ++count2;
                        }
                    }
                }
            }
        } else { // Same size. Check replace
            int diff = 0;
            for(int ii = 0; ii < n1; ++ii) {
                if(s1[ii] != s2[ii]) {
                    diff++;
                }

                if(diff > 1) {
                    return false;
                }
            }
        }
    }

    return true;
}

void print(const std::string &s1, const std::string &s2)
{
    if(isOneAway(s1, s2)) {
        std::cout << s1 << " and " << s2 << " are OneAway." << std::endl;
    } else {
       std::cout << s1 << " and " << s2 << " are NOT OneAway." << std::endl;
    }
}

int main() 
{
    std::string s1 = "pale";
    std::string s2 = "ple";
    print(s1,s2);

    std::string s3 = "pales";
    print(s1,s3);
    print(s3,s1);
    print(s2,s3);

    std::string s4 = "bale";
    print(s1,s4);

    std::string s5 = "bake";
    print(s1,s5);

    return 0;
}
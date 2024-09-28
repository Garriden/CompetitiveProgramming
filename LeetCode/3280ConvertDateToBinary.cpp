#include <string>
#include <bitset>

class Solution {
public:
    string convertDateToBinary(string date) {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    // Convert each part to binary and remove leading zeros by default
    string binaryYear = bitset<32>(year).to_string();
    string binaryMonth = bitset<8>(month).to_string();
    string binaryDay = bitset<8>(day).to_string();

    // Trim leading zeroes for the year
    binaryYear = binaryYear.substr(binaryYear.find('1'));

    // Trim leading zeroes for the month
    binaryMonth = binaryMonth.substr(binaryMonth.find('1'));

    // Trim leading zeroes for the day
    binaryDay = binaryDay.substr(binaryDay.find('1'));

    // Combine in the desired format year-month-day
    return binaryYear + "-" + binaryMonth + "-" + binaryDay;

    }
};

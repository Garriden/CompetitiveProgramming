#include <iostream>
#include <cmath>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ 1316BisectSquares.cpp -o hola

// Brute force ? Binary Search.
//  calculate the line from one extreme of the square, to the other extreme of the other square.
//  This will NOT separate the squares in equal parts, but here we can do a binary search to keep
//  adjusting the line on one square size. (and keep checking the resultant area).

constexpr double PI = 3.14159;
constexpr double RADIANTS = 180.0;

int main()
{
    int square1_x1 = 1;
    int square1_x2 = 2;
    int square1_y1 = 3;
    int square1_y2 = 4;

    int square2_x1 = 7;
    int square2_x2 = 8;
    int square2_y1 = 5;
    int square2_y2 = 6;

    double totalYSquare = std::max(square2_y2, square2_y1) - std::min(square1_y1, square1_y2);
    double totalXSquare = std::max(square2_x2, square2_x1) - std::min(square1_x1, square1_x2);

    std::cout << "totalYSquare: " << totalYSquare << "  , totalXSquare: " << totalXSquare  << std::endl;

    double hipotenusa = std::sqrt(std::pow(totalYSquare, 2) + std::pow(totalXSquare, 2));

    std::cout << "hip: " << hipotenusa << std::endl;

    double shortAngle = std::atan(totalYSquare / totalXSquare) * RADIANTS / PI;

    std::cout << "angle: " << shortAngle << std::endl;

    double opInitialSquare = std::tan(shortAngle * PI / RADIANTS) * 1;

    std::cout << "opInitialSquare: " << opInitialSquare << std::endl;

    double auxiliarY = 0.5;
    double auxiliarYHalf = 0.0;
    double area = 0.0;
    int cont = 20;
    while(cont --> 0 && (area < 0.49 || area > 0.51)) {
        
        double YSquare = totalYSquare - (auxiliarY + auxiliarY);

        hipotenusa = std::sqrt(std::pow(YSquare, 2) + std::pow(totalXSquare, 2));

        shortAngle = std::atan(YSquare / totalXSquare) * RADIANTS / PI;

        opInitialSquare = std::tan(shortAngle * PI / RADIANTS) * 1;

        double areaTriangle = (1 * opInitialSquare) / 2;
        double areaRectangle = auxiliarY * 1;

        area = areaRectangle + areaTriangle;

        std::cout << "YSquare: " << YSquare << ", hip: " << hipotenusa << "   angle: " << shortAngle << "   opInitialSquare: " << opInitialSquare << std::endl;
        std::cout << "___area: " << area << "   areaRectangle: " << areaRectangle << "   areaTriangle: " << areaTriangle << std::endl;
    
        auxiliarYHalf = (auxiliarY / 2);
        if(area > 0.5) {
            auxiliarY -= auxiliarYHalf;
        } else {
            auxiliarY += auxiliarYHalf;
        }
    
    }

    return 0;
}
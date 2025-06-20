 #include <iostream>
#include <cstdint>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// g++ -std=c++20 1308StackOfBoxes.cpp -o hola

// Backtracking

void PrintBoxes(std::vector<int> v)
{
    for(int ii = 0; ii < 10; ++ii) {
            std::cout << v[ii] << " ";
    } std::cout << std::endl;
}

void PileBoxes(std::vector<int> boxes, std::vector<int> pile, std::vector<bool> boxChosen, int index)
{
    if(index == 10) { // Base Case.
        PrintBoxes(pile);
        return;
    }

    for(int ii = 1; ii < 10; ++ii) {
        if(!boxChosen[ii] && (boxes[ii] < pile[index-1])) {
            boxChosen[ii] = true;
            pile[index] = boxes[ii];

            PileBoxes(boxes, pile, boxChosen, index + 1);

            pile[index] = 1000;
            boxChosen[ii] = false;
        }
    }

}

int main()
{
    std::vector<int>  boxes = {88, 24, 5, 4, 69, 12, 25, 7, 64, 10};
    std::vector<int>  pile(10, 1000);
    pile[0] = 88;
    std::vector<bool> boxChosen(10, false);
    boxChosen[0] = true;

    PileBoxes(boxes, pile, boxChosen, 1);
    return 0;
}
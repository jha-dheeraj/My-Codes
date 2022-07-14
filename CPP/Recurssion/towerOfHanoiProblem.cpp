#include<iostream>

using namespace std;

void solveTowerOfHanoi(int numOfPlate, int tower1, int tower2, int tower3)
{
    if(numOfPlate>0)
    {
        solveTowerOfHanoi(numOfPlate-1, tower1,tower3,tower2);
        cout << "Move a plate from Tower " << tower1 << " to Tower " << tower3 << endl;
        solveTowerOfHanoi(numOfPlate-1, tower2,tower1,tower3);
    }
}

int main()
{
    int n;
    cout << "Enter no. of plate to be moved: ";
    cin>> n;
    solveTowerOfHanoi(n,1,2,3);
    return 0;
}
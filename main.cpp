// Test editing from VS Code IDE

// How to use dynamic memory allocation
#include <iostream>
using namespace std;

void perform()
{
    int num = 234; // local variable
    // local variable is available only when the function is scalled
    // and the local variable memeory location will go away when the function finishes.

    cout << num << endl;
    num++;
}
/*
int * getAnIntegerMemoryLocationIncorrect() {
    // never return the address of a local variable (array) to the caller
    // because local variables will go away when the function finishes
    // the memory location is valid. The pointer is pointing to invalid location
    int bigNum = 999;
    return & bigNum;
}
 */

int *getAnIntegerMemoryLocation()
{
    int *pBigNum = new int; // allocate an integer with permanent memory (heap)
    return pBigNum;
}

/*
    "new" operator will allocate the required storage and return the address.
    Unlike local variable, "new" operator returns permanent storage that does not go away when the finishes.
    Because of that, it can create "memory leak" so you must use "delete" operator to free up that memory when you don't need that memory anymore.
 */

int main()
{
    // reserve the memory location but also when this memory is available and when it is invalid
    int num = 123;
    cout << num << endl;

    perform(); // print out 234
    perform(); // still print out 234

    int *pNum = getAnIntegerMemoryLocation();
    *pNum = 888; // valid because the function accquires memory location using new

    bool *pAns = new bool;
    double *pPrice = new double;

    int numList[] = {10, 20, 30}; // local variable
    int *pNumList = new int[3];   // reserve the same storage size: 3 integer variables

    char answers[] = {'Y', 'y', 'N', 'n'}; // local array
    char *pAnswers = new char[4];

    return 0;
}

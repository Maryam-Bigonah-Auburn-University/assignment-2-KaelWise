#include <iostream>

using namespace std;

void computeCoin(int coinValue, int& number, int& amountLeft);
void printOutput(int coinValue, int number);

int main() {
    char compute_again = 'N';
    int number = 0,
        amountLeft = 0;
    //Max value of 99
    do {
        cout << "Enter the amount of change: ";
        cin >> amountLeft;
        while (amountLeft < 1 || amountLeft > 99) {
            cout << "Enter a value between 1 and 99: ";
            cin >> amountLeft;
        }
        //Value reduced by larger denominations and then smaller denominations
        //Denominations noted by print output
        cout << "Change can be given as:\n";
        computeCoin(25, number, amountLeft);
        printOutput(25, number);
        computeCoin(10, number, amountLeft);
        printOutput(10, number);
        computeCoin(1, number, amountLeft);
        printOutput(1, number);

        cout << "Do you want to make change again?\n"
             << "Enter Y to convert again and any other key to exit: ";
        cin >> compute_again;
        //Allow for another computation
    } while (compute_again == 'Y' || compute_again == 'y');

    return 0;
}
//Computation voided and recalculated
void computeCoin(int coinValue, int& number, int& amountLeft) {
    number = amountLeft / coinValue;
    amountLeft %= coinValue;
}
//Output voided and re-output
void printOutput(int coinValue, int number) {
    cout << number << " coin(s) of " << coinValue << " cents\n";
}


#include <iostream>
using namespace std;

int factorial(int n) {
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}

int main() {
  int number;

  cout << "Enter a number: ";
  cin >> number;

  int result = factorial(number);
  cout << "The factorial of " << number << " is " << result << endl;

  return 0;
}
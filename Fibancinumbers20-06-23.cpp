#include <iostream>
using namespace std;

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

void generateFibonacci(int n) {
  for (int i = 0; i < n; i++) {
    cout << fibonacci(i) << " ";
  }
  cout << endl;
}

int main() {
  int N;

  cout << "Enter the value of N: ";
  cin >> N;

  cout << "The first " << N << " Fibonacci numbers are: ";
  generateFibonacci(N);

  return 0;
}
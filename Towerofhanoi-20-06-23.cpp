
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
  if (n == 1) {
    cout << "Move disk 1 from " << source << " to " << destination << endl;
    return;
  }
  
  towerOfHanoi(n - 1, source, destination, auxiliary);
  cout << "Move disk " << n << " from " << source << " to " << destination << endl;
  towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
  int n = 3; // Number of disks
  char source = 'A';
  char auxiliary = 'B';
  char destination = 'C';

  towerOfHanoi(n, source, auxiliary, destination);

  return 0;
}

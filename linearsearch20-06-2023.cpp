```cpp
#include <iostream>

#include <ctime>

using namespace std;

class search {

public:

int a[50], ele;

int linearSearch(int array[], int key) {

int i = 0;

clock_t t1, t2;

t1 = clock();

for (i = 0; i < 50; i++) {

if (array[i] == key) {

return i;

}

i++;

}

t2 = clock();

cout << "The time taken to execute linear search is "

<< (t2 - t1) / CLOCKS_PER_SEC << " seconds" << endl;

return -1;

}

};

int main() {

search s;

int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int key = 5;

int index = s.linearSearch(array, key);

if (index == -1) {

cout << "The target element is not found." << endl;

} else {

cout << "The target element is found at index " << index << endl;

}

return 0;

}
```
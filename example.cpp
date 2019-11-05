#include <iostream>
#include <cstdlib>
#include <ctime>
#include "main.cpp"
using namespace std;

int main(){
        linkedList &arr = *(new linkedList);

        srand(time(NULL));

        // Append function example.
        for(int i = 0; i < 5; i++) {
                arr.append(rand()%10+5);
        }

        // Accessing all of list's elements example.
        cout << arr;

        // Reverse function example.
        arr.reverse();
        cout << arr;

        // Sort function example.
        arr.sort();
        cout << arr;

        // Access element with using [] example.
        cout << arr[2] << endl;

        // Del function example.
        arr.del(-1);
        cout << arr;

        // Remove function example.
        arr.remove(arr[2]);
        cout << arr;

        // Index function example.
        cout << arr.index(arr[2]) << endl;

        // Count function example.
        cout << arr.count(arr[2]) << endl;

        // Insert function example.
        arr.insert(2,-1);
        cout << arr;

        // Extend function example.
        linkedList &newArr = *(new linkedList);
        for (int i = 0; i < 5; i++)
                newArr.append(rand()%10+5);
        arr.extend(&newArr);
        cout << arr;

        // Sum of two list example.
        linkedList &newArr2 = *(new linkedList);
        for (int i = 0; i < 5; i++)
                newArr2.append(rand()%10+5);
        linkedList &newArr3 = *(arr+newArr2);
        cout << newArr3;

        // Copy function example.
        linkedList &newArr4 = *(newArr3.copy());
        cout << newArr4;

        return 0;
}

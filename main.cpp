#include <iostream>

using namespace std;

void printArray(int *a, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << " " << a[i] << (i == n - 1 ? "" : ",");
    }
    cout << "]" << endl;
}

// startet bei 0 und geht bis m-1
void shiftdown(int *a ,int i, int m){
    while (2 * i + 1 < m){ // hat linken Nachfolger
        int j = 2 * i + 1; // linker Nachfolger
        if (j < m - 1) {   // hat rechten Nachfolger
            if (a[j]< a[j+1])
                j = j + 1; // a[j] ist der größere
        }
        if (a[i] < a[j]){  // a[i] muss versickern
            int t = a[i];
            a[i] = a [j];
            a[j] = t;
            i = j;          // weiter verickern
        } else
            i = m;         // fertig
    }
}

void heapsort(int *a, int n){
    // stelle Anfangsheap her
    for (int i = n /2; i >= 0; i--)
        shiftdown(a, i, n);
    for (int i = n - 1; i > 0; i--){
        // tausche a[0] mit a[i], versickere a[0]
        int t = a[i];
        a[i] = a[0];
        a[0] = t;
        shiftdown(a, 0 ,i);
    }
}

int main() {
    int a[] = {15, 2, 43, 17, 4, 8, 47, 12};
    cout << "a = ";
    printArray(a, 8);
    cout << "Heapsort: ";
    heapsort(a, 8);
    printArray(a, 8);
    return 0;
}
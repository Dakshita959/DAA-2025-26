#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int heapArr[MAX];
int heapSize = 0;

void heapifyUp(int i) {
    while (i > 0 && heapArr[(i - 1) / 2] > heapArr[i]) {
        swap(heapArr[(i - 1) / 2], heapArr[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize && heapArr[left] < heapArr[smallest])
            smallest = left;

        if (right < heapSize && heapArr[right] < heapArr[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(heapArr[i], heapArr[smallest]);
        i = smallest;
    }
}

void insert(int val) {
    if (heapSize == MAX) {
        cout << "Heap is full\n";
        return;
    }

    heapArr[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize - 1);
}

int search(int x) {
    for (int i = 0; i < heapSize; i++) {
        if (heapArr[i] == x)
            return i;
    }
    return -1;
}

void deleteIndex(int idx) {
    if (idx < 0 || idx >= heapSize) {
        cout << "Invalid index\n";
        return;
    }

    heapArr[idx] = heapArr[heapSize - 1];
    heapSize--;

    if (heapSize == 0)
        return;

    int parent = (idx - 1) / 2;

    if (idx > 0 && heapArr[idx] < heapArr[parent])
        heapifyUp(idx);
    else
        heapifyDown(idx);
}

void deleteValue(int x) {
    int idx = search(x);

    if (idx == -1) {
        cout << "Value not found\n";
        return;
    }

    deleteIndex(idx);
}

void display() {
    cout << "Heap: ";
    for (int i = 0; i < heapSize; i++)
        cout << heapArr[i] << " ";
    cout << endl;
}

int main() {
    insert(3);
    insert(12);
    insert(9);
    insert(2);

    display();
    cout << "Index of 9: " << search(9) << endl;
    deleteValue(3);
    display();

    return 0;
}



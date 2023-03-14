#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class HashTable {
private:
    int size;
    vector<list<pair<int, float>>> table; // rješenje chaina
    vector<int> a;

int hash(int key) {
    int sum = 0;
    int n = 0;

    while (key > 0) {
        int digit = key % 10;
        sum += a[n++] * digit;
        key /= 10;
    }

    return sum % size;
}
public:
    HashTable(int s) {
    size = s;
    table.resize(size);
    a.resize(7);

    srand(time(NULL));

    for (int i = 0; i < 7; i++) {
        a[i] = rand() % 7;
    }
}

void insert(int key, float value) {
    int index = hash(key);
    auto& cell = table[index];

    for (auto itr = cell.begin(); itr != cell.end(); itr++) {
        if (itr->first == key) {
            itr->second = value;
            return;
        }
    }

    cell.emplace_back(key, value);
}

float search(int key) {
    int index = hash(key);
    auto& cell = table[index];

    for (auto itr = cell.begin(); itr != cell.end(); itr++) {
        if (itr->first == key) {
            return itr->second;
        }
    }

    return -1;
}
};

int main() {
HashTable ht(7);

ht.insert(123, 3.14);
ht.insert(456, 6.89);
ht.insert(789, 32.32);

cout << ht.search(123) << endl;
cout << ht.search(456) << endl;
cout << ht.search(789) << endl;

return 0;
}
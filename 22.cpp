#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

//By asoocomtw
bool sorted_asc_desc(int asc, int left, int right) {
    if(asc)
        return left > right;
    else
        return left < right;
}

int main() {
    fstream ifs("123.txt", ios::in);
    int count = 0;
    int num[100] = { 0 };

    int sort = 0;
    ifs >> sort;
    cout << sort << endl;

    while (ifs >> num[count]) {
        cout << num[count] << " ";
        count++;
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < i; j++) {
            if (sorted_asc_desc(sort, num[i], num[j])) {
                int sw = num[j];
                num[j] = num[i];
                num[i] = sw;
            }
        }
    }

    cout << "\nAns=";
    for (int i = 0; i < count; i++) {
        cout << num[i] << " ";
    }

    return 0;
}
#include<iostream>
using namespace std;

int main() {
    FILE *file = fopen("123.txt", "r+");
    int day;
    int mon;
    fscanf(file, "%d %d", &mon, &day);

    int mons[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int total = 0;

    for(int i = 0; i < mon; i++) {
        total += mons[i];
    }
    total += day;

    printf("Ans=%d\n", total % 7);
}

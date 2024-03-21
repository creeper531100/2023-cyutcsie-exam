#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream ifs("123.txt");
    string boom;
    string check;

    ifs >> boom >> check;
    cout << boom << endl;
    cout << check << endl;

    int A = 0;
    int B = 0;

    for (int i = 0; i < boom.length(); ++i) {
        if (boom[i] == check[i]) {
            A++;
        }
        else if (check.find(boom[i]) != std::string::npos) {
            B++;
        }
    }

    printf("Ans=%dA%dB\n", A, B);

    return 0;
}
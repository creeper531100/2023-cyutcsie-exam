#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string res;
    ifstream ifs("123.txt");

    getline(ifs, res);
    cout << res << endl;

    size_t beg = 0;
    size_t pos = 0;
    string ans;

    do {
        pos = res.find_first_of("~@%", beg + 1);
        string substr = res.substr(beg, pos - beg);
        beg = res.find_first_of("~@%", pos);

        stringstream ss(substr);

        char op;
        int len;
        string content;
        ss >> op >> len >> content;

        switch (op) {
        case '~':
            reverse(content.begin(), content.begin() + len);
            ans += content;
            break;
        case '@':
            ans = ans.substr(len) + content;
            break;
        case '%':
            ans = ans.substr(0, ans.length() - len) + content;
            break;
        default:
            ans += substr;
            break;
        }
    } while (beg != std::string::npos);

    cout << "Ans=" << ans << endl;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> ones = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine " };
    vector<string> teens = { "", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };
    vector<string> tens = { "", "ten-", "twenty-", "thirty-", "forty-", "fifty-", "sixty-", "seventy-", "eighty-", "ninety-" };
    vector<string> thousands = { "million ", "thousand ", "" };
    vector<string> hundred = {"", "hundred "};

    string res = "123241652";
    string ans;
    for (int i = 0; i < res.length() ; i += 3) {
        int number = atoi(res.substr(i, 3).c_str());
        int hundreds_digit = number / 100;
        int tens_digit = number % 100;

        ans += ones[hundreds_digit] + hundred[hundreds_digit != 0 && tens_digit != 0];

        if(tens_digit / 10 == 1) {
            ans += teens[tens_digit / 10];
        }
        else {
            ans += tens[tens_digit / 10] + ones[tens_digit % 10];
        }
        ans += thousands[i / thousands.size()];
    }
    printf("%s", ans.c_str());
}
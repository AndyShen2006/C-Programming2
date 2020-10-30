#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 10087;

int sub[MAX_SIZE], a[MAX_SIZE], b[MAX_SIZE];
int main()
{
    string strA, strB;
    cin >> strA >> strB;
    bool isABTB;
    if (strA.size() > strB.size())
        isABTB = true;
    else {
        for (int i = 0; i < strA.size(); i++) {
            if (strA[i] > strB[i]) {
                isABTB = true;
                break;
            }
        }
    }
    if (!isABTB)
        swap(strB, strA);
    int maxl = strA.size();
    for (int i = 0; i < maxl; i++) {
        a[i] = strA[i] - '0';
        b[i] = strB.size() != (maxl - i) ? 0 : strB[i];
    }
    for (int i = 0; i < maxl; i++) {
        if (a[i] < b[i])
            a[i + 1]--, a[i] += 10;
        sub[i] = a[i] - b[i];
    }
    bool isValid = false;
    for (int i = 0; i < maxl; i++) {
        if (!isValid && sub[i] != 0)
            isValid = true;
        if (isValid)
            cout << sub[i];
    }
    if (strA == strB)
        cout << 0;
    return 0;
}
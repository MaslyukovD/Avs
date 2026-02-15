#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    char s[256];
    cin >> s;

    int n = strlen(s);
    int start = 0;

    if (s[0] == '+' || s[0] == '-') start = 1;

    if (start >= n) {
        cout << "Некорректно\n";
        return 0;
    }

    if (start + 1 < n && s[start] == '0' && (s[start + 1] == 'x' || s[start + 1] == 'X'))
        start += 2;

    if (start >= n) {
        cout << "Некорректно\n";
        return 0;
    }

    for (int k = start; k < n; k++) {
        char c = s[k];

        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'F') ||
            (c >= 'a' && c <= 'f')) {
            continue;
        }

        cout << "Некорректно\n";
        return 0;
    }

    cout << "Корректно\n";
    return 0;
}

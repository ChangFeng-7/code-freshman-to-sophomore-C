#include <iostream>

using namespace std;

class String {
public:
    char *str;
public:
    ~String() { delete[]str; }

    const char *c_str() { return str; }

    String() : str(NULL) {}

    String &operator=(char *s);
};

String &String::operator=(char *s) {
    if (str)
        delete[]str;
    if (s) {
        str = new char(strlen(s) + 1);
        strcpy(str, s);
    } else {
        str = NULL;
    }
    return *this;
}

int main() {
    String a;
    a = "等号运算符的重载";
    cout << a.str;
    return 0;
}
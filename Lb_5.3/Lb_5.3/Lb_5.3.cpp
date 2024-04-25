#include <iostream>
#include <cstring>

class MyString {
protected:
    char* str;

public:
    MyString() {
        str = new char[1];
        str[0] = '\0';
    }

    MyString(const char* s) {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy_s(str, len + 1, s);
    }

    MyString(const MyString& other) {
        int len = strlen(other.str);
        str = new char[len + 1];
        strcpy_s(str, len + 1, other.str);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            int len = strlen(other.str);
            str = new char[len + 1];
            strcpy_s(str, len + 1, other.str);
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }

    friend std::ostream& operator<<(std::ostream& out, const MyString& s) {
        out << s.str;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, MyString& s) {
        char temp[1000];
        in >> temp;
        int len = strlen(temp);
        delete[] s.str;
        s.str = new char[len + 1];
        strcpy_s(s.str, len + 1, temp);
        return in;
    }
};

class DigitString : public MyString {
public:
    DigitString() : MyString() {}

    DigitString(const char* s) : MyString(s) {}

    DigitString(const DigitString& other) : MyString(other) {}

    DigitString& operator=(const DigitString& other) {
        MyString::operator=(other);
        return *this;
    }
};

int main() {
    MyString s1("Hello");
    std::cout << "s1: " << s1 << std::endl;

    MyString s2;
    std::cin >> s2;
    std::cout << "s2: " << s2 << std::endl;

    MyString s3 = s1;
    std::cout << "s3: " << s3 << std::endl;

    s3 = "World";
    std::cout << "s3: " << s3 << std::endl;

    DigitString ds1("12345");
    std::cout << "ds1: " << ds1 << std::endl;

    DigitString ds2;
    std::cin >> ds2;
    std::cout << "ds2: " << ds2 << std::endl;

    DigitString ds3 = ds1;
    std::cout << "ds3: " << ds3 << std::endl;

    ds3 = "67890";
    std::cout << "ds3: " << ds3 << std::endl;
    return 0;
}


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class MyString {
    char* p;
    
public:
    MyString() : p(nullptr) {
        cout << "Inside default constructor" << endl;
    }

    MyString(const char* arg) {
        p = new char[strlen(arg) + 1];
        strcpy(p, arg);
        cout << "Inside parameterized constructor" << endl;
    }

    MyString(const MyString& obj) {
        p = new char[strlen(obj.p) + 1];
        strcpy(p, obj.p);
        cout << "Inside copy constructor" << endl;
    }

    MyString& operator=(const MyString& obj) {
        if (this != &obj) {
            delete[] p;
            p = new char[strlen(obj.p) + 1];
            strcpy(p, obj.p);
        }
        cout << "Inside assignment operator" << endl;
        return *this;
    }

    ~MyString() {
        delete[] p;
        cout << "Inside destructor" << endl;
    }

    int lengthOfString() const {
        return p ? strlen(p) : 0;
    }

    void concat(const MyString& obj) {
        if (p == nullptr) {
            p = new char[strlen(obj.p) + 1];
            strcpy(p, obj.p);
        } else {
            char* newStr = new char[strlen(p) + strlen(obj.p) + 1];
            strcpy(newStr, p);
            strcat(newStr, obj.p);
            delete[] p;
            p = newStr;
        }
    }

    bool containsSubstring(const MyString& sub) const {
        if (p == nullptr || sub.p == nullptr) return false;
        return strstr(p, sub.p) != nullptr;
    }

    void removeCharacter(char ch) {
        if (p == nullptr) return;
        
        int len = strlen(p);
        int newLength = 0;

        for (int i = 0; i < len; ++i) {
            if (p[i] != ch) {
                ++newLength;
            }
        }

        char* newStr = new char[newLength + 1];
        int index = 0;
        
        for (int i = 0; i < len; ++i) {
            if (p[i] != ch) {
                newStr[index++] = p[i];
            }
        }

        newStr[newLength] = '\0';
        delete[] p;
        p = newStr;
    }

    const char* getString() const {
        return p ? p : "";
    }
};

int main() {
    MyString str1("Hello");
    MyString str2("World");
    MyString str3("This is a test");

    str1.concat(str2);
    cout << "After concatenation: " << str1.getString() << endl;

    cout << "Does str1 contain 'World'? " << (str1.containsSubstring("World") ? "Yes" : "No") << endl;
    cout << "Does str1 contain 'Test'? " << (str1.containsSubstring("Test") ? "Yes" : "No") << endl;

    str1.removeCharacter('o');
    cout << "After removing 'o': " << str1.getString() << endl;

    MyString str4 = str3;
    str4.removeCharacter(' ');
    cout << "After removing spaces from str4: " << str4.getString() << endl;

    return 0;
}

cout

#include <iostream>
#include <sstream>
 
int main() {
    std::string data = "somasekhar 21 180.5";
    std::string name;
    int age;
    double height;
 
    std::stringstream ss(data);
    ss >> name >> age >> height; // Extracts multiple values from the string
 
    std::cout << "Name: " << name << ", Age: " << age << ", Height: " << height << std::endl;
    // Outputs: Name: John, Age: 25, Height: 180.5
    return 0;
}

OUTPUT:
Name: Somasekhar, Age:21, Height :180.5

string length

#include<iostream>
 
 
using namespace std;
 
int main(){
    string s;
    cout<<s.length()<<" " <<s.capacity()<<endl;
 
    string s1="dsd";
    cout<<s1.length()<<" "<<s1.capacity()<<endl;
 
    string s2="abcdefghijklmno";
    cout<<s2.length()<<" "<<s2.capacity()<<endl;
 
    string s3="abcdefghijklmnopqrst";
    cout<<s3.length()<<" "<<s3.capacity()<<endl;
 
    string s4="abcdefghijklmnopqrstuvwxyz12345";
    cout<<s4.length()<<" "<<s4.capacity()<<endl;
    return 0;
}

OUTPUT:
0 15
3 15
15 15
20 20
31 31

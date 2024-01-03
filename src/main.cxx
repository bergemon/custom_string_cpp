#include "../include/custom_string.hpp"

int main(int argc, char** argv) {
    using namespace my_str;

    const string s1 = "Hello";
    const string s2 = ", World!";
    const string s3 = s1 + s2;
    string s4 = "Hey! ";
    s4 += s3;

    std::cout << s4 << "\nlength: " << s4.length() << std::endl;

    return 0;
}
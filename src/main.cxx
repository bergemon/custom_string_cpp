#include "../include/custom_string.hpp"
#include "../include/dependencies.hpp"

int main(int argc, char** argv) {
    using namespace my_str;

    string s1 = "Hello";
    string s2 = ", World!";
    string s3 = s1 + s2;
    string s4 = "Hey! ";
    s4 += s3;

    std::cout << s4 << "\nlength: " << s4.length() << std::endl;
    std::cout << s4.find("World") << std::endl;

    return 0;
}
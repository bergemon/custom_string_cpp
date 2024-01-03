#include "../include/custom_string.hpp"

int main(int argc, char** argv) {
    using namespace my_str;

    const String s1 = "Hello";
    const String s2 = ", World";


    // const String s3 = s1 + s2;

    std::cout << s1.length() << std::endl;
    std::cout << s2.length() << std::endl;
    // // std::cout << s3 << std::endl;

    return 0;
}
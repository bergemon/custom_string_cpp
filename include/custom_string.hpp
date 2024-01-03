#include "dependencies.hpp"

namespace my_str {
    class String {
        char* m_str;
        uint32_t m_length = 0;
        char& operator[](uint32_t i) const { return m_str[i]; }

    public:
        // Constructors
        String() {}
        String(const char* str) {
            char currentChar;
            while(currentChar != '\0') {
                currentChar = str[m_length++];
                std::cout << currentChar << std::endl;
            }

            m_str = new char[m_length];
            uint32_t i = m_length;
            while(i > 0)
                m_str[i] = str[--i];
        }
        String(const String& str) {
            m_length = str.length();
            m_str = new char[m_length];
            uint32_t i = m_length;
            while(i > 0)
                m_str[i] = str[--i];
        }
        // Destructor
        ~String() { delete[] m_str; }

        // Getters
        uint32_t length() const { return m_length; }
        char* begin() const { return m_str; }
        char* end() const { return m_str + m_length; }

        // Type conversation
        operator char*() const { return m_str; }

        // Operator= with another String class
        String& operator=(const String& str) {
            delete[] m_str;

            char currentChar;
            m_length = 0;
            while(currentChar != '\0')
                currentChar = str[m_length++];

            m_str = new char[m_length];
            uint32_t i = m_length;
            while(i > 0)
                m_str[i] = str[--i];

            return *this;
        }
        // Operator= with char pointer
        String& operator=(const char* str) {
            delete[] m_str;
            const String tempStr = str;

            return *this += tempStr;
        }

        // Operator+= with another String class
        String& operator+=(const String& str) {
            String tempStr = m_str;
            delete[] m_str;

            uint32_t accumLength = m_length + str.length();
            m_str = new char[accumLength];

            uint32_t i = m_length;
            while(i > 0)
                m_str[i] = tempStr[--i];

            i = accumLength;
            while(i > m_length)
                m_str[i] = str[--i];

            m_length = accumLength;

            return *this;
        }

        // Operator+= with char pointer
        String& operator+=(const char* str) {
            String tempStr = str;

            *this += tempStr;

            return *this;
        }
    };
}

my_str::String operator+(const my_str::String& firstStr, const my_str::String& secondStr) {
    my_str::String newStr = firstStr;
    newStr += secondStr;

    return newStr;
}
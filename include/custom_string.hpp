#include "dependencies.hpp"

namespace my_str {
    class string {
        char* m_str;
        uint32_t m_length = 0;
        char& operator[](uint32_t i) const { return m_str[i]; }

    public:
        // Constructors
        string() {}
        string(const char* str) {
            char currentChar = str[0];
            while(currentChar != '\0')
                currentChar = str[m_length++];

            m_str = new char[m_length];
            uint32_t i = m_length;
            while(i > 0)
                m_str[i] = str[--i];
        }
        string(const string& str) {
            m_length = str.length();
            m_str = new char[m_length];
            uint32_t i = m_length;
            while(i > 0)
                m_str[i] = str[--i];
        }
        // Destructor
        ~string() { delete[] m_str; }

        // Getters
        uint32_t length() const { return m_length; }
        char* begin() const { return m_str; }
        char* end() const { return m_str + m_length; }

        // Type conversation
        operator char*() const { return m_str; }

        // Operator+= with another string class
        string& operator+=(const string& str) {
            string tempStr = m_str;
            delete[] m_str;

            uint32_t accumLength = --m_length + str.length();
            m_str = new char[accumLength];

            uint32_t i = m_length;
            while(i > 0)
                m_str[i] = tempStr[--i];

            i = accumLength;
            while(i > m_length)
                m_str[i] = str[--i - m_length];

            m_length = accumLength;

            return *this;
        }

        // Operator+= with char pointer
        string& operator+=(const char* str) {
            string tempStr = str;

            *this += tempStr;

            return *this;
        }

        // Operator= with another String class
        string& operator=(const string& str) {
            delete[] m_str;

            char currentChar = str[0];
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
        string& operator=(const char* str) {
            delete[] m_str;
            const string tempStr = str;

            return *this += tempStr;
        }
    };
}

my_str::string operator+(const my_str::string& firstStr, const my_str::string& secondStr) {
    my_str::string newStr = firstStr;
    newStr += secondStr;

    return newStr;
}
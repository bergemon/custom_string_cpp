#include <cstdint>

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
            for (int i = 0;;++i) {
                if (currentChar != '\0') {
                    currentChar = str[i];
                }
                else {
                    m_length = i;
                    break;
                }
            }

            m_str = new char[m_length];
            for (int i = 0; i < m_length; ++i)
                m_str[i] = str[i];
        }
        string(const string& str) {
            m_length = str.length() + 1;
            m_str = new char[m_length];
            for (int i = 0; i < m_length; ++i)
                m_str[i] = str[i];
        }
        // Destructor
        ~string() { delete[] m_str; }

        // Getters
        uint32_t length() const { return m_length - 1; }
        char* begin() const { return m_str; }
        char* end() const { return m_str + length(); }

        // Type conversation
        operator char*() const { return m_str; }

        // Operator+= with another string class
        string& operator+=(const string& str) {
            string tempStr = m_str;

            if (m_str != nullptr) { delete[] m_str; }
            if (m_length > 0) { --m_length; }

            uint32_t accumLength = m_length + (str.length() + 1);
            m_str = new char[accumLength];

            for (int i = 0; i < m_length; ++i)
                m_str[i] = tempStr[i];

            for (int a = m_length, b = 0; a < accumLength; ++a, ++b)
                m_str[a] = str[b];

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

            m_length = str.length() + 1;
            m_str = new char[m_length];
            for (int i = 0; i <= m_length; ++i) {
                m_str[i] = str[i];
            }

            return *this;
        }

        // Operator= with char pointer
        string& operator=(char* str) {
            delete[] m_str;
            m_str = nullptr;
            m_length = 0;
            string tempStr = str;

            return *this += tempStr;
        }

        // Find substring in this string
        int64_t find(const char* str) {
            int64_t str_length = 0;
            char checkSymbol;
            for (; checkSymbol != '\0'; ++str_length) {
                checkSymbol = str[str_length];
            }

            int64_t iter = 0;
            int64_t substr_s = 0;

            for (const char& elem : *this) {
                if (elem == str[substr_s] && substr_s != str_length)
                {
                    ++substr_s;
                }
                else if (elem == str[substr_s] && substr_s == str_length)
                {
                    return iter;
                }
                else if (elem != str[substr_s] && substr_s > 0)
                {
                    substr_s = 0;
                    if(elem == str[substr_s]) { ++substr_s; }
                }
                else { substr_s = 0; }

                ++iter;
            }

            return -1;
        }
    };
}

my_str::string operator+(const my_str::string& firstStr, const my_str::string& secondStr) {
    my_str::string newStr = firstStr;
    newStr += secondStr;

    return newStr;
}
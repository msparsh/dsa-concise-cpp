#include <iostream>
#include <string>

int naiveSearch(const std::string & text, const std::string & pattern)
{
    int len_text = text.length();
    int len_pattern = pattern.length();

    for (int i = 0; i <= len_text - len_pattern; i++)
    {
        if (pattern == text.substr(i, len_pattern))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::string text = "AABBCCDDABCDAJBFSJBJBFJBSJBFMABCDV";
    std::string pattern = "ABCD";
    int ret = naiveSearch(text, pattern);
    if (ret == -1)
    {
        std::cout << "Did not find pattern in text" << std::endl;
        return 0;
    }
    std::cout << "Found pattern at index " << ret << std::endl;
    return 0;
}
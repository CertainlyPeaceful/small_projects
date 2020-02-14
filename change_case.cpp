#include <iostream>
#include <string>

void convert(std::string &string, void (*function)(std::string &, int))
{
    static int index = 0;
    if (index == string.size())
    {
        index = 0;
        return;
    }
    function(string, index);
    ++index;
    convert(string, function);
}

int main()
{
    auto upper_to_lower = [](std::string &string, int index) {
        if (string[index] >= 'A' && string[index] <= 'Z')
            string[index] = string[index] + 32;
    };
    auto lower_to_upper = [](std::string &string, int index) {
        if (string[index] >= 'a' && string[index] <= 'z')
            string[index] = string[index] - 32;
    };

    bool continue_loop = true;
    std::string str;
    std::string again;
    int input = 0;

    while (continue_loop)
    {
        std::cout << "Enter a string to convert: ";
        std::getline(std::cin, str);
        std::cout << "Lowercase to uppercase (1) or uppercase to lowercase (2): ";
        std::cin >> input;

        switch (input)
        {
        case 1:
            convert(str, lower_to_upper);
            std::cout << str << std::endl;
            break;
        case 2:
            convert(str, upper_to_lower);
            std::cout << str << std::endl;
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
        }

        std::cin.get();

        std::cout << "Another string? (y/n): ";
        std::getline(std::cin, again);
        if (again != "y")
            continue_loop = false;
    }
}
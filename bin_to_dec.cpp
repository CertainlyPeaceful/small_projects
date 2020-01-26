// Converts binary to decimal

#include <iostream>

int getPower(int power)
{
    if (power == 0) // 2^0 = 1
        return 1;
    else if (power == 1)
        return 2;
    return 2 * getPower(power - 1);
}

int main()
{
    std::string input;

    std::cout << "Enter a binary number: ";
    std::cin >> input;

    int decimal = 0;

    for (int index = 0; index < input.size(); ++index)
    {
        if (input[index] == '1')
            decimal += getPower(input.size() - index - 1);
    }

    std::cout << "In decimal form: " << decimal << '\n';
}
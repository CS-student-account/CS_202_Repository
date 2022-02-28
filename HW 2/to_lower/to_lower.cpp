/*
* to_lower.cpp
* David Misyura
* 27 Feb 2022
* HW 2 for CS 202
*/

#include <iostream>
using std::cout;
using std::endl;

void to_lower(char* s)
{
    for (; *s != '\0'; ++s) //iterate until 0 is reached at end of C-string
    {
        *s |= (1 << 5); //sets the fifth bit of the char to 1
                        //using bitwise operator
    }
}

int main()
{
    char string[] = { 'H', 'E', 'L', 'L', 'O', ',', ' ', 'W', '0', 'R', 'L', 'D', '!', '\0'};
    cout << string << endl;

    to_lower(string);
    cout << string << endl;

    return 0;
}
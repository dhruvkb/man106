#include <iostream>
#include <cstring>

#define MAX 50

using namespace std;

int main()
{
    char str[MAX] = "Good Evening";

    int charCount, vowelCount = 0;

    charCount = strlen(str);
    
    cout << "Character count: " << charCount << endl;

    for (int i = 0; i < charCount; i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowelCount++;
        }
    }

    cout << "Vowel count: " << vowelCount << endl;
    cout << "Uppercase: " << str << endl;

    return 0;
}

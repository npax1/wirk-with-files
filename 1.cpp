#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    string line1, line2;
    int lineNumber = 1;

    while (getline(file1, line1) && getline(file2, line2))
    {
        if (line1 != line2)
        {
            cout << "Lines at line number " << lineNumber << " don't match:\n"
                << "File 1: " << line1 << '\n'
                << "File 2: " << line2 << '\n';
            return 0;
        }
        ++lineNumber;
    }

    if (std::getline(file1, line1))
    {
        cout << "File 1 has additional lines starting at line number " << lineNumber << ":\n"
            << line1 << '\n';
    }

    if (getline(file2, line2))
    {
        std::cout << "File 2 has additional lines starting at line number " << lineNumber << ":\n"
            << line2 << '\n';
    }

    return 0;
}
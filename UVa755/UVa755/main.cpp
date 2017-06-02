#include <iostream>
#include <cctype>
#include <string>
#include <map>
using namespace std;

const string table = "2223334445556667 77888999 ";
map<string, size_t> dataMap;

string Parsing(const string& input)
{
    string output;
    for (char character : input)
    {
        if (isupper(character))
        {
            character = table[character - 'A'];
        }
        else if (character == '-')
        {
            continue;
        }
        output.push_back(character);
    }
    return  output.insert(3, 1, '-');
}

void RecordResult(const string& input)
{
    try
    {
        ++dataMap.at(input);
    }
    catch (out_of_range)
    {
        dataMap[input] = 1;
    }
}

void ShowResult()
{
    bool hasDuplicate = false;

    for (auto& element : dataMap)
    {
        if (element.second == 1)
        {
            continue;
        }
        hasDuplicate = true;
        cout << element.first << " " << element.second << endl;
    }

    if (!hasDuplicate)
    {
        cout << "No duplicates." << endl;
    }
}

int main()
{
    int datasetsNum = 0;
    
    cin >> datasetsNum;
    cin.ignore(1, '\n');

    while (datasetsNum--)
    {
        int telephoneNums;
        cin >> telephoneNums;
        cin.ignore(1, '\n');
        while (telephoneNums--)
        {
            string telephoneNumber;
            cin >> telephoneNumber;
            RecordResult(Parsing(telephoneNumber));
        }

        ShowResult();
        dataMap.clear();

        if (datasetsNum)
        {
            cout << endl;
        }
    }
    return 0;
}


#include <iostream>
#include <string>
#include <map>
using namespace std;

const char table[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7',' ','7','7','8','8','8','9','9','9',' '};
map<string, size_t> dataMap;

string Parsing(const string& input)
{
    string output;
    for (char character : input)
    {
        if ('A' <= character && character <= 'Z')
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
        if (dataMap.at(input))
        {
            ++dataMap[input];
        }
    }
    catch (out_of_range)
    {
        dataMap[input] = 1;
    }
}

void ShowResult()
{
    bool noDuplicate = true;

    for (auto& element : dataMap)
    {
        if (element.second == 1)
        {
            continue;
        }
        noDuplicate = false;
        cout << element.first << " " << element.second << endl;
    }

    if (noDuplicate)
    {
        cout << endl << "No duplicates.";
    }
    cout << endl;
}

int main()
{
    int datasetsNum = 0;
    
    cin >> datasetsNum;
    cin.ignore(1, '\n');

    while (--datasetsNum >= 0)
    {
        int telephoneNums;
        cin >> telephoneNums;
        cin.ignore(1, '\n');
        while (--telephoneNums >= 0)
        {
            string telephoneNumber;
            getline(cin, telephoneNumber,'\n');
            RecordResult(Parsing(telephoneNumber));
        }

        ShowResult();
        dataMap.clear();
    }
    return 0;
}


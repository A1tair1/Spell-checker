#include <string>
#include <vector>
#include <list>
#include <iostream>
using namespace std;


vector<string> dictionary;
vector<string> words;

void get_input(vector<string>& source)
{
    string tmp;
    do
    {
        cin >> tmp;
        if (tmp == "===")
            break;
        source.push_back(tmp);
    } while (1);
}

int get_letter(string &str, int n) // Áåçîïàñíîå ïîëó÷åíèå áóêâû, íå÷óñòâèòåëüíîå ê ðåãèñòðó.
{
    if (n < str.size())
        return toupper(str[n]);
    else
        return -1;
}

int check_similar(string a, string b) // Ïðîâåðêà ñëîâ íà ñõîäñòâî (À - Ñëîâàðíîå ñëîâî, B - Ïðîâåðÿåìîå ñëîâî)
{
    int inserted = 0;
    int deleted = 0;
    int size_a = a.size();
    int size_b = b.size();
    int size = a.size() > b.size() ? a.size() : b.size();
    for (int i_a = 0, i_b = 0; i_a < size || i_b < size;)
    {
        if (get_letter(a,i_a) != get_letter(b,i_b))
        {
            
            if (get_letter(a, i_a) == get_letter(b, i_b + 1)) // Åñëè áóêâà âñòàâëåíà
            {
                inserted++;
                i_b++;
            }
            else if (get_letter(a, i_a + 1) == get_letter(b, i_b)) // Åñëè áóêâà óäàëåíà
            {
                deleted++;
                i_a++;
            }
           

            
            else if (get_letter(b, i_b) == -1) // Åñëè áóêâ â ñëîâå èç ñëîâàðÿ áîëüøå ÷åì â ïðîâåðÿåìîì
            {
                deleted++;
            }
            else // Åñëè çàìåíà áóêâû - (abc -> arc)
            {
                deleted++;
                inserted++;
            }
        }
        i_a++;
        i_b++;

    }
//    cout << deleted << " " << inserted << "\n";
    return deleted + inserted;
}

void find_similar() // Ïîèñê ñëîâ â dictionary, ïîõîæèõ íà words[j]
{
    for (int j = 0; j < words.size(); ++j)
    {
        list<string> result_output;
        int max_changes = 3;

        for (int i = 0; i < dictionary.size(); ++i)
        {
            int count_changes = check_similar(dictionary[i], words[j]);
            if (count_changes < max_changes)
            {
                max_changes = count_changes;
                result_output.clear();
                result_output.push_back(dictionary[i]);
            }
            else if(count_changes == max_changes)
            {
                result_output.push_back(dictionary[i]);
            }

        }

        // Âûâîä ðåçóëüòàòîâ
        if (result_output.empty())
            cout << "{ " << words[j] << "? } ";
        else if (result_output.size() == 1)
            cout << result_output.front() << " ";
        else
        {
            cout << "{ ";
            for (string n : result_output)
                std::cout << n << " ";
            cout << "} ";
        }
    }
}

int main()
{

    get_input(dictionary);
    get_input(words);
    find_similar();

}

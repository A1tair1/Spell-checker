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

int get_letter(string &str, int n) // Безопасное получение буквы, нечуствительное к регистру.
{
    if (n < str.size())
        return toupper(str[n]);
    else
        return -1;
}

int check_similar(string a, string b) // Проверка слов на сходство (А - Словарное слово, B - Проверяемое слово)
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
            
            if (get_letter(a, i_a) == get_letter(b, i_b + 1)) // Если буква вставлена
            {
                inserted++;
                i_b++;
            }
            else if (get_letter(a, i_a + 1) == get_letter(b, i_b)) // Если буква удалена
            {
                deleted++;
                i_a++;
            }
           

            
            else if (get_letter(b, i_b) == -1) // Если букв в слове из словаря больше чем в проверяемом
            {
                deleted++;
            }
            else if (abs(size_a - size_b) == 2)
            {
                if (get_letter(a, i_a + 2) == get_letter(b, i_b)) // Если пара удалений
                {
                    deleted++;
                    deleted++;
                    i_a++;
                    i_a++;
                }
                else if (get_letter(a, i_a) == get_letter(b, i_b + 2)) // Если пара вставок
                {
                    inserted++;
                    inserted++;
                    i_b++;
                    i_b++;
                }
            }
            else // Если замена буквы - (abc -> arc)
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

void find_similar() // Поиск слов в dictionary, похожих на words[j]
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

        // Вывод результатов
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
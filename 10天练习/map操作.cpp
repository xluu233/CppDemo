#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    map<const char *, const char *> mp;
    map<const char *, const char *>::iterator iter;

    const char *key[10] = {"img", "text", "music"};
    const char *value[10] = {"xxx.jpg", "xxx.txt", "xxx.mp3"};

    // 插入
    for (size_t i = 0; i < 3; i++)
    {
        mp.insert(make_pair(key[i], value[i]));
    }

    // 遍历
    for (auto &item : mp)
    {
        cout << item.first << " - " << item.second << endl;
    }
    cout << "---------------------\n"
         << endl;

    // 插入
    mp["insert"] = "xxx.xxx";
    mp.insert(pair<const char *, const char *>("123", "xxx"));

    // c++17遍历方式
    for (auto &[key, value] : mp)
    {
        cout << key << " - " << value << endl;
    }

    cout << "---------------------\n" << endl;


    // 删除
    for (int i = 0; i < 3; i++)
    {
        for (iter = mp.begin(); iter != mp.end(); iter++)
        {
            if (strcmp(iter->first, key[i]) == 0)
            {
                cout << iter->first << " deleted" << endl;
                mp.erase(iter);
                //erase删除之后执行break，理论上不应该在循环中去删除map元素。
                break;
            }
        }
    }


    // iter遍历方式
    for (iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << " - " << iter->second << endl;
    }

    return 0;
}
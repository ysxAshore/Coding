#include <iostream>
#include <vector>
#include <map>
using namespace std;
// map初始化的方式
vector<string> letterCombinations(string digits)
{
    map<char, string> map_string = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    int len = digits.length() ? 1 : 0;
    vector<int> sub_len;
    sub_len.push_back(len);
    for (int i = 0; i < digits.length(); i++)
    {
        sub_len.push_back(map_string[digits[i]].size());
        sub_len[0] *= sub_len[i + 1];
    }
    for (int i = 1; i < digits.length(); i++)
    {
        sub_len[i] = sub_len[i - 1] / sub_len[i];
    }
    sub_len[digits.length()] = 1;
    vector<string> res;
    for (int i = 0; i < sub_len[0]; i++)
    {
        res.push_back("");
    }
    for (int i = 0; i < digits.length() - 1; i++)
    {
        string s = map_string[digits[i]];
        for (int j = 0; j < s.size(); j++)
        {
            for (int z = 0; z < sub_len[i + 1]; z++)
            {
                res[z + j * sub_len[i + 1]] += s[j];
            }
        }
    }
    string s = map_string[digits[digits.length() - 1]];
    int lay = sub_len[0] / s.size();
    for (size_t i = 0; i < lay; i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            res[lay * i + j] += s[j];
        }
    }

    return res;
}
int main()
{
    vector<string> s = letterCombinations("234");
    for (size_t i = 0; i < s.size(); i++)
    {
        cout << s[i] << "　";
    }

    return 0;
}

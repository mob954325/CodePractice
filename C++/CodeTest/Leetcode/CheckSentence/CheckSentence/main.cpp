#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int isPrefixOfWord(string sentence, string searchWord) {

    istringstream iss(sentence); // string을 시퀀스 단위로 쪼개는 함수
    string word;
    int index = 1;

    while (iss >> word)
    {
        if (word.find(searchWord) == 0)
        {
            return index;
        }

        index++;
    }

    return -1;
}

int main()
{
    string sentence = "i love eating burger";
    string search = "burg";

    isPrefixOfWord(sentence, search);
}
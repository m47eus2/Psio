#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

using WordList = std::map<std::string, int>;
using WordsVector = std::vector<std::pair<std::string, int>>;

void readWords(string &input, WordList &map)
{
    istringstream stream(input);
    regex pattern("(f|l|d)....+");
    string word;
    while(stream >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if(regex_match(word, pattern)) map[word]++;
    }
}

void mapToVector(WordList &map, WordsVector &vector)
{
    vector.resize(map.size());
    copy(map.begin(), map.end(), vector.begin());
    sort(vector.begin(), vector.end(), [&map](pair<string, int> &a, pair<string, int> &b){return map[a.first] > map[b.first];});
}

void printVector(WordsVector &v){
    for(auto it = v.begin(); it != v.end(); it++){
        cout << it -> first << " : "  << it -> second << endl;
    }
}

int main()
{
    WordList word_statistics;
    WordsVector words_statistics_vector;
    string inputData, message;
    
    while(cin){
        cin >> inputData;
        message += inputData + ' ';
    }
    
    readWords(message, word_statistics);
    mapToVector(word_statistics, words_statistics_vector);
    printVector(words_statistics_vector);
    return 0;
}
#ifndef TOKENIZER_H
#define TOKENIZER_HP

#include <string>
#include <vector>
using std::string;
using std::vector;

bool readLine(string &str);
unsigned stringToTokenWS(const string &input, vector<string> &tokens);
void analyzeTokens(const vector<string> &tokens);
bool readFile(const string& filename);
string excerpt(const string& filename);

#endif 
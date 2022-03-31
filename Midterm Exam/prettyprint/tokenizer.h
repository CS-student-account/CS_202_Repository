#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;

bool checkFile(const string &filename);
vector<string> lineToTokens(const string &line);
vector<string> readLines(const string &fileName);
void textWrap(ostream &os, const vector<string> &inputTokens, const int &wordWrap);

#endif 
#ifndef TOKENIZER_H
#define TOKENIZER_HP

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
using std::istream;

bool readLine(string &str);
unsigned stringToTokenWS(const string &input, vector<string> &tokens);
void analyzeTokens(const vector<string> &tokens);
bool readFile(const string& filename);
string excerpt(const string& filename);


struct TokenAndPosition 
{
	string _token;
	int _line;
	unsigned int _column;
};

vector<string> lineToTokens(const string& line);
vector<TokenAndPosition> readLines(istream& is);
void printTokens(ostream& os, const vector<TokenAndPosition>& tokens);

#endif 
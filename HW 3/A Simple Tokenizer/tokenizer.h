#ifndef FILE_TOKENIZER_HPP_INCLUDED
#define FILE_TOKENIZER_HPP_INCLUDED

#include <string>
#include <vector>

bool ReadLine(std::string &str);
unsigned StringToTokenWS(const std::string &input, std::vector<std::string> &tokens);
void AnalyzeTokens(const std::vector<std::string> &tokens);

#endif 
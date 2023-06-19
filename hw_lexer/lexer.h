#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "lexem.h"

namespace Lexer {
bool parseLexem(const std::string &word, LexWord &token);
std::vector<Lexem> lexIt(std::string line);
} // namespace Lexer

#endif // LEXER_H

#include "lexem.h"

namespace Lexer {
Lexem::Lexem(const LexWord type, const int line, const int column) : type(type), line(line), column(column)  {}
} // namespace Lexer

#ifndef LEXEM_H
#define LEXEM_H

namespace Lexer {
enum LexWord {
    ALetter,
    BLetter,
    ABLetters,
    BALetters,
    Space,
    Number,
    Unknown,
};

struct Lexem {
    int line = -1;
    int column = -1;
    LexWord type = Unknown;
    Lexem(const LexWord type, const int line, const int column);
};
} // namespace Lexer

#endif // LEXEM_H

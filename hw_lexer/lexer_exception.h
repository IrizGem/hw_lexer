#ifndef LEXER_EXCEPTION_H
#define LEXER_EXCEPTION_H

#include <stdexcept>

namespace Lexer {
enum LexError {
    InvalidToken,
    UnknownError,
};

struct LexerRuntimeError : std::runtime_error {
    LexError type = UnknownError;
    std::string token;
    // int line = -1;
    // int column = -1;

    LexerRuntimeError(
        const std::string message,
        const std::string token = "",
        const LexError type = UnknownError);
};
} // namespace Lexer

#endif // LEXER_EXCEPTION_H

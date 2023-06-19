#include "lexer_exception.h"
#include <stdexcept>

namespace Lexer {
LexerRuntimeError::LexerRuntimeError(
    const std::string message,
    const std::string token,
    const LexError type)
    : std::runtime_error(message)
{
    this->token = token;
    this->type = type;
}
} // namespace Lexer

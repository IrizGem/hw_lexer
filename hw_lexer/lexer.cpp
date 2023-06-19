#include "lexer.h"
#include <sstream>
#include <string>
#include <vector>

#include "lexem.h"
#include "lexer_exception.h"
using namespace Lexer;

namespace Lexer {
bool parseLexem(const std::string &word, LexWord &token) {
    if (word == "a") {
        token = ALetter;
        return true;
    }
    if (word == "b") {
        token = BLetter;
        return true;
    }
    if (word == "ab") {
        token = ABLetters;
        return true;
    }
    if (word == "ba") {
        token = BALetters;
        return true;
    }
    if (word == "_") {
        token = Space;
        return true;
    }
    return false;
}

std::vector<Lexem> lexIt(std::string line) {
    if (line == "")
        return {};

    std::vector<Lexem> list;
    int i = 0;
    int l = 1;
    int c = 1;
    int lb = 1;
    int cb = 1;
    std::string cur_lexem = "";

    while (i < line.size()) {
        if (line[i] == '\n') {
            ++l;
            c = 1;
        }
        if (line[i] != '_') {
            if (cur_lexem == "_") {
                list.push_back(Lexem(Space, lb, cb));
                cur_lexem = "";
                lb = l;
                cb = c;
            }
            cur_lexem += line[i];
        } else {
            LexWord token;
            if (cur_lexem == "")
                cur_lexem = "_";

            if (parseLexem(cur_lexem, token)) {
                if (token != Space) {
                    list.push_back(Lexem(token, lb, cb));
                    cur_lexem = "_";
                    lb = l;
                    cb = c;
                }
            } else {
                std::stringstream ss;
                ss << "can't parse this: '" << cur_lexem << "' in line " << lb << ", colunm " << cb << "\n";
                std::string s = ss.str();
                throw LexerRuntimeError(s, cur_lexem, InvalidToken);
                return {};
            }
        }
        ++i;
        ++c;
    }

    LexWord token;
    if (parseLexem(cur_lexem, token))
        list.push_back(Lexem(token, lb, cb));
    else {
        std::stringstream ss;
        ss << "can't parse this: '" << cur_lexem << "' in line " << lb << ", colunm " << cb << "\n";
        std::string s = ss.str();
        throw LexerRuntimeError(s, cur_lexem, InvalidToken);
        return {};
    }

    return list;
}
}

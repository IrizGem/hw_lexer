#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "lexer.h"
#include "lexer_exception.h"
using namespace Lexer;

std::array<std::string, 5> lexwords {
    "a", "b", "ab", "ba", "_",
};

auto test(const std::string &input, const std::string &output)
{
    std::vector<Lexem> lexems;
    try {
        lexems = lexIt(input);
    }
    catch (const LexerRuntimeError &err) {
        std::cout << err.what();
    }
    std::string res;
    for (const auto &l : lexems) {
        res += res.size() ? "," : "";
        res += lexwords[l.type];
    }
    std::cout << "input:   '" << input << "'\n";
    std::cout << "output:  '" << res << "'\n";
    std::cout << "expected: '" << output << "'\n";
    return (res == output) ? "OK\n\n" : "FAILED\n\n";
}

int main (int argc, char **argw)
{
    // positive
    std::cout << (test("a__ba_ab_b___b", "a,_,ba,_,ab,_,b,_,b"));
    std::cout << (test("", ""));
    std::cout << (test("_____________", "_"));
    std::cout << (test("ab_ba_a_a", "ab,_,ba,_,a,_,a"));
    std::cout << (test("_a_a_a_", "_,a,_,a,_,a,_"));
    std::cout << (test("_____a_a_a_", "_,a,_,a,_,a,_"));
    std::cout << (test("_a_a_a______", "_,a,_,a,_,a,_"));

    // negative
    std::cout << (test("abc", ""));
    std::cout << (test("1", ""));
    std::cout << (test("aa", ""));
    std::cout << (test("a_ba______ba___bb", ""));
    std::cout << (test("a_ba____bb___ba_a", ""));
    std::cout << (test("a b", ""));
    std::cout << (test("a_ba\naa", ""));

    // TODO:
    // 1. fix test cases - checked
    // 2. add throu exception -

    return 0;
}

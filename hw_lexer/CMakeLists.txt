cmake_minimum_required(VERSION 3.14)

project(hw_lexer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw_lexer
  main.cpp
  lexer.h lexer.cpp
  lexem.h lexem.cpp
  lexer_exception.h lexer_exception.cpp
)

install(TARGETS hw_lexer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

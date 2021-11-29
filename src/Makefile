# -std=c++17
# -DNDEBUG: turns off e.g. assertion checks
# -O3: enables optimizations in the compiler

# Settings for optimized build
FLAGS=-O3 -DNDEBUG -std=c++17

# Settings for a debug build
#FLAGS=-g -std=c++17

all: interpreter_test

clean:
	rm -f lexer_test

flex: lexer/go.lex
	flex -o ./lexer/lexer.cpp --header-file=./lexer/lexer.hpp ./lexer/go.lex

bison: parser/grammar.y
	bison -o ./parser/parser.cpp ./parser/grammar.y -dv

bison_counter: parser/grammar.y
	bison -o ./parser/parser.cpp ./parser/grammar.y -dv -Wcounterexamples

interpreter_test: main.cpp ast/*/*.cpp environment/*/*.cpp
	$(CXX) $(FLAGS) -o interpreter_test main.cpp lexer/lexer.cpp parser/parser.cpp ast/*/*.cpp environment/*/*.cpp

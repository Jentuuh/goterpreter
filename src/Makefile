# -std=c++17
# -DNDEBUG: turns off e.g. assertion checks
# -O3: enables optimizations in the compiler

# Settings for optimized build
FLAGS=-O3 -DNDEBUG -std=c++17

# Settings for a debug build
#FLAGS=-g -std=c++17

all: lexer_test

clean:
	rm -f lexer_test

lexer_test: main.cpp 
	$(CXX) $(FLAGS) -o lexer_test main.cpp lexer/lex.yy.c parser/grammar.tab.c

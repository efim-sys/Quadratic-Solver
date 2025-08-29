CC = g++
CFLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=16384 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

source_files = quad.c unit-test/unit-test.c tools/tools.c solver/solver.c parser/parser.c
# compile:
# 	g++ $(CFLAGS) unit-test/unit-test.c parser/parser.c solver/solver.c tools/tools.c quad.c -o build/a.out

all: link run	

link: unit-test.o parser.o solver.o tools.o quad.o complex.o
	$(CC) $(CFLAGS) build/quad.o build/unit-test.o build/parser.o build/solver.o build/tools.o build/complex.o -o build/a.out

quad.o: 
	$(CC) $(CFLAGS) quad.c -c -o build/quad.o

unit-test.o: 
	$(CC) $(CFLAGS) unit-test/unit-test.c -c -o build/unit-test.o

solver.o: 
	$(CC) $(CFLAGS) solver/solver.c -c -o build/solver.o

parser.o: 
	$(CC) $(CFLAGS) parser/parser.c -c -o build/parser.o

tools.o: 
	$(CC) $(CFLAGS) tools/tools.c -c -o build/tools.o

complex.o: 
	$(CC) $(CFLAGS) complex/complex.c -c -o build/complex.o

run:
	echo "\033[102m-------------------------LAUNCHING-------------------------\033[49m"
	build/a.out --test

CC    ?= clang
CXX   ?= clang++

EXE = my_wc

CDEBUG = -g -Wall

CXXDEBUG = -g -Wall

CSTD = -std=c99
CXXSTD = -std=c++11

CFLAGS = -Wno-deprecated-register -O0  $(CDEBUG) $(CSTD) 
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)


CPPOBJ = main driver
SOBJ =  parser lexer

FILES = $(addsuffix .cpp, $(CPPOBJ))
OBJS  = $(addsuffix .o, $(CPPOBJ))

CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) \
				 mparser.tab.cc parser.tab.hh \
				 location.hh position.hh \
			    stack.hh parser.output parser.o \
				 lexer.o lexer.yy.cc $(EXE)\

.PHONY: all
all: wc

wc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)

parser: parser.yy
	bison -d -v parser.yy
	$(CXX) $(CXXFLAGS) -c -o parser.o parser.tab.cc

lexer: lexer.l
	flex --outfile=lexer.yy.cc  $<
	$(CXX)  $(CXXFLAGS) -c lexer.yy.cc -o lexer.o


.PHONY: clean
clean:
	rm -rf $(CLEANLIST)


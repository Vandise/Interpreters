CC    ?= clang
CXX   ?= clang++

EXE = wc

CDEBUG = -g -Wall

CXXDEBUG = -g -Wall

CSTD = -std=c99
CXXSTD = -std=c++11

CFLAGS = -Wno-deprecated-register -O0  $(CDEBUG) $(CSTD) 
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)

OBJDIR = obj/
OUTDIR = bin/

MAIN_DRIVER = main driver
PARSER_LEXER =  parser lexer
MAIN_DRIVER_OUT = $(addsuffix .o, $(addprefix $(OBJDIR),$(MAIN_DRIVER)))
OBJ_FILES = $(wildcard obj/*.o)


.PHONY: all

all: dependencies

compile:
	$(CXX) $(CXXFLAGS) -o $(OUTDIR)$(EXE) $(OBJ_FILES) $(LIBS)

dependencies:
	$(MAKE) $(PARSER_LEXER)
	$(MAKE) $(MAIN_DRIVER_OUT)

parser: parser.yy
	bison -d -v parser.yy
	$(CXX) $(CXXFLAGS) -c -o $(OBJDIR)parser.o parser.tab.cc

lexer: lexer.l
	flex --outfile=lexer.yy.cc  $<
	$(CXX)  $(CXXFLAGS) -c lexer.yy.cc -o $(OBJDIR)lexer.o


.PHONY: clean
clean:
	-rm -rf $(OBJDIR)
	-rm -rf $(OUTDIR)
	-mkdir $(OBJDIR)
	-mkdir $(OUTDIR)

$(OBJDIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
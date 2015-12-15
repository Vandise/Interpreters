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

OBJ_FILES = $(wildcard obj/*.o)
MAIN_DRIVER = main driver
PARSER_LEXER =  parser lexer
MAIN_DRIVER_OUT = $(addsuffix .o, $(addprefix $(OBJDIR),$(MAIN_DRIVER)))

NODE_FILES = $(wildcard nodes/*.cpp)
NODE_FILES_OUT = $(addprefix obj/,$(notdir $(NODE_FILES:.cpp=.o)))

RUNTIME_FILES = $(wildcard runtime/*.cpp)
RUNTIME_FILES_OUT = $(addprefix obj/,$(notdir $(RUNTIME_FILES:.cpp=.o)))

.PHONY: all

all: dependencies

compile:
	$(CXX) $(CXXFLAGS) -o $(OUTDIR)$(EXE) $(OBJ_FILES) $(LIBS)

dependencies:
	$(MAKE) $(PARSER_LEXER)
	$(MAKE) $(MAIN_DRIVER_OUT)
	$(MAKE) $(NODE_FILES_OUT)
	$(MAKE) $(RUNTIME_FILES_OUT)

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

$(OBJDIR)%.o: nodes/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)%.o: runtime/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
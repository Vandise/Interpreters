// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 51 "parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 37 "parser.yy" // lalr1.cc:413

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   #include <map>

   /* include for all driver functions */
   #include "driver.hpp"

   #include "nodes/abstractnode.hpp"
   #include "nodes/nodes.hpp"
   #include "nodes/literalnode.hpp"
   #include "nodes/callnode.hpp"
   #include "nodes/selfnode.hpp"
   #include "runtime.hpp"

   #undef yylex
   #define yylex scanner.yylex
   

#line 74 "parser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 4 "parser.yy" // lalr1.cc:479
namespace FrontEnd {
#line 141 "parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg, Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 16: // IDENTIFIER

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 351 "parser.tab.cc" // lalr1.cc:617
        break;

      case 18: // SEMICOLON

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 358 "parser.tab.cc" // lalr1.cc:617
        break;

      case 19: // COLON

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 365 "parser.tab.cc" // lalr1.cc:617
        break;

      case 20: // DOT

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 372 "parser.tab.cc" // lalr1.cc:617
        break;

      case 23: // AT

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 379 "parser.tab.cc" // lalr1.cc:617
        break;

      case 24: // EQ

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 386 "parser.tab.cc" // lalr1.cc:617
        break;

      case 25: // LE

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 393 "parser.tab.cc" // lalr1.cc:617
        break;

      case 26: // GE

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 400 "parser.tab.cc" // lalr1.cc:617
        break;

      case 27: // LT

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 407 "parser.tab.cc" // lalr1.cc:617
        break;

      case 28: // GT

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 414 "parser.tab.cc" // lalr1.cc:617
        break;

      case 29: // PLUS

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 421 "parser.tab.cc" // lalr1.cc:617
        break;

      case 30: // MINUS

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 428 "parser.tab.cc" // lalr1.cc:617
        break;

      case 31: // MUL

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 435 "parser.tab.cc" // lalr1.cc:617
        break;

      case 32: // DIV

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 442 "parser.tab.cc" // lalr1.cc:617
        break;

      case 33: // MOD

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 449 "parser.tab.cc" // lalr1.cc:617
        break;

      case 34: // AND

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 456 "parser.tab.cc" // lalr1.cc:617
        break;

      case 35: // OR

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 463 "parser.tab.cc" // lalr1.cc:617
        break;

      case 36: // NOT

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 470 "parser.tab.cc" // lalr1.cc:617
        break;

      case 37: // ASSIGN

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 477 "parser.tab.cc" // lalr1.cc:617
        break;

      case 38: // COMMENT

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 484 "parser.tab.cc" // lalr1.cc:617
        break;

      case 39: // NEWLINE

#line 100 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 491 "parser.tab.cc" // lalr1.cc:617
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 130 "parser.yy" // lalr1.cc:859
    { 
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back((yystack_[0].value.abs_node));
                                            driver.set_stack(nodes);
                                            (yylhs.value.driver) = &driver;
                                          }
#line 726 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 136 "parser.yy" // lalr1.cc:859
    {
                                            (yystack_[2].value.driver)->push_node((yystack_[0].value.abs_node));
                                            (yylhs.value.driver) = (yystack_[2].value.driver);
                                          }
#line 735 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 140 "parser.yy" // lalr1.cc:859
    { /* do nothing */ }
#line 741 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 141 "parser.yy" // lalr1.cc:859
    {
                                            (yylhs.value.driver) = (yystack_[1].value.driver);
                                          }
#line 749 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 156 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = (yystack_[1].value.abs_node); }
#line 755 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 160 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(new Runtime::ValueObject((yystack_[0].value.ival))); }
#line 761 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 161 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::trueObject); }
#line 767 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 162 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::falseObject); }
#line 773 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 163 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::nilObject); }
#line 779 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 164 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::SelfNode(); }
#line 785 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 168 "parser.yy" // lalr1.cc:859
    {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = (yystack_[0].value.abs_node);
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 796 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 175 "parser.yy" // lalr1.cc:859
    {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = (yystack_[0].value.abs_node);
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 807 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 181 "parser.yy" // lalr1.cc:859
    {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = (yystack_[0].value.abs_node);
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 818 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 187 "parser.yy" // lalr1.cc:859
    {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = (yystack_[0].value.abs_node);
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 829 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 193 "parser.yy" // lalr1.cc:859
    {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = (yystack_[0].value.abs_node);
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 840 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 199 "parser.yy" // lalr1.cc:859
    {
                                        std::map<int, Nodes::AbstractNode*> arguments;
                                        arguments[0] = (yystack_[0].value.abs_node);
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 851 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 208 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::nilObject); }
#line 857 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 212 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::nilObject); }
#line 863 "parser.tab.cc" // lalr1.cc:859
    break;


#line 867 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -37;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      -7,   -37,   -37,   -37,   -37,   -37,   -36,    -7,     0,    13,
     -37,   -37,   -37,   -37,    -7,     5,   -37,   -37,   -37,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    13,   -37,    13,    13,
      13,    13,    13,    13,    13
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,    17,    16,    14,    15,    13,    24,     0,     0,     2,
       8,     9,    10,    11,     0,     0,     1,     7,     6,     5,
       0,     0,     0,     0,     0,     0,    25,    12,     3,    22,
      23,    18,    19,    20,    21
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -37,   -37,   -37,     1,   -37,   -37,   -37,   -37
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     8,    19,     9,    10,    11,    12,    13
  };

  const unsigned char
  Parser::yytable_[] =
  {
      16,    14,     1,     2,     3,     4,     5,     0,    15,     6,
       0,     0,     0,     0,     7,    26,     0,     0,    17,     0,
      28,    29,    30,    31,    32,    33,    34,    27,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,     0,    18,
      20,    21,    22,    23,    24,    25
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,    37,     9,    10,    11,    12,    13,    -1,     7,    16,
      -1,    -1,    -1,    -1,    21,    14,    -1,    -1,    18,    -1,
      19,    20,    21,    22,    23,    24,    25,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    39,
      27,    28,    29,    30,    31,    32
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     9,    10,    11,    12,    13,    16,    21,    57,    59,
      60,    61,    62,    63,    37,    59,     0,    18,    39,    58,
      27,    28,    29,    30,    31,    32,    59,    22,    59,    59,
      59,    59,    59,    59,    59
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    56,    57,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    63
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "CLASS", "FUNC", "IF", "ELSE",
  "WHILE", "END", "SELF", "NIL", "TRUE", "FALSE", "INTEGER", "FLOAT",
  "STRING", "IDENTIFIER", "CONSTANT", "SEMICOLON", "COLON", "DOT",
  "OPEN_PAREN", "CLOSE_PAREN", "AT", "EQ", "LE", "GE", "LT", "GT", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "AND", "OR", "NOT", "ASSIGN", "COMMENT",
  "NEWLINE", "\".\"", "\"!\"", "\"*\"", "\"/\"", "\"+\"", "\"-\"", "\">\"",
  "\">=\"", "\"<\"", "\"<=\"", "\"==\"", "\"!=\"", "\"&&\"", "\"||\"",
  "\"=\"", "\",\"", "$accept", "Expressions", "Terminator", "Expression",
  "Literal", "Operator", "GetLocal", "SetLocal", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,   130,   130,   136,   140,   141,   147,   148,   152,   153,
     154,   155,   156,   160,   161,   162,   163,   164,   168,   175,
     181,   187,   193,   199,   208,   212
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
    };
    const unsigned int user_token_number_max_ = 310;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 4 "parser.yy" // lalr1.cc:1167
} // FrontEnd
#line 1218 "parser.tab.cc" // lalr1.cc:1167
#line 215 "parser.yy" // lalr1.cc:1168



void 
FrontEnd::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n"; 
}

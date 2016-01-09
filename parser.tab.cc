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
#line 40 "parser.yy" // lalr1.cc:413

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   #include <map>
   #include <vector>

   /* include for all driver functions */
   #include "driver.hpp"

   #include "nodes/abstractnode.hpp"
   #include "nodes/nodes.hpp"
   #include "nodes/literalnode.hpp"
   #include "nodes/callnode.hpp"
   #include "nodes/selfnode.hpp"
   #include "nodes/localassignnode.hpp"
   #include "nodes/methoddefinitionnode.hpp"
   #include "nodes/classdefinitionnode.hpp"
   #include "nodes/constantnode.hpp"
   #include "nodes/instancevariablenode.hpp"
   #include "nodes/instancevariableassign.hpp"
   #include "nodes/lambdanode.hpp"
   #include "runtime.hpp"

   #undef yylex
   #define yylex scanner.yylex
   

#line 82 "parser.tab.cc" // lalr1.cc:413


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
#line 149 "parser.tab.cc" // lalr1.cc:479

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
            case 16: // STRING

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 359 "parser.tab.cc" // lalr1.cc:617
        break;

      case 17: // IDENTIFIER

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 366 "parser.tab.cc" // lalr1.cc:617
        break;

      case 18: // CONSTANT

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 373 "parser.tab.cc" // lalr1.cc:617
        break;

      case 19: // SEMICOLON

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 380 "parser.tab.cc" // lalr1.cc:617
        break;

      case 27: // EQ

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 387 "parser.tab.cc" // lalr1.cc:617
        break;

      case 28: // LE

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 394 "parser.tab.cc" // lalr1.cc:617
        break;

      case 29: // GE

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 401 "parser.tab.cc" // lalr1.cc:617
        break;

      case 30: // LT

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 408 "parser.tab.cc" // lalr1.cc:617
        break;

      case 31: // GT

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 415 "parser.tab.cc" // lalr1.cc:617
        break;

      case 32: // PLUS

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 422 "parser.tab.cc" // lalr1.cc:617
        break;

      case 33: // MINUS

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 429 "parser.tab.cc" // lalr1.cc:617
        break;

      case 34: // MUL

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 436 "parser.tab.cc" // lalr1.cc:617
        break;

      case 35: // DIV

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 443 "parser.tab.cc" // lalr1.cc:617
        break;

      case 36: // MOD

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 450 "parser.tab.cc" // lalr1.cc:617
        break;

      case 37: // AND

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 457 "parser.tab.cc" // lalr1.cc:617
        break;

      case 38: // OR

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 464 "parser.tab.cc" // lalr1.cc:617
        break;

      case 39: // NOT

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 471 "parser.tab.cc" // lalr1.cc:617
        break;

      case 40: // ASSIGN

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 478 "parser.tab.cc" // lalr1.cc:617
        break;

      case 41: // COMMENT

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 485 "parser.tab.cc" // lalr1.cc:617
        break;

      case 42: // COMMA

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 492 "parser.tab.cc" // lalr1.cc:617
        break;

      case 43: // NEWLINE

#line 115 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 499 "parser.tab.cc" // lalr1.cc:617
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
#line 151 "parser.yy" // lalr1.cc:859
    { 
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back((yystack_[0].value.abs_node));
                                            driver.set_stack(nodes);
                                            (yylhs.value.driver) = &driver;
                                          }
#line 734 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 157 "parser.yy" // lalr1.cc:859
    {
                                            (yystack_[2].value.driver)->push_node((yystack_[0].value.abs_node));
                                            (yylhs.value.driver) = (yystack_[2].value.driver);
                                          }
#line 743 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 161 "parser.yy" // lalr1.cc:859
    { /* do nothing */ }
#line 749 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 162 "parser.yy" // lalr1.cc:859
    {
                                            (yylhs.value.driver) = (yystack_[1].value.driver);
                                          }
#line 757 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 168 "parser.yy" // lalr1.cc:859
    {
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back((yystack_[0].value.abs_node));
                                            Nodes::Nodes *nodelist = new Nodes::Nodes(nodes);
                                            (yylhs.value.nodes) = nodelist;
                                          }
#line 768 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 174 "parser.yy" // lalr1.cc:859
    {
                                            (yystack_[2].value.nodes)->add((yystack_[0].value.abs_node));
                                            (yylhs.value.nodes) = (yystack_[2].value.nodes);
                                          }
#line 777 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 178 "parser.yy" // lalr1.cc:859
    { /* do nothing */ }
#line 783 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 179 "parser.yy" // lalr1.cc:859
    {
                                            (yylhs.value.nodes) = (yystack_[1].value.nodes);
                                          }
#line 791 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 200 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = (yystack_[1].value.abs_node); }
#line 797 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 204 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(new Runtime::ValueObject((yystack_[0].value.ival))); }
#line 803 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 205 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(new Runtime::ValueObject(*(yystack_[0].value.sval))); }
#line 809 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 206 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::trueObject); }
#line 815 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 207 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::falseObject); }
#line 821 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 208 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::nilObject); }
#line 827 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 209 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::SelfNode(); }
#line 833 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 213 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[3].value.sval), NULL, *(yystack_[1].value.arguments)); }
#line 839 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 214 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[3].value.sval), (yystack_[5].value.abs_node), *(yystack_[1].value.arguments));   }
#line 845 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 215 "parser.yy" // lalr1.cc:859
    {
                                                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                                                  (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[0].value.sval), (yystack_[2].value.abs_node), *arguments);
                                                                }
#line 854 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 222 "parser.yy" // lalr1.cc:859
    {
                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                  arguments->push_back((yystack_[0].value.abs_node));
                                  (yylhs.value.arguments) = arguments;
                                }
#line 864 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 227 "parser.yy" // lalr1.cc:859
    {
                                  (yystack_[2].value.arguments)->push_back((yystack_[0].value.abs_node));
                                  (yylhs.value.arguments) = (yystack_[2].value.arguments);
                                }
#line 873 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 231 "parser.yy" // lalr1.cc:859
    {
                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                  (yylhs.value.arguments) = arguments;
                                }
#line 882 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 238 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 893 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 245 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 904 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 251 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 915 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 257 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 926 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 263 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 937 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 269 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 948 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 278 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LocalAssignNode(*(yystack_[2].value.sval), (yystack_[0].value.abs_node)); }
#line 954 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 279 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::InstanceVariableAssign(*(yystack_[2].value.sval), (yystack_[0].value.abs_node)); }
#line 960 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 283 "parser.yy" // lalr1.cc:859
    {
              // Evaluate "my_local" as a local variable 
              // since we cant have a function (with no arguments and called without parens) 
                          // and a variable named the same
                          std::vector<Nodes::AbstractNode*> arguments;
                          (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[0].value.sval), NULL, arguments);
                       }
#line 972 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 295 "parser.yy" // lalr1.cc:859
    {
                                    (yylhs.value.abs_node) = new Nodes::MethodDefinitionNode(*(yystack_[6].value.sval), *(yystack_[4].value.parameters), (yystack_[1].value.nodes));
                                  }
#line 980 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 301 "parser.yy" // lalr1.cc:859
    {
                                    std::vector<std::string> arguments = std::vector<std::string>();
                                    (yylhs.value.abs_node) = new Nodes::MethodDefinitionNode(*(yystack_[3].value.sval), arguments, (yystack_[1].value.nodes));
                                  }
#line 989 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 310 "parser.yy" // lalr1.cc:859
    {
                                    (yylhs.value.abs_node) = new Nodes::LambdaNode(*(yystack_[4].value.parameters),(yystack_[1].value.nodes));
                                  }
#line 997 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 316 "parser.yy" // lalr1.cc:859
    {
                                    std::vector<std::string> *parameters = new std::vector<std::string>();
                                    parameters->push_back(*(yystack_[0].value.sval));
                                    (yylhs.value.parameters) = parameters;
                                  }
#line 1007 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 321 "parser.yy" // lalr1.cc:859
    { (yystack_[2].value.parameters)->push_back(*(yystack_[0].value.sval)); (yylhs.value.parameters) = (yystack_[2].value.parameters); }
#line 1013 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 322 "parser.yy" // lalr1.cc:859
    { 
                                    std::vector<std::string> *parameters = new std::vector<std::string>();
                                    (yylhs.value.parameters) = parameters;
                                  }
#line 1022 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 331 "parser.yy" // lalr1.cc:859
    {
                                    (yylhs.value.abs_node) = new Nodes::ClassDefinitionNode(*(yystack_[5].value.sval), *(yystack_[3].value.sval), (yystack_[1].value.nodes));
                                  }
#line 1030 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 337 "parser.yy" // lalr1.cc:859
    {
                                    (yylhs.value.abs_node) = new Nodes::ClassDefinitionNode(*(yystack_[3].value.sval), std::string(""), (yystack_[1].value.nodes));
                                  }
#line 1038 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 343 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::ConstantNode(*(yystack_[0].value.sval)); }
#line 1044 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 347 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::InstanceVariableNode(*(yystack_[0].value.sval)); }
#line 1050 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1054 "parser.tab.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -41;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      67,   -14,   -12,   -41,   -41,   -41,   -41,   -41,   -41,    -5,
     -41,    67,     1,    35,     2,    73,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -11,    15,    67,    67,
      65,    -6,    19,   -41,   -41,   -41,    67,    43,    67,    67,
      67,    67,    67,    67,    44,    67,    47,    67,    73,   -20,
      73,   -41,    47,    67,    73,    39,    73,    73,    73,    73,
      73,    73,     5,     4,    73,   -41,   -17,     7,   -41,    67,
      32,    73,    67,    67,   -41,    67,     5,    48,   -41,    73,
       5,    34,     8,    73,    67,   -41,    67,   -41,   -41,    11,
      12,   -41,   -41
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     0,    28,    27,    25,    26,    23,    24,    43,
      52,     0,     0,     0,     0,     2,    12,    13,    14,    17,
      18,    19,    20,    21,    15,    16,     0,     0,    34,     0,
       0,     0,    53,     1,    11,    10,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     8,    49,     8,    32,     0,
      41,    22,    49,     0,     3,    31,    39,    40,    35,    36,
      37,    38,     0,     0,     6,    47,     0,     0,    29,     0,
       0,    42,    34,     8,    51,     9,     0,     0,    45,    33,
       0,     0,     0,     7,     8,    48,     8,    30,    50,     0,
       0,    44,    46
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -41,   -41,   -40,   -13,     0,   -41,   -41,    -4,   -41,   -41,
     -41,   -41,   -41,    14,   -41,   -41,   -41
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    14,    63,    75,    64,    16,    17,    49,    18,    19,
      20,    21,    22,    66,    23,    24,    25
  };

  const unsigned char
  Parser::yytable_[] =
  {
      15,    36,    33,    68,    26,    27,    76,    67,    34,    44,
      31,    30,    74,    45,    47,    78,    88,    28,    52,    91,
      92,    34,    69,    34,    34,    77,    34,    34,    48,    50,
      34,    34,    35,    82,    34,    29,    54,    46,    56,    57,
      58,    59,    60,    61,    89,    35,    90,    35,    35,    73,
      35,    35,    32,    71,    35,    35,    80,    87,    35,    53,
      55,    72,    62,    84,    65,    85,    70,    86,    81,    79,
       1,     2,    48,     0,    77,    83,    69,     3,     4,     5,
       6,     7,     0,     8,     9,    10,    37,     0,    51,    11,
       0,     0,    12,    13,    37,    38,    39,    40,    41,    42,
      43,     0,     0,    38,    39,    40,    41,    42,    43
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,    14,     0,    23,    18,    17,    23,    47,    19,    20,
       9,    11,     8,    26,    27,     8,     8,    22,    24,     8,
       8,    19,    42,    19,    19,    42,    19,    19,    28,    29,
      19,    19,    43,    73,    19,    40,    36,    22,    38,    39,
      40,    41,    42,    43,    84,    43,    86,    43,    43,    62,
      43,    43,    17,    53,    43,    43,    24,    23,    43,    40,
      17,    22,    18,    76,    17,    17,    52,    80,    72,    69,
       3,     4,    72,    -1,    42,    75,    42,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    21,    -1,    23,    22,
      -1,    -1,    25,    26,    21,    30,    31,    32,    33,    34,
      35,    -1,    -1,    30,    31,    32,    33,    34,    35
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,    10,    11,    12,    13,    14,    16,    17,
      18,    22,    25,    26,    61,    64,    65,    66,    68,    69,
      70,    71,    72,    74,    75,    76,    18,    17,    22,    40,
      64,     9,    17,     0,    19,    43,    63,    21,    30,    31,
      32,    33,    34,    35,    20,    63,    22,    63,    64,    67,
      64,    23,    24,    40,    64,    17,    64,    64,    64,    64,
      64,    64,    18,    62,    64,    17,    73,    62,    23,    42,
      73,    64,    22,    63,     8,    63,    23,    42,     8,    64,
      24,    67,    62,    64,    63,    17,    63,    23,     8,    62,
      62,     8,     8
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    60,    61,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    69,    69,    70,    71,    71,    72,    73,    73,    73,
      74,    74,    75,    76
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     0,     2,     1,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       6,     3,     1,     3,     0,     3,     3,     3,     3,     3,
       3,     3,     4,     1,     8,     5,     8,     1,     3,     0,
       7,     5,     1,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "CLASS", "FUNC", "IF", "ELSE",
  "WHILE", "END", "DO", "SELF", "NIL", "TRUE", "FALSE", "INTEGER", "FLOAT",
  "STRING", "IDENTIFIER", "CONSTANT", "SEMICOLON", "COLON", "DOT",
  "OPEN_PAREN", "CLOSE_PAREN", "PIPE", "LAMBDA", "AT", "EQ", "LE", "GE",
  "LT", "GT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "AND", "OR", "NOT",
  "ASSIGN", "COMMENT", "COMMA", "NEWLINE", "\".\"", "\"!\"", "\"*\"",
  "\"/\"", "\"+\"", "\"-\"", "\">\"", "\">=\"", "\"<\"", "\"<=\"",
  "\"==\"", "\"!=\"", "\"&&\"", "\"||\"", "\"=\"", "\",\"", "$accept",
  "Expressions", "BodyExpressions", "Terminator", "Expression", "Literal",
  "Call", "Arguments", "Operator", "SetLocal", "GetLocal", "Function",
  "Lambda", "Parameters", "Class", "GetConstant", "InstanceVariable", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   151,   151,   157,   161,   162,   168,   174,   178,   179,
     185,   186,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   204,   205,   206,   207,   208,   209,   213,
     214,   215,   222,   227,   231,   238,   245,   251,   257,   263,
     269,   278,   279,   283,   293,   299,   308,   316,   321,   322,
     329,   335,   343,   347
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
      55,    56,    57,    58,    59
    };
    const unsigned int user_token_number_max_ = 314;
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
#line 1448 "parser.tab.cc" // lalr1.cc:1167
#line 349 "parser.yy" // lalr1.cc:1168



void 
FrontEnd::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n"; 
}

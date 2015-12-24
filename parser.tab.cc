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
   #include "runtime.hpp"

   #undef yylex
   #define yylex scanner.yylex
   

#line 79 "parser.tab.cc" // lalr1.cc:413


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
#line 146 "parser.tab.cc" // lalr1.cc:479

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
            case 15: // STRING

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 356 "parser.tab.cc" // lalr1.cc:617
        break;

      case 16: // IDENTIFIER

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 363 "parser.tab.cc" // lalr1.cc:617
        break;

      case 17: // CONSTANT

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 370 "parser.tab.cc" // lalr1.cc:617
        break;

      case 18: // SEMICOLON

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 377 "parser.tab.cc" // lalr1.cc:617
        break;

      case 23: // AT

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 384 "parser.tab.cc" // lalr1.cc:617
        break;

      case 24: // EQ

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 391 "parser.tab.cc" // lalr1.cc:617
        break;

      case 25: // LE

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 398 "parser.tab.cc" // lalr1.cc:617
        break;

      case 26: // GE

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 405 "parser.tab.cc" // lalr1.cc:617
        break;

      case 27: // LT

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 412 "parser.tab.cc" // lalr1.cc:617
        break;

      case 28: // GT

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 419 "parser.tab.cc" // lalr1.cc:617
        break;

      case 29: // PLUS

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 426 "parser.tab.cc" // lalr1.cc:617
        break;

      case 30: // MINUS

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 433 "parser.tab.cc" // lalr1.cc:617
        break;

      case 31: // MUL

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 440 "parser.tab.cc" // lalr1.cc:617
        break;

      case 32: // DIV

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 447 "parser.tab.cc" // lalr1.cc:617
        break;

      case 33: // MOD

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 454 "parser.tab.cc" // lalr1.cc:617
        break;

      case 34: // AND

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 461 "parser.tab.cc" // lalr1.cc:617
        break;

      case 35: // OR

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 468 "parser.tab.cc" // lalr1.cc:617
        break;

      case 36: // NOT

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 475 "parser.tab.cc" // lalr1.cc:617
        break;

      case 37: // ASSIGN

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 482 "parser.tab.cc" // lalr1.cc:617
        break;

      case 38: // COMMENT

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 489 "parser.tab.cc" // lalr1.cc:617
        break;

      case 39: // COMMA

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 496 "parser.tab.cc" // lalr1.cc:617
        break;

      case 40: // NEWLINE

#line 109 "parser.yy" // lalr1.cc:617
        { if ((yysym.value.sval))  { delete ((yysym.value.sval)); ((yysym.value.sval)) = nullptr; } }
#line 503 "parser.tab.cc" // lalr1.cc:617
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
#line 145 "parser.yy" // lalr1.cc:859
    { 
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back((yystack_[0].value.abs_node));
                                            driver.set_stack(nodes);
                                            (yylhs.value.driver) = &driver;
                                          }
#line 738 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 151 "parser.yy" // lalr1.cc:859
    {
                                            (yystack_[2].value.driver)->push_node((yystack_[0].value.abs_node));
                                            (yylhs.value.driver) = (yystack_[2].value.driver);
                                          }
#line 747 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 155 "parser.yy" // lalr1.cc:859
    { /* do nothing */ }
#line 753 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 156 "parser.yy" // lalr1.cc:859
    {
                                            (yylhs.value.driver) = (yystack_[1].value.driver);
                                          }
#line 761 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 162 "parser.yy" // lalr1.cc:859
    {
                                            std::vector<Nodes::AbstractNode *> nodes;
                                            nodes.push_back((yystack_[0].value.abs_node));
                                            Nodes::Nodes *nodelist = new Nodes::Nodes(nodes);
                                            (yylhs.value.nodes) = nodelist;
                                          }
#line 772 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 168 "parser.yy" // lalr1.cc:859
    {
                                            (yystack_[2].value.nodes)->add((yystack_[0].value.abs_node));
                                            (yylhs.value.nodes) = (yystack_[2].value.nodes);
                                          }
#line 781 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 172 "parser.yy" // lalr1.cc:859
    { /* do nothing */ }
#line 787 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 173 "parser.yy" // lalr1.cc:859
    {
                                            (yylhs.value.nodes) = (yystack_[1].value.nodes);
                                          }
#line 795 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 192 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = (yystack_[1].value.abs_node); }
#line 801 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 196 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(new Runtime::ValueObject((yystack_[0].value.ival))); }
#line 807 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 197 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(new Runtime::ValueObject(*(yystack_[0].value.sval))); }
#line 813 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 198 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::trueObject); }
#line 819 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 199 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::falseObject); }
#line 825 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 200 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LiteralNode(Lang::Runtime::nilObject); }
#line 831 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 201 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::SelfNode(); }
#line 837 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 205 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[3].value.sval), NULL, *(yystack_[1].value.arguments)); }
#line 843 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 206 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[3].value.sval), (yystack_[5].value.abs_node), *(yystack_[1].value.arguments));   }
#line 849 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 207 "parser.yy" // lalr1.cc:859
    {
                                                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                                                  (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[0].value.sval), (yystack_[2].value.abs_node), *arguments);
                                                                }
#line 858 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 214 "parser.yy" // lalr1.cc:859
    {
                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                  arguments->push_back((yystack_[0].value.abs_node));
                                  (yylhs.value.arguments) = arguments;
                                }
#line 868 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 219 "parser.yy" // lalr1.cc:859
    {
                                  (yystack_[2].value.arguments)->push_back((yystack_[0].value.abs_node));
                                  (yylhs.value.arguments) = (yystack_[2].value.arguments);
                                }
#line 877 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 223 "parser.yy" // lalr1.cc:859
    {
                                  std::vector<Nodes::AbstractNode*> *arguments = new std::vector<Nodes::AbstractNode*>();
                                  (yylhs.value.arguments) = arguments;
                                }
#line 886 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 230 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 897 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 237 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 908 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 243 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 919 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 249 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 930 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 255 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 941 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 261 "parser.yy" // lalr1.cc:859
    {
                                        std::vector<Nodes::AbstractNode*> arguments;
                                        arguments.push_back((yystack_[0].value.abs_node));
                                        std::string method = *(yystack_[1].value.sval);
                                        (yylhs.value.abs_node) = new Nodes::CallNode(method, (yystack_[2].value.abs_node), arguments); 
                                      }
#line 952 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 270 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::LocalAssignNode(*(yystack_[2].value.sval), (yystack_[0].value.abs_node)); }
#line 958 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 274 "parser.yy" // lalr1.cc:859
    {
              // Evaluate "my_local" as a local variable 
              // since we cant have a function (with no arguments and called without parens) 
                          // and a variable named the same
                          std::vector<Nodes::AbstractNode*> arguments;
                          (yylhs.value.abs_node) = new Nodes::CallNode(*(yystack_[0].value.sval), NULL, arguments);
                       }
#line 970 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 286 "parser.yy" // lalr1.cc:859
    {
                                    (yylhs.value.abs_node) = new Nodes::MethodDefinitionNode(*(yystack_[6].value.sval), *(yystack_[4].value.parameters), (yystack_[1].value.nodes));
                                  }
#line 978 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 292 "parser.yy" // lalr1.cc:859
    {
                                    std::vector<std::string> arguments = std::vector<std::string>();
                                    (yylhs.value.abs_node) = new Nodes::MethodDefinitionNode(*(yystack_[3].value.sval), arguments, (yystack_[1].value.nodes));
                                  }
#line 987 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 299 "parser.yy" // lalr1.cc:859
    {
                                    std::vector<std::string> *parameters = new std::vector<std::string>();
                                    parameters->push_back(*(yystack_[0].value.sval));
                                    (yylhs.value.parameters) = parameters;
                                  }
#line 997 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 304 "parser.yy" // lalr1.cc:859
    { (yystack_[2].value.parameters)->push_back(*(yystack_[0].value.sval)); (yylhs.value.parameters) = (yystack_[2].value.parameters); }
#line 1003 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 305 "parser.yy" // lalr1.cc:859
    { 
                                    std::vector<std::string> *parameters = new std::vector<std::string>();
                                    (yylhs.value.parameters) = parameters;
                                  }
#line 1012 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 314 "parser.yy" // lalr1.cc:859
    {
                                    (yylhs.value.abs_node) = new Nodes::ClassDefinitionNode(*(yystack_[5].value.sval), *(yystack_[3].value.sval), (yystack_[1].value.nodes));
                                  }
#line 1020 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 320 "parser.yy" // lalr1.cc:859
    {
                                    (yylhs.value.abs_node) = new Nodes::ClassDefinitionNode(*(yystack_[3].value.sval), std::string(""), (yystack_[1].value.nodes));
                                  }
#line 1028 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 326 "parser.yy" // lalr1.cc:859
    { (yylhs.value.abs_node) = new Nodes::ConstantNode(*(yystack_[0].value.sval)); }
#line 1034 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1038 "parser.tab.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -40;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      60,    -3,   -13,   -40,   -40,   -40,   -40,   -40,   -40,    37,
     -40,    60,     1,    64,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -14,    27,    60,    60,    58,   -40,   -40,   -40,
      60,    -8,    60,    60,    60,    60,    60,    60,     5,    60,
      11,    60,    64,     7,    64,   -40,    64,    -6,    64,    64,
      64,    64,    64,    64,    -9,    -2,    64,   -40,    18,    -1,
     -40,    60,    60,    60,   -40,    60,    -9,    31,   -40,    64,
      29,     2,    64,    60,   -40,   -40,   -40,    10,   -40
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     0,    26,    25,    23,    24,    21,    22,    40,
      48,     0,     0,     2,    12,    13,    14,    16,    17,    18,
      19,    15,     0,     0,    32,     0,     0,     1,    11,    10,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     8,
      45,     8,    30,     0,    39,    20,     3,    29,    37,    38,
      33,    34,    35,    36,     0,     0,     6,    43,     0,     0,
      27,     0,    32,     8,    47,     9,     0,     0,    42,    31,
       0,     0,     7,     8,    44,    28,    46,     0,    41
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -40,   -40,   -20,   -10,     0,   -40,   -40,   -39,   -40,   -40,
     -40,   -40,   -40,   -40,   -40
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    12,    55,    65,    56,    14,    15,    43,    16,    17,
      18,    19,    58,    20,    21
  };

  const unsigned char
  Parser::yytable_[] =
  {
      13,    27,    30,    23,    28,    38,    64,    68,    47,    28,
      76,    26,    39,    41,    22,    62,    28,    28,    78,    28,
      28,    59,    54,    70,    42,    44,    29,    57,    28,    60,
      46,    29,    48,    49,    50,    51,    52,    53,    29,    29,
      66,    29,    29,    71,    63,    28,    61,    74,    40,     0,
      29,    75,     0,    77,     0,     0,    73,    67,    24,     0,
       0,    69,    42,     1,     2,    72,     0,    29,    61,     3,
       4,     5,     6,     7,    25,     8,     9,    10,    31,     0,
      45,    11,     0,     0,    31,    32,    33,    34,    35,    36,
      37,    32,    33,    34,    35,    36,    37
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,     0,    12,    16,    18,    19,     8,     8,    16,    18,
       8,    11,    22,    23,    17,    21,    18,    18,     8,    18,
      18,    41,    17,    62,    24,    25,    40,    16,    18,    22,
      30,    40,    32,    33,    34,    35,    36,    37,    40,    40,
      22,    40,    40,    63,    54,    18,    39,    16,    21,    -1,
      40,    22,    -1,    73,    -1,    -1,    66,    39,    21,    -1,
      -1,    61,    62,     3,     4,    65,    -1,    40,    39,     9,
      10,    11,    12,    13,    37,    15,    16,    17,    20,    -1,
      22,    21,    -1,    -1,    20,    27,    28,    29,    30,    31,
      32,    27,    28,    29,    30,    31,    32
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     9,    10,    11,    12,    13,    15,    16,
      17,    21,    58,    61,    62,    63,    65,    66,    67,    68,
      70,    71,    17,    16,    21,    37,    61,     0,    18,    40,
      60,    20,    27,    28,    29,    30,    31,    32,    19,    60,
      21,    60,    61,    64,    61,    22,    61,    16,    61,    61,
      61,    61,    61,    61,    17,    59,    61,    16,    69,    59,
      22,    39,    21,    60,     8,    60,    22,    39,     8,    61,
      64,    59,    61,    60,    16,    22,     8,    59,     8
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    57,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    66,
      67,    68,    68,    69,    69,    69,    70,    70,    71
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     0,     2,     1,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     4,     6,     3,
       1,     3,     0,     3,     3,     3,     3,     3,     3,     3,
       1,     8,     5,     1,     3,     0,     7,     5,     1
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
  "COMMA", "NEWLINE", "\".\"", "\"!\"", "\"*\"", "\"/\"", "\"+\"", "\"-\"",
  "\">\"", "\">=\"", "\"<\"", "\"<=\"", "\"==\"", "\"!=\"", "\"&&\"",
  "\"||\"", "\"=\"", "\",\"", "$accept", "Expressions", "BodyExpressions",
  "Terminator", "Expression", "Literal", "Call", "Arguments", "Operator",
  "SetLocal", "GetLocal", "Function", "Parameters", "Class", "GetConstant", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   145,   145,   151,   155,   156,   162,   168,   172,   173,
     179,   180,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   196,   197,   198,   199,   200,   201,   205,   206,   207,
     214,   219,   223,   230,   237,   243,   249,   255,   261,   270,
     274,   284,   290,   299,   304,   305,   312,   318,   326
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
      55,    56
    };
    const unsigned int user_token_number_max_ = 311;
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
#line 1420 "parser.tab.cc" // lalr1.cc:1167
#line 328 "parser.yy" // lalr1.cc:1168



void 
FrontEnd::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: " << err_message << "\n"; 
}

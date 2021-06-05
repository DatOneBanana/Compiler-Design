%{
#define YY_NO_UNPUT
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <vector>
void yyerror(const char* msg);
int yylex();
  
extern int lineNum;
extern int lineCol;
extern char* yytext;
extern char* progName;
  
std::string newTemp();
std::string newLabel();

char empty[1] = "";

std::map<std::string, int> variables;

std::map<std::string, int> functions;
std::vector<std::string> reservedWords = {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
    "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", 
    "NOT", "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
    "R_SQUARE_BRACKET", "COLON", "SEMICOLON", "COMMA", "ASSIGN", "function", "Ident", "beginparams", "endparams", "beginlocals", "endlocals", "integer", 
    "beginbody", "endbody", "beginloop", "endloop", "if", "endif", "continue", "while", "else", "read", "do", "write"};
%}


%union{
  char* ident_val;
  int num_val;
    struct S {
    char* code;
  } stat;
  struct E {
    char* place;
    char* code;
    bool array;
  } expr;
 }

%error-verbose
%start Program

%token <ident_val> IDENT
%token <num_val> NUMBER

%type <expr> Ident FunctionIdent
%type <expr> Declarations Declaration Identifiers Var Vars
%type <stat> Statement_Loop Statement ElseStatement
%type <expr> Expression Expressions MultExp Term BoolExp Regxp RegLoopxp RegLoopxp1 Comp

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO IN BEGINLOOP
%token ENDLOOP CONTINUE READ WRITE TRUE FALSE RETURN L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET COLON SEMICOLON COMMA

%left ASSIGN EQ NEQ LT GT LTE GTE ADD SUB MULT DIV MOD AND OR
%right NOT

%%  

Program:         %empty
{
  std::string tempMain = "main";
  if ( functions.find(tempMain) == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Main not declared");
    yyerror(temp);
  }
}
| Function Program
{
};

Function:        FUNCTION FunctionIdent SEMICOLON BEGIN_PARAMS Declarations END_PARAMS BEGIN_LOCALS Declarations END_LOCALS BEGIN_BODY Statement_Loop END_BODY
{
  std::string temp = "func ";
  temp.append($2.place);
  temp.append("\n");
  temp.append($2.code);
  temp.append($5.code);
  
  std::string init_params = $5.code;
  int param_number = 0;
  while (init_params.find(".") != std::string::npos) {
    size_t pos = init_params.find(".");
    init_params.replace(pos, 1, "=");
    std::string param = ", $";
    param.append(std::to_string(param_number++));
    param.append("\n");
    init_params.replace(init_params.find("\n", pos), 1, param);
  }
  temp.append(init_params);
  temp.append($8.code);
  std::string statements($11.code);
  
  if (statements.find("continue") != std::string::npos) {
    printf("ERROR: Outside loop in function %s\n", $2.place);
  }
  temp.append(statements);
  temp.append("endfunc\n");
  
  printf("%s", temp.c_str());
};


Declaration:     Identifiers COLON INTEGER
{
  std::string vars($1.place);
  std::string temp;
  std::string variable;
  bool cont = true;

  
  size_t oldpos = 0;
  size_t pos = 0;
  bool isReserved = false;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == std::string::npos) {
      temp.append(". ");
      variable = vars.substr(oldpos,pos);
      temp.append(variable);
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(". ");
      variable = vars.substr(oldpos, len);
      temp.append(variable);
      temp.append("\n");
    }
    
    for (unsigned int i = 0; i < reservedWords.size(); ++i) {
      if (reservedWords.at(i) == variable) {
        isReserved = true;
      }
    } 
    
    if (variables.find(variable) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclared variable %s", variable.c_str());
      yyerror(temp);
    }
    else if (isReserved){
      char temp[128];
      snprintf(temp, 128, "Invalid declaration of %s", variable.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(std::pair<std::string,int>(variable,0));
    }
    
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);	      
}
| Identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
{
  if ($5 <= 0) {
    char temp[128];
    snprintf(temp, 128, "Array size needs to be bigger than 1");
    yyerror(temp);
  }
  
  std::string vars($1.place);
  std::string temp;
  std::string variable;
  bool cont = true;

  size_t oldpos = 0;
  size_t pos = 0;
  while (cont) {
    pos = vars.find("|", oldpos);
    if (pos == std::string::npos) {
      temp.append(".[] ");
      variable = vars.substr(oldpos, pos);
      temp.append(variable);
      temp.append(", ");
      temp.append(std::to_string($5));
      temp.append("\n");
      cont = false;
    }
    else {
      size_t len = pos - oldpos;
      temp.append(".[] ");
      variable = vars.substr(oldpos, len);
      temp.append(variable);
      temp.append(", ");
      temp.append(std::to_string($5));
      temp.append("\n");
    }
    
    if (variables.find(variable) != variables.end()) {
      char temp[128];
      snprintf(temp, 128, "Redeclared variable %s", variable.c_str());
      yyerror(temp);
    }
    else {
      variables.insert(std::pair<std::string,int>(variable,$5));
    }
      
    oldpos = pos + 1;
  }
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);	      
};

Declarations:    %empty
{
  $$.code = strdup(empty);
  $$.place = strdup(empty);
}
| Declaration SEMICOLON Declarations
{
  std::string temp;
  temp.append($1.code);
  temp.append($3.code);
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
};

Identifiers:     Ident
{
  $$.place = strdup($1.place);
  $$.code = strdup(empty);
}
| Ident COMMA Identifiers
{

  std::string temp;
  temp.append($1.place);
  temp.append("|");
  temp.append($3.place);
  
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
};

Statement_Loop:      Statement SEMICOLON Statement_Loop
{
  std::string temp;
  temp.append($1.code);
  temp.append($3.code);

  $$.code = strdup(temp.c_str());
}
| Statement SEMICOLON
{
  std::string temp;
  temp.append($1.code);

  $$.code = strdup(temp.c_str());
};

Statement:      Var ASSIGN Expression
{
  std::string temp;
  temp.append($1.code);
  temp.append($3.code);
  std::string intermediate = $3.place;
  if ($1.array && $3.array) {
    intermediate = newTemp();
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");

    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append($3.place);
    temp.append("\n");
    temp.append("[]= ");
  }
  else if ($1.array) {
    temp.append("[]= ");
  }
  else if ($3.array) {
    temp.append("=[] ");
  }
  else {
    temp.append("= ");
  }
  temp.append($1.place);
  temp.append(", ");
  temp.append(intermediate);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| IF BoolExp THEN Statement_Loop ElseStatement ENDIF
{
  std::string then_begin = newLabel();
  std::string after = newLabel();
  std::string temp;


  temp.append($2.code);
  
  temp.append("?:= ");
  temp.append(then_begin);
  temp.append(", ");
  temp.append($2.place);
  temp.append("\n");
  
  temp.append($5.code);
  
  temp.append(":= ");
  temp.append(after);
  temp.append("\n");
  
  temp.append(": ");
  temp.append(then_begin);
  temp.append("\n");
  
  temp.append($4.code);
  
  temp.append(": ");
  temp.append(after);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
}		 
| WHILE BoolExp BEGINLOOP Statement_Loop ENDLOOP
{
  std::string temp;
  std::string beginWhile = newLabel();
  std::string beginLoop = newLabel();
  std::string endLoop = newLabel();
  
  std::string statement = $4.code;
  std::string jump;
  jump.append(":= ");
  jump.append(beginWhile);
  while (statement.find("continue") != std::string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  temp.append(": ");
  temp.append(beginWhile);
  temp.append("\n");

  temp.append($2.code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append($2.place);
  temp.append("\n");

  temp.append(":= ");
  temp.append(endLoop);
  temp.append("\n");

  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");

  temp.append(statement);
  temp.append(":= ");
  temp.append(beginWhile);
  temp.append("\n");

  temp.append(": ");
  temp.append(endLoop);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| DO BEGINLOOP Statement_Loop ENDLOOP WHILE BoolExp
{
  std::string temp;
  std::string beginLoop = newLabel();
  std::string beginWhile = newLabel();
  
  std::string statement = $3.code;
  std::string jump;
  jump.append(":= ");
  jump.append(beginWhile);
  while (statement.find("continue") != std::string::npos) {
    statement.replace(statement.find("continue"), 8, jump);
  }
  
  temp.append(": ");
  temp.append(beginLoop);
  temp.append("\n");

  temp.append(statement);
  temp.append(": ");
  temp.append(beginWhile);
  temp.append("\n");

  temp.append($6.code);
  temp.append("?:= ");
  temp.append(beginLoop);
  temp.append(", ");
  temp.append($6.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
}
| READ Vars
{
  std::string temp = $2.code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == std::string::npos)
      break;
    temp.replace(pos, 1, "<");
  } while (true);

  $$.code = strdup(temp.c_str());
}
| WRITE Vars
{
  std::string temp = $2.code;
  size_t pos = 0;
  do {
    pos = temp.find("|", pos);
    if (pos == std::string::npos)
      break;
    temp.replace(pos, 1, ">");
  } while (true);

  $$.code = strdup(temp.c_str());
}
| CONTINUE
{
  std::string temp = "continue\n";
  $$.code = strdup(temp.c_str());
}
| RETURN Expression
{
  std::string temp;
  temp.append($2.code);
  temp.append("ret ");
  temp.append($2.place);
  temp.append("\n");
  $$.code = strdup(temp.c_str());
};


ElseStatement:   %empty
{
  $$.code = strdup(empty);
}
| ELSE Statement_Loop
{
  $$.code = strdup($2.code);
};

Var:             Ident L_SQUARE_BRACKET Expression R_SQUARE_BRACKET
{
  if (variables.find(std::string($1.place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared variable %s", $1.place);
    yyerror(temp);
  }
  
  else if (variables.find(std::string($1.place))->second == 0) {
    char temp[128];
    snprintf(temp, 128, "Indexing a non-array variable %s", $1.place);
    yyerror(temp);
  }

  std::string temp;
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);

  $$.code = strdup($3.code);
  $$.place = strdup(temp.c_str());
  $$.array = true;
}
| Ident
{
  if (variables.find(std::string($1.place)) == variables.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared variable %s", $1.place);
    yyerror(temp);
  }
  
  else if (variables.find(std::string($1.place))->second > 0) {
    char temp[128];
    snprintf(temp, 128, "Failed to provide index for array variable %s", $1.place);
    yyerror(temp);
  }

  $$.code = strdup(empty);
  $$.place = strdup($1.place);
  $$.array = false;
};

Vars:            Var
{
  std::string temp;
  temp.append($1.code);
  if ($1.array)
    temp.append(".[]| ");
  else
    temp.append(".| ");
  
  temp.append($1.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
}
| Var COMMA Vars
{
  std::string temp;
  temp.append($1.code);
  if ($1.array){
    temp.append(".[]| ");
  }
  else{
    temp.append(".| ");
  }
  
  temp.append($1.place);
  temp.append("\n");
  temp.append($3.code);
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
};

Expression:      MultExp
{
  $$.code = strdup($1.code);
  $$.place = strdup($1.place);
}
| MultExp ADD Expression
{
  $$.place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");

  temp.append("+ ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| MultExp SUB Expression
{
  $$.place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");

  temp.append("- ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
};

Expressions:     %empty
{
  $$.code = strdup(empty);
  $$.place = strdup(empty);
}
| Expression COMMA Expressions
{
  std::string temp;
  temp.append($1.code);
  temp.append("param ");
  temp.append($1.place);
  temp.append("\n");
  temp.append($3.code);

  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
}
| Expression
{
  std::string temp;
  temp.append($1.code);
  temp.append("param ");
  temp.append($1.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
  $$.place = strdup(empty);
};


MultExp:         Term
{
  $$.code = strdup($1.code);
  $$.place = strdup($1.place);
}
| Term MULT MultExp
{
  $$.place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");

  temp.append($1.code);
  temp.append($3.code);
  temp.append("* ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| Term DIV MultExp
{
  $$.place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");

  temp.append($1.code);
  temp.append($3.code);
  temp.append("/ ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
}
| Term MOD MultExp
{
  $$.place = strdup(newTemp().c_str());
  
  std::string temp;
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append($1.code);
  temp.append($3.code);
  temp.append("% ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");

  $$.code = strdup(temp.c_str());
};


Term:            Var
{
  
  if ($$.array == true) {
    std::string temp;
    std::string intermediate = newTemp();

    temp.append($1.code);
    temp.append(". ");
    temp.append(intermediate);
    temp.append("\n");

    temp.append("=[] ");
    temp.append(intermediate);
    temp.append(", ");
    temp.append($1.place);
    temp.append("\n");

    $$.code = strdup(temp.c_str());
    $$.place = strdup(intermediate.c_str());
    $$.array = false;
  }
  else {
    $$.code = strdup($1.code);
    $$.place = strdup($1.place);
  }
}
| SUB Var
{
  
  $$.place = strdup(newTemp().c_str());
  std::string temp;
  temp.append($2.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  if ($2.array) {
    temp.append("=[] ");
    temp.append($$.place);
    temp.append(", ");
    temp.append($2.place);
    temp.append("\n");
  }
  else {
    temp.append("= ");
    temp.append($$.place);
    temp.append(", ");
    temp.append($2.place);
    temp.append("\n");
  }
  temp.append("* ");
  temp.append($$.place);
  temp.append(", ");
  temp.append($$.place);
  temp.append(", -1\n");
  
  $$.code = strdup(temp.c_str());
  $$.array = false;
}
| NUMBER
{
  $$.code = strdup(empty);
  $$.place = strdup(std::to_string($1).c_str());
}
| SUB NUMBER
{
  std::string temp;
  temp.append("-");
  temp.append(std::to_string($2));
  $$.code = strdup(empty);
  $$.place = strdup(temp.c_str());
}
| L_PAREN Expression R_PAREN
{
  $$.code = strdup($2.code);
  $$.place = strdup($2.place);
}
| SUB L_PAREN Expression R_PAREN
{
  $$.place = strdup($3.place);
  std::string temp;
  temp.append($3.code);
  temp.append("* ");
  temp.append($3.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append(", -1\n");
  $$.code = strdup(temp.c_str());
}
| Ident L_PAREN Expressions R_PAREN
{
   
  if (functions.find(std::string($1.place)) == functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Use of undeclared function %s", $1.place);
    yyerror(temp);
  }

  $$.place = strdup(newTemp().c_str());

  std::string temp;
  temp.append($3.code);
  temp.append(". ");
  temp.append($$.place);
  temp.append("\n");
  temp.append("call ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($$.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
};

BoolExp:         Regxp 
{
  $$.place = strdup($1.place);
  $$.code = strdup($1.code);
}
| Regxp OR BoolExp
{
  std::string dest = newTemp();
  std::string temp;

  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("|| ");
  temp.append(dest);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
};

Regxp:           RegLoopxp
{
  $$.place = strdup($1.place);
  $$.code = strdup($1.code);
}
| RegLoopxp AND Regxp
{
  std::string dest = newTemp();
  std::string temp;

  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("&& ");
  temp.append(dest);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
};

RegLoopxp:            NOT RegLoopxp1
{
  std::string dest = newTemp();
  std::string temp;

  temp.append($2.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  
  temp.append("! ");
  temp.append(dest);
  temp.append(", ");
  temp.append($2.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
}
| RegLoopxp1
{
  $$.place = strdup($1.place);
  $$.code = strdup($1.code);
};

RegLoopxp1:           Expression Comp Expression
{
  std::string dest = newTemp();
  std::string temp;  

  temp.append($1.code);
  temp.append($3.code);
  temp.append(". ");
  temp.append(dest);
  temp.append("\n");
  temp.append($2.place);
  temp.append(dest);
  temp.append(", ");
  temp.append($1.place);
  temp.append(", ");
  temp.append($3.place);
  temp.append("\n");
  
  $$.code = strdup(temp.c_str());
  $$.place = strdup(dest.c_str());
}
| TRUE
{
  char temp[2] = "1";
  $$.place = strdup(temp);
  $$.code = strdup(empty);
}
| FALSE
{
  char temp[2] = "0";
  $$.place = strdup(temp);
  $$.code = strdup(empty);
}
| L_PAREN BoolExp R_PAREN
{
  $$.place = strdup($2.place);
  $$.code = strdup($2.code);
};

Comp:            EQ
{
  std::string temp = "== ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| NEQ
{
  std::string temp = "!= ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| LT
{
  std::string temp = "< ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| GT
{
  std::string temp = "> ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| LTE
{
  std::string temp = "<= ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
}
| GTE
{
  std::string temp = ">= ";
  $$.place = strdup(temp.c_str());
  $$.code = strdup(empty);
};

Ident:      IDENT
{
  $$.place = strdup($1);
  $$.code = strdup(empty);;
};
FunctionIdent: IDENT
{
  if (functions.find(std::string($1)) != functions.end()) {
    char temp[128];
    snprintf(temp, 128, "Redeclaration of function %s", $1);
    yyerror(temp);
  }
  else {
    functions.insert(std::pair<std::string,int>($1,0));
  }
  $$.place = strdup($1);
  $$.code = strdup(empty);;
}
%%

void yyerror(const char* msg) {
   printf("Error: Line %d, position %d: %s \n", lineNum, lineCol, msg);
}

std::string newTemp() {
  static int num = 0;
  std::string temp = "_t" + std::to_string(num++);
  return temp;
}

std::string newLabel() {
  static int num = 0;
  std::string temp = 'L' + std::to_string(num++);
  return temp;
}
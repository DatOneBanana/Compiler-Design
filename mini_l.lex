%{
  #include <string>
  #include "mini_l.tab.h"
  
  int lineNum = 1, lineCol = 0;
  char* progName;
%}

DIGIT [0-9]
DIGIT_UNDERSCORE [0-9_]
LETTER [a-zA-Z]
LETTER_UNDERSCORE [a-zA-Z_]
CHAR [0-9a-zA-Z_]
ALPHANUMER [0-9a-zA-Z]
WHITESPACE [\t ]
NEWLINE [\n]

%%

"function"     return FUNCTION; lineCol += yyleng;
"beginparams"  return BEGIN_PARAMS; lineCol += yyleng;
"endparams"    return END_PARAMS;  lineCol += yyleng;
"beginlocals"  return BEGIN_LOCALS; lineCol += yyleng;
"endlocals"    return END_LOCALS; lineCol += yyleng;
"beginbody"    return BEGIN_BODY; lineCol += yyleng;
"endbody"      return END_BODY; lineCol += yyleng;
"integer"      return INTEGER; lineCol += yyleng;
"array"        return ARRAY; lineCol += yyleng;
"of"           return OF; lineCol += yyleng;
"if"           return IF; lineCol += yyleng;
"then"         return THEN; lineCol += yyleng;
"endif"        return ENDIF; lineCol += yyleng;
"else"         return ELSE; lineCol += yyleng;
"while"        return WHILE; lineCol += yyleng;
"do"           return DO; lineCol += yyleng;
"in"           return IN; lineCol += yyleng;
"beginloop"    return BEGINLOOP; lineCol += yyleng;
"endloop"      return ENDLOOP; lineCol += yyleng;
"continue"     return CONTINUE; lineCol += yyleng;
"read"         return READ; lineCol += yyleng;
"write"        return WRITE; lineCol += yyleng;
"and"          return AND; lineCol += yyleng;
"or"           return OR; lineCol += yyleng;
"not"          return NOT; lineCol += yyleng;
"true"         return TRUE; lineCol += yyleng;
"false"        return FALSE; lineCol += yyleng;
"return"       return RETURN; lineCol += yyleng;

"-"       lineCol += yyleng; return SUB;
"+"       lineCol += yyleng; return ADD;
"*"       lineCol += yyleng; return MULT;
"/"       lineCol += yyleng; return DIV;
"%"       lineCol += yyleng; return MOD;

"=="      lineCol += yyleng; return EQ;
"<>"      lineCol += yyleng; return NEQ;
"<"       lineCol += yyleng; return LT;
">"       lineCol += yyleng; return GT;
"<="      lineCol += yyleng; return LTE;
">="      lineCol += yyleng; return GTE;

";"       lineCol += yyleng; return SEMICOLON;
":"       lineCol += yyleng; return COLON;
","       lineCol += yyleng; return COMMA;
"("       lineCol += yyleng; return L_PAREN;
")"       lineCol += yyleng; return R_PAREN;
"["       lineCol += yyleng; return L_SQUARE_BRACKET;
"]"       lineCol += yyleng; return R_SQUARE_BRACKET;
":="      lineCol += yyleng; return ASSIGN;

{LETTER}({CHAR}*{ALPHANUMER}+)? {
  yylval.ident_val = yytext;
  return IDENT;
  lineCol += yyleng;
	}

{DIGIT}+ {
  yylval.num_val = atoi(yytext);
  return NUMBER;
  lineCol += yyleng;
  }

({DIGIT}+{LETTER_UNDERSCORE}{CHAR}*)|("_"{CHAR}+) {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", lineNum, lineCol, yytext); exit(0);}

{LETTER}({CHAR}*{ALPHANUMER}+)?"_" {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", lineNum, lineCol, yytext); exit(0);}


"##".*{NEWLINE} lineCol = 0; ++lineNum;

{WHITESPACE}+   lineCol += yyleng;
{NEWLINE}+      lineNum += yyleng; lineCol = 0;

. {printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", lineNum, lineCol, yytext); exit(0);}

%%
int yyparse();
int yylex();

int main(int argc, char* argv[]) {
  if (argc == 2) {
    yyin = fopen(argv[1], "r");
    if (yyin == 0) {
      printf("Error opening file: %s\n", argv[1]);
      exit(1);
    }
  }
  else {
    yyin = stdin;
  }
  progName = strdup(argv[1]);
  
  //yylex();
  yyparse();
  
  return 0;
}
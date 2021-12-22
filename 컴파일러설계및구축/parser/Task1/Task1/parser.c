#include "miniC.tbl"
#define PS_SIZE 200
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NO_KEYWORDS 7
#define ID_LENGTH 12
#define EOF -1
FILE* source_file;

enum tsymbol {
    tnull = -1,
    tnot, tnotequ, tmod, tmodAssign, tident, tnumber,
    // 0      1        2      3        4         5   
    tand, tlparen, trparen, tmul, tmulAssign, tplus,
    // 6      7         8      9        10      11    
    tinc, taddAssign, tcomma, tminus, tdec, tsubAssign,
    // 12     13       14           15       16   17           
    tdiv, tdivAssign, tsemicolon, tless, tlesse, tassign,
    // 18      19       20        21       22       23     
    tequal, tgreat, tgreate, tlbracket, trbracket, teof,
    // 24     25       26        27        28      29   
    //        ......         word symnols ............. //            
    tconst, telse, tif, tint, treturn, tvoid,
    // 30     31    32    33     34     35                                                               
    twhile, tlbrace, tor, trbrace
    // 36     37      38      39 
};

struct tokenType {
    int number;                // token number
    union {
        char id[ID_LENGTH];
        int num;
    } value;                // token value
};

char* keyword[NO_KEYWORDS] = {
        "const", "else", "if", "int", "return", "void", "while"
};

enum tsymbol tnum[NO_KEYWORDS] = {
        tconst, telse, tif, tint, treturn, tvoid, twhile
};

void lexicalError(int n)
{
    printf(" *** Lexical Error : ");
    switch (n) {
    case 1: printf("an identifier length must be less than 12.\n");
        break;
    case 2: printf("next character must be &.\n");
        break;
    case 3: printf("next character must be |.\n");
        break;
    case 4: printf("invalid character!!!\n");
        break;
    }
}

int superLetter(char ch)
{
    if (isalpha(ch) || ch == '_') return 1;
    else return 0;
}

int superLetterOrDigit(char ch)
{
    if (isalnum(ch) || ch == '_') return 1;
    else return 0;
}

int hexValue(char ch)
{
    switch (ch) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        return (ch - '0');
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        return (ch - 'A' + 10);
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
        return (ch - 'a' + 10);

    default: return -1;
    }
}

int getIntNum(char firstCharacter, FILE* source_file)
{
    int num = 0;
    int value;
    char ch;

    if (firstCharacter != '0') {                        // decimal
        ch = firstCharacter;
        do {
            num = 10 * num + (int)(ch - '0');
            ch = getc(source_file);
        } while (isdigit(ch));
    }
    else {
        ch = getc(source_file);
        if ((ch >= '0') && (ch <= '7'))                // octal
            do {
                num = 8 * num + (int)(ch - '0');
                ch = getc(source_file);
            } while ((ch >= 'X') && (ch <= '7'));
        else if ((ch == 'X') || (ch == 'x')) {        // hexa decimal
            while ((value = hexValue(ch = getc(source_file))) != -1)
                num = 16 * num + value;
        }
        else num = 0;                                                // zero
    }
    ungetc(ch, source_file);        // retract
    return num;
}

struct tokenType scanner(FILE* source_file)
{
    struct tokenType token;
    int i = 0, index;
    char ch, id[ID_LENGTH];;

    token.number = tnull;

    do {
        while (isspace(ch = fgetc(source_file))); // state 1: ������ �پ�ѱ�
        if (superLetter(ch)) { // �ĺ��ڳ� Ű���尡 �ִٸ�
            i = 0;
            do {
                if (i < ID_LENGTH) id[i++] = ch;
                ch = fgetc(source_file);
            } while (superLetterOrDigit(ch));
            if (i >= ID_LENGTH) lexicalError(1);
            id[i] = '\0';
            ungetc(ch, source_file); // retract

            // find the identifier in the keyword table
            for (index = 0; index < NO_KEYWORDS; index++)
                if (!strcmp(id, keyword[index])) break;
            if (index < NO_KEYWORDS) {   //Ű���� ���̺� ������ Ű����
                token.number = tnum[index];
                strcpy(token.value.id, id);
            }
            else {   //Ű���� ���̺� ������ ��Ī                                    
                token.number = tident;
                strcpy(token.value.id, id);
            }
        } // end of identifier or keyword
        else if (isdigit(ch)) {                        // integer constant
            token.number = tnumber;
            token.value.num = getIntNum(ch, source_file);
        }
        else
            switch (ch) {                                // special character

            case '/':                                        // state 10
                ch = fgetc(source_file);
                if (ch == '*')                        // text comment
                    do {
                        while (ch != '*') ch = fgetc(source_file);
                        ch = fgetc(source_file);
                    } while (ch != '/');
                else if (ch == '/')                // line comment
                    while (fgetc(source_file) != '\n');
                else if (ch == '=') { token.number = tdivAssign; strcpy(token.value.id, "/="); }
                else {
                    token.number = tdiv;
                    strcpy(token.value.id, "/");
                    ungetc(ch, source_file); // retract
                }
                break;

            case '!':                                        // state 17
                ch = fgetc(source_file);
                if (ch == '=') { token.number = tnotequ; strcpy(token.value.id, "!="); }
                else {
                    token.number = tnot;
                    strcpy(token.value.id, "!");
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '%':                                        // state 20
                ch = fgetc(source_file);
                if (ch == '=') {
                    token.number = tmodAssign;
                    strcpy(token.value.id, "%=");
                }
                else {
                    token.number = tmod;
                    strcpy(token.value.id, "%");
                    ungetc(ch, source_file);
                }
                break;

            case '&':                                        // state 23
                ch = fgetc(source_file);
                if (ch == '&') { token.number = tand; strcpy(token.value.id, "&&"); }
                else {
                    lexicalError(2);
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '*':                                        // state 25
                ch = fgetc(source_file);
                if (ch == '=') { token.number = tmulAssign; strcpy(token.value.id, "*="); }
                else {
                    strcpy(token.value.id, "*");
                    token.number = tmul;
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '+':                                        // state 28
                ch = fgetc(source_file);
                if (ch == '+') { token.number = tinc; strcpy(token.value.id, "++"); }
                else if (ch == '=') {
                    token.number = taddAssign; strcpy(token.value.id, "+=");
                }
                else {
                    strcpy(token.value.id, "+");
                    token.number = tplus;
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '-':                                        // stats 32
                ch = fgetc(source_file);
                if (ch == '-') {
                    token.number = tdec; strcpy(token.value.id, "--");
                }
                else if (ch == '=') { token.number = tsubAssign; strcpy(token.value.id, "-="); }
                else {
                    token.number = tminus;
                    strcpy(token.value.id, "-");
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '<':                                        // state 36
                ch = fgetc(source_file);
                if (ch == '=') { token.number = tlesse; strcpy(token.value.id, "<="); }
                else {
                    strcpy(token.value.id, "<");
                    token.number = tless;
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '=':                                        // state 39
                ch = fgetc(source_file);
                if (ch == '=') { token.number = tequal; strcpy(token.value.id, "=="); }
                else {
                    token.number = tassign;
                    strcpy(token.value.id, "=");
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '>':                                        // state 42
                ch = fgetc(source_file);
                if (ch == '=') { token.number = tgreate; strcpy(token.value.id, ">="); }
                else {
                    token.number = tgreat;
                    strcpy(token.value.id, ">");
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '|':                                        // state 45
                ch = fgetc(source_file);
                if (ch == '|') { token.number = tor; strcpy(token.value.id, "||"); }
                else {
                    lexicalError(3);
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '(': token.number = tlparen;  strcpy(token.value.id, "(");    break;
            case ')': token.number = trparen;   strcpy(token.value.id, ")");   break;
            case ',': token.number = tcomma;    strcpy(token.value.id, ",");   break;
            case ';': token.number = tsemicolon; strcpy(token.value.id, ";");  break;
            case '[': token.number = tlbracket;  strcpy(token.value.id, "[");  break;
            case ']': token.number = trbracket;  strcpy(token.value.id, "]");  break;
            case '{': token.number = tlbrace;  strcpy(token.value.id, "{");    break;
            case '}': token.number = trbrace;  strcpy(token.value.id, "}");    break;
            case EOF: token.number = teof;  strcpy(token.value.id, "EOF");       break;

            default: {
                printf("Current character : %c", ch);
                lexicalError(4);
                break;
            }

            } // switch end
    } while (token.number == tnull);
    return token;
}

void parser();
void semantic(int);
void printToken(struct tokenType token);
void dumpStack();
void errorRecovery();

int errcnt = 0;
int sp;
int stateStack[PS_SIZE];
int symbolStack[PS_SIZE];

char* tokenName[] = {
    "!", "!=", "%","%=","%ident","%number",
    "&&","(",")","*","*=","+",
    "++","+=",",","-","--","-=",
    "/","/=",";","<","<=","=",
    "==",">",">=","[","]","eof",

    "const","else","if","int","return","void",
    "while","{","||","}"
};

void main() {
    source_file = fopen("perfect.mc", "rt");

	printf("start of parser \n");
	parser();
	printf("end of parser \n");
}

void parser()
{
	extern int parsingTable[NO_STATES][NO_SYMBOLS + 1];
	extern int leftsymbol[NO_RULES + 1], rightLength[NO_RULES + 1];
	int entry, ruleNumber, lhs;
	int currentState;
	struct tokenType token;

    sp = 0; stateStack[sp] = 0;
    token = scanner(source_file);
    while (1) {
        currentState = stateStack[sp];
        entry = parsingTable[currentState][token.number];
        if (entry > 0) {
            sp++;
            if (sp > PS_SIZE) {
                printf("critical compiler error: parsing stack overflow");
                exit(1);
            }
            symbolStack[sp] = token.number;
            stateStack[sp] = entry;
            token = scanner(source_file);
        }
        else if (entry < 0) {
            ruleNumber = -entry;
            if (ruleNumber == GOAL_RULE) {
                if (errcnt == 0) printf(" *** valid source ***\n");
                else printf(" *** error in source : %d\n", errcnt);
                return;
            }
            semantic(ruleNumber);
            sp = sp - rightLength[ruleNumber];
            lhs = leftSymbol[ruleNumber];
            currentState = parsingTable[stateStack[sp]][lhs];
            sp++;
            symbolStack[sp] = lhs;
            stateStack[sp] = currentState;
        }
        else {
            printf(" === error in source ===\n");
            errcnt++;
            printf("Current Token : ");
            printToken(token);
            dumpStack();
            errorRecovery();
            token = scanner(source_file);
        }
    }

}

void semantic(int n) {
	printf("reduced rule number = %d\n", n);
	/*
	cnt++;
	if(cnt==3){
		printf("\n");
		cnt=0;
	}
	else printf("\t");
	*/
}

void printToken(struct tokenType token) {
    if (token.number == tident) printf("%s", token.value.id);
    else if (token.number == tnumber) printf("%d", token.value.num);
    else printf("%s", tokenName[token.number]);
}

void dumpStack() {
    int i, start;

    if (sp > 10) start = sp - 10;
    else start = 0;

    printf("\n ***dump state stack :");
    for (i = start; i <= sp; ++i) printf(" %d", stateStack[i]);

    printf("\n ***dump symbol stack : ");
    for (i = start; i <= sp; i++) printf(" %d", symbolStack[i]);
    printf("\n");
}

void errorRecovery() {
    struct tokenType tok;
    int parenthesisCount, braceCount;
    int i;

    parenthesisCount = braceCount = 0;
    while (1) {
        tok = scanner(source_file);
        if (tok.number = teof) exit(1);
        if (tok.number == tlparen) parenthesisCount++;
        else if (tok.number == trparen) parenthesisCount--;
        if (tok.number == tlbrace) braceCount++;
        else if (tok.number == trbrace) braceCount--;
        if ((tok.number == tsemicolon) && (parenthesisCount <= 0) && (braceCount <= 0)) break;

        for (i = sp; i >= 0; i--) {
            if (stateStack[i] == 36) break;

            if (stateStack[i] == 24) break;

            if (stateStack[i] == 25) break;

            if (stateStack[i] == 17) break;

            if (stateStack[i] == 2) break;

            if (stateStack[i] == 0) break;
        }
        sp = i;
    }
}
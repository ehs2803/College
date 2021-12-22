#include "scanner.h"

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

    token.tokenNumber = tnull;

    do {
        while (isspace(ch = fgetc(source_file))); // state 1: 공백은 뛰어넘기
        if (superLetter(ch)) { // 식별자나 키워드가 있다면
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
            if (index < NO_KEYWORDS) {   //키워드 테이블에 있으면 키워드
                token.tokenNumber = tnum[index];
                token.tokenValue = id;
            }
            else {   //키워드 테이블에 없으면 명칭                                    
                token.tokenNumber = tident;
                //token.tokenValue=id;
                token.tokenValue = (char*)malloc(sizeof(5));//////////////////////////////
                strcpy(token.tokenValue, id);//////////////////////////
            }
        } // end of identifier or keyword
        else if (isdigit(ch)) {                        // integer constant
            token.tokenNumber = tnumber;
            token.tokenValue = getIntNum(ch, source_file);
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
                else if (ch == '=') { token.tokenNumber = tdivAssign; token.tokenValue="/="; }
                else {
                    token.tokenNumber = tdiv;
                    token.tokenValue="/";
                    ungetc(ch, source_file); // retract
                }
                break;

            case '!':                                        // state 17
                ch = fgetc(source_file);
                if (ch == '=') { token.tokenNumber = tnotequ; token.tokenValue="!="; }
                else {
                    token.tokenNumber = tnot;
                    token.tokenValue="!";
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '%':                                        // state 20
                ch = fgetc(source_file);
                if (ch == '=') {
                    token.tokenNumber = tmodAssign;
                   token.tokenValue="%=";
                }
                else {
                    token.tokenNumber = tmod;
                    token.tokenValue="%";
                    ungetc(ch, source_file);
                }
                break;

            case '&':                                        // state 23
                ch = fgetc(source_file);
                if (ch == '&') { token.tokenNumber = tand; token.tokenValue="&&"; }
                else {
                    lexicalError(2);
                    ungetc(ch, source_file);        // retract/////////////////////////////////////////
                }
                break;

            case '*':                                        // state 25
                ch = fgetc(source_file);
                if (ch == '=') { token.tokenNumber = tmulAssign; token.tokenValue="*="; }
                else {
                    token.tokenValue="*";
                    token.tokenNumber = tmul;
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '+':                                        // state 28
                ch = fgetc(source_file);
                if (ch == '+') { token.tokenNumber = tinc; token.tokenValue="++"; }
                else if (ch == '=') {
                    token.tokenNumber = taddAssign; token.tokenValue="+=";
                }
                else {
                    token.tokenValue="+";
                    token.tokenNumber = tplus;
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '-':                                        // stats 32
                ch = fgetc(source_file);
                if (ch == '-') {
                    token.tokenNumber = tdec; token.tokenValue="--";
                }
                else if (ch == '=') { token.tokenNumber = tsubAssign; token.tokenValue="-="; }
                else {
                    token.tokenNumber = tminus;
                    token.tokenValue= "-";
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '<':                                        // state 36
                ch = fgetc(source_file);
                if (ch == '=') { token.tokenNumber = tlesse; token.tokenValue="<="; }
                else {
                    token.tokenValue= "<";
                    token.tokenNumber = tless;
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '=':                                        // state 39
                ch = fgetc(source_file);
                if (ch == '=') { token.tokenNumber = tequal; token.tokenValue= "=="; }
                else {
                    token.tokenNumber = tassign;
                    token.tokenValue="=";
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '>':                                        // state 42
                ch = fgetc(source_file);
                if (ch == '=') { token.tokenNumber = tgreate; token.tokenValue= ">="; }
                else {
                    token.tokenNumber = tgreat;
                    token.tokenValue= ">";
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '|':                                        // state 45
                ch = fgetc(source_file);
                if (ch == '|') { token.tokenNumber = tor; token.tokenValue= "||"; }
                else {
                    lexicalError(3);
                    ungetc(ch, source_file);        // retract
                }
                break;

            case '(': token.tokenNumber = tlparen;  token.tokenValue= "(";    break;
            case ')': token.tokenNumber = trparen;  token.tokenValue= ")";   break;
            case ',': token.tokenNumber = tcomma;    token.tokenValue= ",";   break;
            case ';': token.tokenNumber = tsemicolon; token.tokenValue= ";";  break;
            case '[': token.tokenNumber = tlbracket;  token.tokenValue= "[";  break;
            case ']': token.tokenNumber = trbracket;  token.tokenValue= "]";  break;
            case '{': token.tokenNumber = tlbrace;  token.tokenValue= "{";    break;
            case '}': token.tokenNumber = trbrace;  token.tokenValue= "}";    break;
            case EOF: token.tokenNumber = teof;  token.tokenValue="EOF";       break;

            default: {
                printf("Current character : %c", ch);
                lexicalError(4);
                break;
            }

            } // switch end
    } while (token.tokenNumber == tnull);
    return token;
}


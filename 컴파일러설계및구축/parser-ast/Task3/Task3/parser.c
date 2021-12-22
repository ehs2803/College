#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "miniC.tbl"
#include "scanner.h"
#define PS_SIZE 200

FILE* source_file;
FILE* astFile;

typedef struct nodeType {
    struct tokenType token;
    enum { terminal, nonterm } noderep;
    struct nodeType* son;
    struct nodeType* brother;
}Node;

int errcnt = 0;
int sp;
int stateStack[PS_SIZE];
Node* valueStack[PS_SIZE];
int symbolStack[PS_SIZE];

enum nodeNumber {
    ACTUAL_PARAM, ADD, ADD_ASSIGN, ARRAY_VAR, ASSIGN_OP,
    CALL, COMPOUND_ST, CONST_NODE, DCL, DCL_ITEM,
    DCL_LIST, DCL_SPEC, DIV, DIV_ASSIGN, EQ,
    ERROR_NODE, EXP_ST, FORMAL_PARA, FUNC_DEF, FUNC_HEAD,
    GE, GT, IDENT, IF_ELSE_ST, IF_ST,
    INDEX, INT_NODE, LE, LOGICAL_AND, LOGICAL_NOT,
    LOGICAL_OR, LT, MOD, MOD_ASSIGN, MUL,
    MUL_ASSIGN, NE, NUMBER, PARAM_DCL, POST_DEC,
    POST_INC, PRE_DEC, PRE_INC, PROGRAM, RETURN_ST,
    SIMPLE_VAR, STAT_LIST, SUB, SUB_ASSIGN, UNARY_MINUS,
    VOID_NODE, WHILE_ST
};

char* nodeName[] = {
    "ACTUAL_PARAM", "ADD",         "ADD_ASSIGN",  "ARRAY_VAR",   "ASSIGN_OP",
    "CALL",         "COMPOUND_ST", "CONST_NODE",  "DCL",         "DCL_ITEM",
    "DCL_LIST",     "DCL_SPEC",    "DIV",         "DIV_ASSIGN",  "EQ",
    "ERROR_NODE",   "EXP_ST",      "FORMAL_PARA", "FUNC_DEF",    "FUNC_HEAD",
    "GE",           "GT",          "IDENT",       "IF_ELSE_ST",  "IF_ST",
    "INDEX",        "INT_NODE",    "LE",          "LOGICAL_AND", "LOGICAL_NOT",
    "LOGICAL_OR",   "LT",          "MOD",         "MOD_ASSIGN",  "MUL",
    "MUL_ASSIGN",   "NE",          "NUMBER",      "PARAM_DCL",   "POST_DEC",
    "POST_INC",     "PRE_DEC",     "PRE_INC",     "PROGRAM",     "RETURN_ST",
    "SIMPLE_VAR",   "STAT_LIST",   "SUB",         "SUB_ASSIGN",  "UNARY_MINUS",
    "VOID_NODE",    "WHILE_ST"
};

int ruleName[] = {
    0, PROGRAM, 0, 0, 0,
    0, FUNC_DEF, FUNC_HEAD, DCL_SPEC, 0,
    0, 0, 0, CONST_NODE, INT_NODE,
    VOID_NODE, 0, FORMAL_PARA, 0, 0,
    0, 0, PARAM_DCL, COMPOUND_ST, DCL_LIST,
    DCL_LIST, 0, 0, DCL, 0,
    0, DCL_ITEM, DCL_ITEM, SIMPLE_VAR, ARRAY_VAR,
    0, 0, STAT_LIST, 0, 0,
    0, 0, 0, 0, 0,
    0, EXP_ST, 0, 0, IF_ST,
    IF_ELSE_ST, WHILE_ST, RETURN_ST, 0, 0,
    ASSIGN_OP, ADD_ASSIGN, SUB_ASSIGN, MUL_ASSIGN, DIV_ASSIGN,
    MOD_ASSIGN, 0, LOGICAL_OR, 0, LOGICAL_AND,
    0, EQ, NE, 0, GT,
    LT, GE, LE, 0, ADD,
    SUB, 0, MUL, DIV, MOD,
    0, UNARY_MINUS, LOGICAL_NOT, PRE_INC, PRE_DEC,
    0, INDEX, CALL, POST_INC, POST_DEC,
    0, 0, ACTUAL_PARAM, 0, 0,
    0, 0, 0
};

char* tokenName[] = {
    "!", "!=", "%","%=","%ident","%number",
    "&&","(",")","*","*=","+",
    "++","+=",",","-","--","-=",
    "/","/=",";","<","<=","=",
    "==",">",">=","[","]","eof",

    "const","else","if","int","return","void",
    "while","{","||","}"
};

void semantic(int n) {
    printf("reduced rule number = %d\n", n);
}

void printToken(struct tokenType token) {
    if (token.tokenNumber == tident) printf("%s", token.tokenValue);
    else if (token.tokenNumber == tnumber) printf("%s", token.tokenValue);
    else printf("%s", tokenName[token.tokenNumber]);
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
        if (tok.tokenNumber = teof) exit(1);
        if (tok.tokenNumber == tlparen) parenthesisCount++;
        else if (tok.tokenNumber == trparen) parenthesisCount--;
        if (tok.tokenNumber == tlbrace) braceCount++;
        else if (tok.tokenNumber == trbrace) braceCount--;
        if ((tok.tokenNumber == tsemicolon) && (parenthesisCount <= 0) && (braceCount <= 0)) break;

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

int meaingfulToken(struct tokenType token) {
    if ((token.tokenNumber == tident) || (token.tokenNumber == tnumber)) return 1;
    else return 0;
}

Node* buildNode(struct tokenType token)
{
    Node* ptr;

    ptr = (Node*)malloc(sizeof(Node));

    if (!ptr) {
        printf("malloc error in buildNode()\n");
        exit(1);
    }

    ptr->token = token;
    ptr->noderep = terminal;
    ptr->son = ptr->brother = NULL;
    return ptr;
}

Node* buildTree(int nodeNumber, int rhsLength)
{
    int i, j, start;
    Node* first, * ptr;

    i = sp - rhsLength + 1;
    while (i <= sp && valueStack[i] == NULL) i++;
    if (!nodeNumber && i > sp) return NULL;
    start = i;

    while (i <= sp - 1) {
        j = i + 1;
        while (j <= sp && valueStack[j] == NULL) j++;
        if (j <= sp) {
            ptr = valueStack[i];
            while (ptr->brother) ptr = ptr->brother;
            ptr->brother = valueStack[j];
        }
        i = j;
    }
    first = (start > sp) ? NULL : valueStack[start];

    if (nodeNumber) {
        ptr = (Node*)malloc(sizeof(Node));
        if (!ptr) {
            printf("malloc error in buildTree()\n");
            exit(1);
        }
        ptr->token.tokenNumber = nodeNumber;
        ptr->token.tokenValue = NULL;
        ptr->noderep = nonterm;
        ptr->son = first;
        ptr->brother = NULL;
        return ptr;
    }
    else return first;
}

void printNode(Node* pt, int indent)
{
    extern FILE* astFile;
    int i;

    for (i = 1; i <= indent; i++) {
        fprintf(astFile, "  ");
    }

    if (pt->noderep == terminal) {
        if (pt->token.tokenNumber == tident) fprintf(astFile, " Terminal: %s", pt->token.tokenValue);
        else if (pt->token.tokenNumber == tnumber) fprintf(astFile, " Terminal: %d", pt->token.tokenValue);//
    }
    else {
        int i;
        i = (int)(pt->token.tokenNumber);
        fprintf(astFile, " Nonterminal: %s", nodeName[i]);
    }
    fprintf(astFile, "\n");
}

void printTree(Node* pt, int indent)
{
    Node* p = pt;
    while (p != NULL) {
        printNode(p, indent);
        if (p->noderep == nonterm) {
            printTree(p->son, indent + 5);
        }
        p = p->brother;
    }
}

Node* parser()
{
    extern int parsingTable[NO_STATES][NO_SYMBOLS + 1];
    extern int leftsymbol[NO_RULES + 1], rightLength[NO_RULES + 1];
    int entry, ruleNumber, lhs;
    int currentState;
    struct tokenType token;
    Node* ptr;

    sp = 0; stateStack[sp] = 0;
    token = scanner(source_file);
    while (1) {
        currentState = stateStack[sp];
        entry = parsingTable[currentState][token.tokenNumber];
        if (entry > 0) {
            //sp++;
            if (++sp > PS_SIZE) {
                printf("critical compiler error: parsing stack overflow");
                exit(1);
            }
            symbolStack[sp] = token.tokenNumber;
            stateStack[sp] = entry;
            valueStack[sp] = meaingfulToken(token) ? buildNode(token) : NULL;
            token = scanner(source_file);
        }
        else if (entry < 0) {
            ruleNumber = -entry;
            if (ruleNumber == GOAL_RULE) { 
                return valueStack[sp - 1];
            }
            //semantic(ruleNumber);
            ptr = buildTree(ruleName[ruleNumber], rightLength[ruleNumber]);
            sp = sp - rightLength[ruleNumber];
            lhs = leftSymbol[ruleNumber];
            currentState = parsingTable[stateStack[sp]][lhs];
            symbolStack[++sp] = lhs;
            stateStack[sp] = currentState;
            valueStack[sp] = ptr;
        }
        else {
            printf(" === error in source ===\n");
            printf("Current Token : ");
            printToken(token);
            dumpStack();
            errorRecovery();
            token = scanner(source_file);
        }
    }
}

int main() {
    Node* root;

    source_file = fopen("perfect.mc", "rt");
    if (!source_file) {
        fprintf(stderr, "mc file can't open\n");
        return -1;
    }
  
    astFile = fopen("perfect.ast", "w");
    if (!astFile) {
        fprintf(stderr, "Ast file can't open\n");
        return -1;
    }
   

    printf("start of parser \n");
    root = parser();
    printTree(root,0);
    printf("end of parser \n");

    fclose(source_file);
    fclose(astFile);
}
/*
 * tokenizer.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */
int isDelim(char *, char);
struct TokenizerT_ {
    char *sep;
    char *string;
    int pos;
};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given set of separator
 * characters (given as a string) and a token stream (given as a string).
 *
 * TKCreate should copy the two arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate(char *separators, char *ts) {
    if(!(separators ==NULL && ts==NULL)){
        TokenizerT *ptr;
        ptr = (TokenizerT *)malloc(sizeof(TokenizerT));
        ptr->sep = (char *)malloc(sizeof(char)*(strlen(separators)+1));
        strcpy(ptr->sep,separators);
        ptr->string = (char *)malloc(sizeof(char)*(strlen(ts)+1));
        strcpy(ptr->string,ts);
        ptr->pos = 0;
        return ptr;
    }

    return NULL;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy(TokenizerT *tk) {
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken(TokenizerT *tk) {
    static char buffer[2000];
    while(tk->string[tk->pos] != '\0'){
        if(isDelim(tk->sep, tk->string[tk->pos]) == 1){
            buffer[tk->pos] = '\0';
        }



        tk->pos++;

   }

    return NULL;
}

/*
 * main will have two string arguments (in argv[1] and argv[2]).
 * The first string contains the separator characters.
 * The second string contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int isDelim(char *delims, char token){
    int i;
    for(i = 0; i<strlen(delims); i++){
        if(delims[i] == token){
            return 1;
        }
    }
    return 0;
}
/*
char *escapeReplace(char escapeChar){
    if(escapeChar == 'n'){
        return "[0x0a]";
    }
    if(escapeChar == 't'){
        return "[0x09]";
    }
    if(escapeChar == 'v'){
        return "[0x0b]";
    }
    if(escapeChar == 'b'){
        return "[0x08]";
    }
    if(escapeChar == 'r'){
        return "[0x0d]";
    }
    if(escapeChar == 'f'){
        return "[0x0c]";
    }
    if(escapeChar == 'a'){
        return "[0x07]";
    }
    if(escapeChar == '\'){
        return "[0x5c]";
    }
    if(escapeChar == '"'){
        return "[0x22]";
    }
    return NULL;
}*/



int main(int argc, char **argv) {
    if(argc != 3){
        return -1;
    }

    TokenizerT *tokObject =  TKCreate(argv[1], argv[2]);
    printf(" %s %s\n",tokObject->sep, tokObject->string);


    return 0;
}

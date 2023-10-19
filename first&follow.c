#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 100

char production[MAX_RULES][MAX_SYMBOLS];
char firstSets[26][MAX_SYMBOLS];  // Assuming non-terminals are uppercase letters
char followSets[26][MAX_SYMBOLS],nonterminal;

int numRules = 0,i,j;

void addToSet(char set[26][MAX_SYMBOLS], char nonterminal, char symbol) {
    int ntIndex = nonterminal - 'A';
    int i;

    for (i = 0; set[ntIndex][i] != '\0'; i++) {
        if (set[ntIndex][i] == symbol) {
            return;  // Symbol already in the set
        }
    }

    set[ntIndex][i] = symbol;
    set[ntIndex][i + 1] = '\0';
}

void computeFirstSet(char nonterminal) {
    for (i = 0; i < numRules; i++) {
        if (production[i][0] == nonterminal) {
            int j = 2;
            while (production[i][j] != '\0') {
                char symbol = production[i][j];

                if (isupper(symbol)) {
                    computeFirstSet(symbol);
                    int k = 0;
                    while (firstSets[symbol - 'A'][k] != '\0') {
                        if (firstSets[symbol - 'A'][k] != '#') {
                            addToSet(firstSets, nonterminal, firstSets[symbol - 'A'][k]);
                        }
                        k++;
                    }

                    if (firstSets[symbol - 'A'][k] == '\0') {
                        j++;  // Move to the next symbol in the production
                    }
                } else if (symbol == '#') {
                    addToSet(firstSets, nonterminal, symbol);
                    break;
                } else {
                    addToSet(firstSets, nonterminal, symbol);
                    break;
                }
            }
        }
    }
}

void computeFollowSet(char nonterminal) {
    if (production[0][0] == nonterminal) {
        addToSet(followSets, nonterminal, '$');
    }

    for ( i = 0; i < numRules; i++) {
        for ( j = 2; production[i][j] != '\0'; j++) {
            if (production[i][j] == nonterminal) {
                j++;

                while (production[i][j] != '\0') {
                    char symbol = production[i][j];

                    if (isupper(symbol)) {
                        int k = 0;
                        while (firstSets[symbol - 'A'][k] != '\0') {
                            if (firstSets[symbol - 'A'][k] != '#') {
                                addToSet(followSets, nonterminal, firstSets[symbol - 'A'][k]);
                            }
                            k++;
                        }

                        if (firstSets[symbol - 'A'][k] == '\0') {
                            j++;
                        }
                    } else if (symbol == '#') {
                        j++;
                    } else {
                        addToSet(followSets, nonterminal, symbol);
                        break;
                    }
                }

                if (production[i][j] == '\0') {
                    if (production[i][0] != nonterminal) {
                        computeFollowSet(production[i][0]);
                    }
                }
            }
        }
    }
}

int main() {
    // Initialize production rules
    numRules = 8;
    strcpy(production[0], "X=TnS");
    strcpy(production[1], "X=Rm");
    strcpy(production[2], "T=q");
    strcpy(production[3], "T=#");
    strcpy(production[4], "S=p");
    strcpy(production[5], "S=#");
    strcpy(production[6], "R=om");
    strcpy(production[7], "R=ST");

    // Compute First and Follow sets
    for ( nonterminal = 'A'; nonterminal <= 'Z'; nonterminal++) {
        computeFirstSet(nonterminal);
        computeFollowSet(nonterminal);
    }

    // Print First and Follow sets
    for ( nonterminal = 'A'; nonterminal <= 'Z'; nonterminal++) {
        printf("First(%c): { %s }\n", nonterminal, firstSets[nonterminal - 'A']);
        printf("Follow(%c): { %s }\n", nonterminal, followSets[nonterminal - 'A']);
    }

    return 0;
}


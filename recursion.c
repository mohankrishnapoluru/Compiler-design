#include <stdio.h>
#include <string.h>
int main() {
    char a[100],b[100], c[100];
    printf("Enter a production: ");
    gets(a);
    if (a[0] == a[3]) {
        char f = a[0]; // Assuming the first character is the non-terminal symbol
        int i, j, n=0;
        // Parse the right-hand side of the production
        for (i = 4, j = 0; a[i] != '\0' && a[i] != '/'; i++, j++) {
            b[j] = a[i];
        }
        b[j] = '\0';
        if (a[i] == '/') {
            i++; // Skip the '/' character
            for (j = 0; a[i] != '\0'; j++, i++) {
                c[j] = a[i];
            }
            c[j] = '\0';
            n = j;
        }
        // Print the left-factored production
        printf("%c -> %s%c'\n", f, c, f);
        
        printf("%c' -> %s%c' | $\n", f, b, f);

    } else {
        printf("Not a left recursion.\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *str;
    char append_str[100];
    int len;


    str = (char*)malloc(100 * sizeof(char));  // Initial allocation of 100 characters
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    printf("Enter a string: ");
    fgets(str, 100, stdin);


    str[strcspn(str, "\n")] = '\0';


    printf("Enter a string to append: ");
    fgets(append_str, 100, stdin);
    append_str[strcspn(append_str, "\n")] = '\0';  // Remove newline


    str = realloc(str, (strlen(str) + strlen(append_str) + 1) * sizeof(char));
    strcat(str, append_str);  // Append the string


    len = strlen(str);


    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }


    printf("Modified String: %s\n", str);
    printf("Length of the String: %d\n", len);


    free(str);

    return 0;
}


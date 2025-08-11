#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* pangrams(char* s) {
    /*
    int result[26]={0};
for(int i=0;s[i]!='\0';i++)
{
   if((int)s[i]<=90 && (int)s[i]>=65)
            s[i]=(int)s[i]+32;
}
for(int i=0;i<s[i]!='\0';i++)
{
    result[(int)s[i]-97]++;
}
for(int i=0;i<26;i++)
    if(result[i]==0)
        return "pangram";
return "not pangram";
*/
    int result[26] = {0}; // An array to track each letter.

    // Iterate through the entire string until the null terminator ('\0').
    for (int i = 0; s[i] != '\0'; i++) {
        // Convert the character to lowercase for case-insensitivity.
        // The tolower() function also handles non-alphabetic characters safely.
        char c = tolower(s[i]);
        
        // Check if the character is a lowercase letter.
        if (c >= 'a' && c <= 'z') {
            // Increment the count for the corresponding letter.
            result[c - 'a']++;
        }
    }

    // Check if every letter from 'a' to 'z' was present.
    for (int i = 0; i < 26; i++) {
        // If any letter's count is zero, it's not a pangram.
        if (result[i] == 0) {
            return "not pangram";
        }
    }

    // If all letters were found, it's a pangram.
    return "pangram";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = pangrams(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

/*#include<stdio.h>
#include<string.h>

int countWordOccurences (char input_string[], int string_len)
{
    char word_for_checking[15];
    int i = 0, j = 0;
    for(int i = 0; i < (string_len-1); i++)
    {
        while((strcmp(string_len, " ")) != 0 && (strcmp(string_len, ".")) != 0 && (strcmp(string_len, ",")) != 0 
        && (strcmp(string_len, "!")) != 0 && (strcmp(string_len, "(")) != 0 && (strcmp(string_len, ")")) != 0 
        && (strcmp(string_len, "!")) != 0 && (strcmp(string_len, "?")) != 0 && (strcmp(string_len, ";")) != 0 
        && (strcmp(string_len, ":")) != 0 && (strcmp(string_len, "'")) != 0 && (strcmp(string_len, "\"")) != 0
        )
        {
            word_for_checking[i];
            i++;
        }
        while(j+strlen(word_for_checking) < string_len)
        {
            strcmp(word_for_checking, [j+strlen(word_for_checking)]);
            j++;
        }
    }
}

int main()
{
    int string_len;
    printf("Please enter the length of the string:\n");
    scanf("%d", &string_len);
    while (getchar() != '\n');
    char input_string[string_len-1];
    printf("\nEnter the string:");
    fgets(input_string, string_len, stdin);

    printf("\n----------------------------------------------------------------------------------------------------------\n");

    countWordOccurences(input_string, string_len);
}
*/
// step 1: string/array input
// step 2: preprocessing (choose word)
// step 3: check singular word in list
// step 3.1: add singular word to new array which contains found unique words
// step 4: print frequency
// step 5: repeat 2 3 4 till end of line appending to new array and crosschecking constantly

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void countWordOccurrences(char text[]);

void countWordOccurrences(char text[]) {
    WordCount words[MAX_WORDS];
    int wordIndex = 0;
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;

    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].count = 0;
    }

    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            if (wordLength < MAX_WORD_LENGTH - 1) {
                word[wordLength++] = text[i];
            }
        } else {
            if (wordLength > 0) {
                word[wordLength] = '\0';
                int found = 0;
                for (int j = 0; j < wordIndex; j++) {
                    if (strcmp(words[j].word, word) == 0) {
                        words[j].count++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(words[wordIndex].word, word);
                    words[wordIndex].count = 1;
                    wordIndex++;
                }

                wordLength = 0;
            }
        }
    }

    if (wordLength > 0) {
        word[wordLength] = '\0';
        int found = 0;
        for (int j = 0; j < wordIndex; j++) {
            if (strcmp(words[j].word, word) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordIndex].word, word);
            words[wordIndex].count = 1;
            wordIndex++;
        }
    }

    for (int i = 0; i < wordIndex; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char text[] = "Hello, world! Hello... How are you? Are you fine? Hello, are you there?";
    countWordOccurrences(text);
    return 0;
}
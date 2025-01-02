/* MANAN 23
 * By: Tal Anaf
 * This program will promote the user to enter a name of a file. The program will read the name
 * and it will read the text in the file. The program will sort the words in the test to lexicon order
 * and will print each word all line numbers the word in it.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Defined the param struct. the param will include the word and the lines the word in it*/
typedef struct param{
    char* word;
    int row;
    char place[100];

}param;

param* words = NULL;
int wordCount = 0;
/*This program will check if the word is already defined.
 * If so , she will return the index number of the word and if not she will return -1.
 */
int indexCheck(param newInx){
    int i;
    for(i = 0; i < wordCount; i++){
        /* A loop to get through all the words and check them */
        if(strcmp(newInx.word, words[i].word) == 0){
            return i;
        }
    }
    return -1;
}
/* A function to sort the words to lexico order*/
void indexSort(){
    int i, j;
    param temp;
    for(i = 0; i < wordCount-1; i++){
        for(j = i+1; j < wordCount; j++){
            if(strcmp(words[i].word, words[j].word) > 0){
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main(){
    /* Defined the string for the file name */
    char fileName[100];
    int maxl = 100;
    int i = 1;
    char* line = malloc(maxl * sizeof(char));
    FILE* input;
    param new_Word;
    int idx;
    printf("Please enter the file name (including the file type and make sure the file's name is no longer than 100 chars): \n ");
    scanf("%s", fileName);
    
    /* Dynamic memory allocation for the file */

    words = malloc(maxl * sizeof(param));
    /* Checks if the dynamic memory allocation has succeed*/
    if (line==NULL || words==NULL) {
        printf("Memory not allocated!\n");
        return 1;
    }
    /* Getting the file and checks if the file is valid*/
    input = fopen(fileName, "r");
    if(input == NULL){
        printf("Error of opening file! \n");
        return 1;
    }
    /*A loop to sort and define the lines appearence

     */
    while( fgets(line,maxl,input) != NULL){
        /* a char pointer to devied between words */
        char* token = strtok(line, " ");
        while (token != NULL) {
            /* Make sure there is no "\n" in the word
             */
            token[strcspn(token, "\n")] = 0;

            /* Allocate memory for the word
             */
            new_Word.word = malloc(strlen(token) + 1);
            /*Copy the token into the new memory space*/
            strcpy(new_Word.word, token);
            new_Word.row = i;
            /* Checks if the word is already defined*/
            idx = indexCheck(new_Word);
            /* If function in case the word is already showed it the text */
            if (idx != -1){
                char temp[5];
                /* Adding the number of line to it */
                sprintf(temp, ", %d  " , i);
                strcat(words[idx].place,temp);
            }
            else {
                /* In case of the word is new in the text */
                sprintf(new_Word.place, " %d  " , i);
                /* Moving to the next word */
                words[wordCount++] = new_Word;
            }
            token = strtok(NULL, " ");
        }
        /* Moving to the next word */
        i++;
    }
    /* Calling to indexSort function to sort the words into lexico order */
    indexSort();
    /* A loop to print all the words */
    for(i = 0; i < wordCount; i++){
        /* Checks if there is more than one line for a word */
        if(strlen(words[i].place)>4){
            printf("%s appears in lines %s\n", words[i].word, words[i].place);
        }
        else{
            printf("%s appears in line %s\n", words[i].word, words[i].place);

        }
    }
    /* Closes the file and free the memory */
    fclose(input);
    free(line);
    free(words);

    return 0;
}
/* End of program */

/*
 -------------------------------------
 File:    myword.c
 Project: wali6947_a03
 file description
 -------------------------------------
 Author:  Ahmad Wali
 ID:      169036947
 Email:   wali6947@mylaurier.ca
 Version  2025-01-31
 -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000


/*
 * Load word data from file, and insert words a directory represented by char array.
 * Also, an auxilary helper function to convert characters to lowercase.
 * 
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
void toLowercase(char *line) {
	int current_index = 0;
	char current_char = *(line + current_index);
	while (current_char != '\0') {
		if ((current_char >= 65 && current_char <= 90)) {
			*(line + current_index) = current_char + 32;
		}
		current_index += 1;
		current_char = *(line + current_index);
	}
}



/*
 * Load word data from file, and insert words a directory represented by char array.
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
int create_dictionary(FILE *fp, char *dictionary) {
	char line[1000];
	//char delimiters[] = " .,\n\t\r";
	char *token;
	int count = 0;
	while (fgets(line, 1000, fp) != NULL) {
		//strlwr(line)
		token = (char*) strtok(line, ",");
		toLowercase(token);
		while (token != NULL) {
			count++;
			strcat(dictionary, token);
			strcat(dictionary, ",");
			token = (char*) strtok(NULL, ",");
		}
	}
	return count;
}

/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word) {
	char temp[20] = { 0 };
	if (word == NULL || *word == '\0') {
		return FALSE;

	} else {
		//printf("WORD: %s", word);
		// assume that words are separated by comma in the dictionary array // char temp[20] = {0}; // build the searching pattern like ,word,
		strcat(temp, ",");
		strcat(temp, word);
		strcat(temp, ",");
		if (strstr(dictionary, temp)) {
			return TRUE;
		}
	}
	return FALSE;
}
/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.   
 * 
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.    
 *                     
 * @return - WORDSTATS value of processed word stats information.   
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
	WORDSTATS ws;
	ws.keyword_count = 0;
	ws.line_count = 0;
	ws.word_count = 0;
	char delimeters[] = " .,\n\t\r";
	char line[1000];
	char *word_token;
	//default all my values to 0, create a delimeter check that we know means an end
	//a character array for lines up to 1000 characters
	while(fgets(line,MAX_LINE_LEN,fp)!= NULL){
		//READ A LINE FOR THE MAXIMUM LENGTH FROM THE FP FILE. KEEP GOING UNTIL NULL 
		word_token = (char*) strtok(line,delimeters);
		ws.line_count++;
		//create pointers to the lines seperated by delimiters and increment the count
		while(word_token!=NULL){
			toLowercase(word_token);
			ws.word_count++;
			//while we have words being filled in, increment the count
			if(count_word(dictionary,word_token)==FALSE){
				int j = 0;
				while (j<ws.keyword_count && strcmp(word_token,words[j].word)!= 0){
					j++;
				}
				if (j<ws.keyword_count){
					words[j].count++;
				}else{
					strcpy(words[j].word,word_token);
					words[j].count = 1;
					ws.keyword_count++;
				}
			}
			word_token = (char*) strtok(NULL,delimeters);
		}

	}
	return ws;
}


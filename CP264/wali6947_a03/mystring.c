/*
 -------------------------------------
 File:    mystring.c
 Project: dhil6351_a03
 file description
 -------------------------------------
 Author:  Ahmad Wali
 ID:      169036947
 Email:   wali6947@mylaurier.ca
 Version  2025-01-31
 -------------------------------------
 */
/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.  
 *
 * @param s - char pointer to a string
 * @return - return the number of words. 
 */
int str_words(char *s) {
	char prev = *s;
	char curr;
	int count = 0;

	int len = sizeof(*s);

	for (int i = 1; *(s + i) != '\0'; i++) {
		curr = *(s + i);
		//loop through the whole string until the end, incrementing the pointer
		if (((prev >= 'A' && prev <= 'Z') || (prev >= 'a' && prev <= 'z'))
		//if we encounter a letter but a space or sommething breaks it up, end the word and we add to the coint
				&& (curr == ' ' || curr == '\t' || curr == ',' || curr == '.')) {
			count++;
		}
		prev = curr;
	}
	//same logic as above but using pointer notation
	if ((*(s + len - 1) >= 'A' && *(s + len - 1) <= 'Z')
			|| (*(s + len - 1) >= 'a' && *(s + len - 1) <= 'z')) {
		count++;
	}

	return count;
}
/**
 * Change every upper case English letter to its lower case of string passed by s
 * @param s - char pointer to a string
 * @return - return the number of actual flips.   
 */
int str_lower(char *s){
	int flips = 0;
	//if we have a string thats an uppercase letter, add 32 so we get
	//the ascii value of its lowercase variant
	for (int i = 0; *(s + i) != '\0'; i++) {
		if (*(s + i) >= 'A' && *(s + i) <= 'Z') {
			*(s + i) += 32;
			flips++;
		}
	}

	return flips;
}
/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s){
	char *p = s, *dp = s;
	//while we arent pointing to a null value, if we encounter a space,
	while (*p) {
		//looping through the whole string, if we do not encounter a space or our previous isnt a space, we keep going
		if ((*p != ' ') || (p > s && *(p - 1) != ' ')) { 
			*dp = *p;
			dp++;        
		}
		p++;
	}
	if (*(p - 1) != ' ') {//once were at the end of hte string, manually check the end is good (edge case)
		*dp = '\0';
	} else {
		//i
		*(dp - 1) = '\0';
	}
	return;
}
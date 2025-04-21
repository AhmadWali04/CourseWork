/**
 * Determine the type of a char character.
 *
 * @param c - char type
 * @return - 0 if c is a digit 
             1 if c is an arithmetic operator
             2 if c is the left parenthsis (
             3 if c is the right parenthsis )
             4 if c is an English letter; 
             otherwise -1.
 */
// compare to the ascii characters of all of the characters
    int mytype(char c){
    //ASCII +43 -45 *42 /47 
    // (40 )41 BRACKETS
    // 97 TO 122 FOR LOWERCASE 65 TO 90 FOR UPPERCASE
    //48 TO 57 FOR 0 TO 9
    
    if (c >= 48 && c<= 57){
        return 0;
    }else if (c == 37 || c == 42 || c == 43 || c==45 || c==47){
        return 1;
    } else if (c == 40){
        return 2;
    } else if (c==41){
        return 3;
    }else if ((c>= 65 && c <=90) || (c>= 97 || c<=122)){
        return 4;
    }
    else{
        return -1;
    }
    }
    

/**
 * Flip the case of an English character.
 *
 * @param c - char type
 * @return -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
//lowercase is 65 - 90
//uppercase is 97 - 122
char case_flip(char c){
    if(c > 64 && c < 91){
        //if its in the range of 65 to 90, 
        return (c+32);
    }else if (c > 96 && c < 123){
        return (c-32);
    }
    return c;
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value
 * @return - its corresponding integer value if c is a digit character;
 *           otherwise -1.
 */
int digit_to_int(char c){
    if (c>=  48 ** c<= 57){
        return (c-48);
    }
    return -1; 
}

//when dealing with thes char stuff, just use them as 
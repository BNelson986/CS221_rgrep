/**
 * You can modify this file.
 */

#include "matcher.h"

#define FALSE 0
#define TRUE 1

/**
 * Your helper functions can go below this line
 */

/**
 * Your helper functions can go above this line
 */


/**
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
int matches_leading(char *partial_line, char *pattern) {
	
	//	End of partial line, No Match
	if(*partial_line == '\0' && *pattern != '\0'){
		return FALSE;
	}
	
	//	End of pattern, Match
	if(*pattern == '\0'){
		return TRUE;
	}

	/*
	 * 	Checks for special characters
	 *	pattern typecasted to int to check for '\'
	 */

	//	Check for backslash
	if((int) *pattern == 92){
	    	if(*partial_line == *(pattern + 1)){
                	return matches_leading(partial_line + 1, pattern + 2);
        	}
        	return FALSE;
	}
	//	Check for question mark
	if((int) *(pattern + 1) == 63){
		if(*partial_line == *pattern){
			return matches_leading(partial_line + 1, pattern + 2);	
		}
		else{
			return matches_leading(partial_line, pattern + 2);
		}
	}
	//	Check for plus sign
	if((int) *pattern == 43){
		//      If line char matches char before +, continue
        	if(*partial_line == *(pattern - 1)){
                	return matches_leading(partial_line + 1, pattern);
        	}
		//	Edge case of + being last char before terminator
		if(*(pattern + 1) == '\0'){
			return TRUE;
		}
        	return matches_leading(partial_line + 1, pattern + 2);
	}
	//	Check for period
	if((int) *pattern == 46){
		return matches_leading(partial_line + 1, pattern +1);
	}
	
	//	If chars match, continue comparisons
	if(*partial_line == *pattern){
		return matches_leading(partial_line + 1, pattern + 1);
	}

	return FALSE;
}

/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char *line, char *pattern) {
	
  	//	Base case (End of line)
	if(*line == '\0'){
		return FALSE;
   	}
	
	//	Characters match each other
   	if(*line == *pattern){
		if(matches_leading(line, pattern)){
			return TRUE;
		}
		else{
			return rgrep_matches(line + 1, pattern);
		}
	}		

    return rgrep_matches(line + 1, pattern);
}








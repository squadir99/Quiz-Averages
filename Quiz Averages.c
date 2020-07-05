/*
Author: Sohail Quadir
Date: 12/7/2019
Purpose: The purpose of this program is to read a list of names and test scores from one file, and format them and find the average of each test score
and write them to another file. 
Sources of Help: Tutor
Time Spent: 13 hours
*/
#include <stdio.h>
#include <stdlib.h>


void readAndWriteNames(FILE* fInput, FILE* fOutput, char strLast[], char strFirst[]);
void readAndWriteScores(FILE* fInput, FILE* fOutput);
int main(int argc, const char* argv[]) {
	FILE* fInput = fopen("quiz.txt", "r");
	FILE* fOutput = fopen("average.txt", "w");

	char LastName[20] = "";
	char FirstName[20] = "";

	if (fInput && fOutput) {
		//printf("Both files were opened successfully.\n");
		
		while (!feof(fInput)) {
			readAndWriteNames(fInput, fOutput, LastName, FirstName);
			readAndWriteScores(fInput, fOutput);
		}
	}
	else {
		printf("Neither of the files were opened successfully.\n");
	}

	fclose(fInput);
	fclose(fOutput);

	return 0; 
}

void readAndWriteNames(FILE* fInput, FILE* fOutput, char strLast[], char strFirst[]) { //This function reads only the names of the file and writes them to the output file. 
	char ch;
	ch = fgetc(fInput);
	if (ch == EOF) {
		return;
	}
	int i = 0;
	while (ch != ' ') {
		strFirst[i] = ch;
		ch = fgetc(fInput);
		i++;
	}
	strFirst[i] = '\0';
	i = 0;
	ch = fgetc(fInput);
	while (ch != ' ' && ch != '\n' && ch != EOF) {
		strLast[i] = ch;
		ch = fgetc(fInput);
		i++;
	}
	strLast[i] = '\0';
	fprintf(fOutput, "%s, %s ", strLast, strFirst);
}

void readAndWriteScores(FILE* fInput, FILE* fOutput) { //This function reads only the scores, writes them to the output file, then calculates the average and writes the average to the output file. 
	int num;
	int sum = 0;
	int numCounter = 0; 
	while (fscanf(fInput, "%d", &num) == 1) {
		sum = sum + num;
		numCounter++;
		fprintf(fOutput, "%4d ", num);
	}
	for (int i = 0; i < 10 - numCounter; i++) {
		fprintf(fOutput,"%d ", 0);
	}
	fprintf(fOutput, "%10f\n", sum / 10.0);
}

/* Computing I -- COMP.1010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for 
students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University's Academic 
Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the 
course catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course 
academic policy on the course website on Blackboard, and the UMass Lowell academic code.
Date: 12/7/2019
Name: Sohail Quadir
*/
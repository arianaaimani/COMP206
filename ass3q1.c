#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
 int sum = 0, count = 0;   //initiates the sum and count to 0
 int i=0;                  // initiates the variable fro the loop
	 
FILE* ptr=fopen(argv[1], "rt");
 char str[4096];          //just storing an array of characters of size 4096

    if (ptr==NULL){                         
        perror("Error while opening file");
        exit(EXIT_FAILURE);                      //this deals with opening the file. if it's null it will read out an 								error message
    } 
   while(!feof(ptr)){
	char s; 
	s = fgetc(ptr);   //getting characters from the file. 

	if(s != ',' && (!isdigit(s))) { //printing the experiment names
		if(sum!=0) {
		double result= (double)sum/(double)count; //casting the int variables into doubles
		printf(" %.2lf\n", result);               
		sum = 0;
		count = 0;
		}
		printf("%c", s);           //printing statement for experiment anmes
}

if(s == ',') {
	fscanf(ptr, "%d", &i);
	sum+=i;
	count++;                  //incrememnting the counter and the sum
}
}
printf("%d\n", sum/count); //printing out the average
fclose(ptr);  //closing the file
return 0;    
}

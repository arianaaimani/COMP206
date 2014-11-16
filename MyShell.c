#include <stdio.h>
#include <string.h>
#define DELIM " \n"

char cmdname[322];                //this allocates the space for amount of characters for the command name. 
char *cmdstring = "MEOW";         // first command. 

int main (int argc, char *argv()) 
{
   while(1)
{
printf("%s ", cmdstring);  //printing the cmdstring
fgets(cmdname, sizeof(cmdname), stdin);  //getting the command name from the user through the stdin
char *tken = strtok(cmdname, DELIM);

if(strcasecmp(tken, "set") == 0) // comparing the cases of strings to set
{
	tken = strtok(NULL, DELIM);
	
	if(strcasecmp(tken, "Prompt") == 0)
	{
		tken = strtok(NULL, DELIM);
		cmdstring = tken;          //setting tken to cmdstring

}
}

else if(strcasecmp(tken, "quit") == 0)
break;

else
	system(cmdname);
}
return 0;
}

		

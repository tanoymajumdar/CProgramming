#include<stdio.h>
#include<string.h>

// Task2. Build the toLower() function here.
void toLower(char a[]){
     // To be implemented by you.
 for ( int i=0; i<strlen(a); i++)
{
	if (a[i]>=65 && a[i]<=90)
	{
		a[i] += 32;}
}

}

int main(){
     char input[100];
     // Task 1. Read in user input to the char array input.

	scanf ("%s", input);
     
     // Task 3. Call the toLower function.    

	toLower(input);


     printf("%s",input);
     return 0;
}

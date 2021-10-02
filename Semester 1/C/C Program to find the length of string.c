//CODE BY 32200091_ANDREW VIRYA VICTORIO//
//C PROGRAM TO FIND LENGTH OF STRING

/* Mohon maaf kalau menggunakan bahasa inggris, saya sedikit
bingung kalau pakai bahasa terapan */

//Method 1 :
//Using loop to calculate the length of the string
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char Str[1000];       //char var [array];
	int i;                //Declaration

	printf("Enter the String : "); //write : str
	scanf("%s", Str);             //read : str

	for (i = 0; Str[i] != '\0'; ++i); //looping condition

	printf("Length of String is %d", i); //write : str

	return 0; 
}

/*Output : 
Enter the String : Andrew
Length of Str is 6 */


//Method 2 :
//Using scanf() function to find string length
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char Str[1000];         //char var[array]
	int i;                  //DECLARATION

	printf("Enter the String : "); //write : string
	scanf("%s", Str);              //read (format, var)

	printf("Length of String is %ld", strlen(Str)); //write : ("string :: format", strlen(var));

	return 0; 
} 

/* Input : Andrew
   Output : Length of Str is 6 */

//NOTE : THE FUNCTION DOESN'T WORK IF THE STRING HAS SPACE IN IT!! //
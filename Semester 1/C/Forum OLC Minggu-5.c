/*3.  Buatlah program yang mendeklarasikan sekaligus menginisialisasi 
sebuah array kata1[], kemudian copy-lah isi array kata1[] tsb ke dalam array kata2[], 
selanjutnya tampilkan isi kedua array tsb ke layar */

/*strcpy() is a standard library function in C/C++ and is used to copy one string to another. 
In C it is present in string.h header file and in C++ it is present in cstring header file. */

//SYNTAX
//char* strcpy(char* dest, const char* src);

/*Parameters: This method accepts following paramters:

    dest: Pointer to the destination array where the content is to be copied.
    src: string which will be copied. */


//CODE by 32200091_Andrew Virya Victorio
// C program to illustrate 
// strcpy() function 
#include<stdio.h> 
#include<string.h> 

int main () 
{ 
	char kata1[]="Coding is Fun";         //char var1[] : string text
	char kata2[] = "Fun is Coding";      //char var2[] : string text
	char kata3[40];                      //char var3[array];
	char kata4[40];                      //char var4[array];
	char kata5[] = "Good Luck in Programming";                //char var5[] : string text
	
	strcpy(kata2, kata1);                 //strcpy(var2, var1);
	strcpy(kata3, "Copy successful");    //strcpy(var3, string text);
	strcpy(kata4, kata5);                 //strcpy(var4, var5);
	printf ("kata1: %s\nkata2: %s\nkata3: %s\nkata4: %s\n", kata1, kata2, kata3, kata4); //write : ("var1: format string")
	return 0;                                                                          //: ("var2 : format string")
}                                                                                      //: ("var3 : format string")

/* OUTPUT 
str1: Coding is Fun
str2: Coding is Fun
str3: copy successful
str4: Good Luck in Programming
*/

/* Important Points

    1. This function copies the entire string to the destination string. 
        It doesn’t append the source string to the destination string. 
        In other words, we can say that it replaces the content of destination string by 
        the content of source string.
    2. It does not affect the source string. The source string remains same after copying.
    3. This function only works with C style strings and not C++ style strings i.e. 
        It only works with strings of type char str[]; and not string s1; which are 
        created using standard string data type available in C++ and not C.
*/



//4.  Jelaskan, sebenarnya pada fungsi strcmp() apa yang dibandingkan dalam string?

/*The function strcmp() is a built-in library function and it is declared in 
“string. h” header file. This function is used to compare the string arguments. 
It compares strings lexicographically which means it compares both the strings character by character.*/

//strcmp() is --> "string compare"
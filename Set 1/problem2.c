#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexxor(char* string1, char* string2, char* result);

int main()
{
	char* string1 = "1c0111001f010100061a024b53535009181c";
	char* string2 = "686974207468652062756c6c277320657965";
	char* result = (char*)calloc(strlen(string1), sizeof(char));
	
	hexxor(string1, string2, result);
	printf("Result: %s\n", result);
}

void hexxor(char* string1, char* string2, char* result)
{
	int length = strlen(string1);
	int counter = 0;
	
	for (int i = 0; i < length; i++)
	{
		char derp[] = " ";
		char* ptr;
		int a, b;
		
		derp[0] = string1[i];
		a = strtol(derp, &ptr, 16);
		derp[0] = string2[i];
		b = strtol(derp, &ptr, 16);
		
		snprintf(&result[i], 1, "%d", a ^ b);
	}
}
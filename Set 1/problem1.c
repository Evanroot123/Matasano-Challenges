#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertHexToB64(char* hexString, char* b64String);

int main()
{
	char* hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	char* b64String = (char*)calloc(strlen(hexString), sizeof(char));
	
	convertHexToB64(hexString, b64String);
	printf("Hex String: %s\n", hexString);
	printf("B64 String: %s\n", b64String);
}

void convertHexToB64(char* hexString, char* b64String)
{
	char* lookupString = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	
	int length = strlen(hexString);
	int position = 0;
	for (int i = 0; i < length; i += 3)
	{
		int a, b, c, ax, bx;
		char derp[] = " ";
		char* ptr;
		derp[0] = hexString[i];
		a = strtol(derp, &ptr, 16);
		derp[0] = hexString[i+1];
		b = strtol(derp, &ptr, 16);
		derp[0] = hexString[i+2];
		c = strtol(derp, &ptr, 16);
		
		ax = (a << 2) | (b >> 2);
		bx = ((b & 0x03) << 4) | c;
		
		b64String[position++] = lookupString[ax];
		b64String[position++] = lookupString[bx];
	}
}
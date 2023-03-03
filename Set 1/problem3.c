#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToAscii(char* hexString, char* asciiString);
void scoreKeys(char* cipherText, int keyRange, float* keyScores);

int main()
{
	char* cipherText = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	char* asciiCipher = (char*)calloc(strlen(cipherText) / 2, sizeof(char));
	
	convertToAscii(cipherText, asciiCipher);
	scoreKeys(
	// step 1 convert string to ascii
	// step 2 determine likely keys
}

void convertToAscii(char* hexString, char* asciiString)
{
	int length = strlen(hexString);
	
	for (int i = 0; i < length; i += 2)
	{
		char derp[] = " ";
		char* ptr;
		int a, b;
		
		derp[0] = hexString[i];
		a = strtol(derp, &ptr, 16);
		derp[0] = hexString[i+1];
		b = strtol(derp, &ptr, 16);
		asciiString[i / 2] = (a << 4) | b;
	}
	
	//printf("Ascii: %s\n", asciiCipher);
}

void scoreKeys(char* cipherText, int keyRange, float* keyScores)
{
	float letterScores[] = {8.167, 1.492, 2.202, 4.253, 12.702, 2.228, 2.015, 6.094, 6.699, 0.153, 1.292, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.356, 2.758, 0.978, 2.560, 0.150, 1.994, 0.077};
	
	for (int i = 0; i < keyRange; i++)
	{
		int length = strlen(cipherText);
		
		for (int j = 0; j < length; j++)
		{
			cipherText[length] ^ i;
		}
		
	}
}
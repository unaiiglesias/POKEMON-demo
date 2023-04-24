#include <stdio.h>
#include <string>
using namespace std;

int print_from_txt(char txt_file[])
{
	/* .txt fitxategi baten izena pasatuz gero,
	   honen edukiak inprimatzen dituen funtzioa */
	
	// Beharrezko aldagaiak deklaratu
	int c;
	FILE *file;
	
	// Irakurri beharreko fitxategia ireki
	file = fopen(txt_file, "r");
	
	// Karakterez karaktere iteratu .txt fitxategiaren edukien gainean
	// Azken karakterera (EOF) iristean, bukatu
    while ((c = getc(file)) != EOF)
    {
    	// Irakurritaku karaktere bakoitza inprimatu
    	putchar(c);
	}
	// Espazioa utzi gero gehiago inprimatzeko
	printf("\n");
	
	// Irekitako fitxategia itxi
    fclose(file);    
}


int main()
{
	print_from_txt("banner.txt");
	printf("BEGIRA: Pokemon");
}

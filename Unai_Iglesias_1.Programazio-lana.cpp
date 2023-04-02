#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"
using namespace std;

int print_from_txt(char file_name[100])
{
	/* .txt fitxategi baten izena pasatuz gero,
	   honen edukiak inprimatzen dituen funtzioa */
	
	// Jaso, txt fitxategiaren izena
	
	// Beharrezko aldagaiak deklaratu
	int c;
	FILE *file;
	
	// Jasotako izenari hasieran "assets\\" gehitu,fitxategiaren benetako kokalekua lortzeko ("assets" karpetan)
	char file_path[99] = "assets\\";
	strcat(file_path, file_name);
	
	// Irakurri beharreko fitxategia ireki
	file = fopen(file_path, "r");
	
	// Karakterez karaktere iteratu .txt fitxategiaren edukien gainean
	// Azken karakterera (EOF) iristean, bukatu
    while ((c = getc(file)) != EOF)
    {
    	// Irakurritaku karaktere bakoitza inprimatu
        printf("%c", c);
	}
	// Espazioa utzi gero gehiago inprimatzeko
	printf("\n");
	
	// Irekitako fitxategia itxi
    fclose(file);
    return 0;
}

void press_any_key_to_continue(){
	
	/* Funtzio hau botoi bat sakatzea eskatzen du, irakurtzeko pausa balitz bezala.*/	
	
	printf("Edozein botoi sakatu jarraitzeko......");
	getchar();
	fflush(stdin);
	fflush(stdout);
	// Kontsola garbitzeko
	system("cls");
}

int choose_pokemon(string* pokemons){
	
    printf("pending");
    printf("%s", pokemons);
	return 0;

}


int main()
{
	// Aldagai globalen deklarazioa (Geroagoko kodearen funtzionamenduarentzat, array-en 0. posizioa ekidiko da)
	string pokemons[] = {"", "Bulbasur", "Squirtle", "Charmander", "Bidoof"};
	// Pokemon bakoitzaren mugimenduak --> zenbakia * 4
	// Adib, Charmander-en mugimenduak (3 pos): 3 * 4, 3* 4 + 1, 3 * 4 + 2 eta 3 * 4 + 3
	string moves[] = {"", ""};
	
	// Aurkezpena / Titulua
	print_from_txt("banner.txt");
	print_from_txt("test.txt");
	printf("\n\n");
	press_any_key_to_continue();
	
	// Pokemon-a aukeratu
	print_from_txt("oak.txt");
	printf("Kaixo, jokalari\n");
	printf("Ongi etorri Pokemonen mundura!\n");
	
	press_any_key_to_continue();
	print_from_txt("oak.txt");
	printf("Oak Irakaslea nauzu, opari bat dut zuretzat...\n");
	press_any_key_to_continue();

    choose_pokemon(pokemons);
	
	// Erabakiak
	
	
	// Borroka
	
	// Amaiera
}

#pragma clang diagnostic pop
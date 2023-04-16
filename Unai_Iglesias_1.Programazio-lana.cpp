#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


int print_from_txt(string file_name)
{
	/* .txt fitxategi baten izena pasatuz gero,
	   honen edukiak inprimatzen dituen funtzioa */
	
	// Jaso, txt fitxategiaren izena
	
	// Beharrezko aldagaiak deklaratu
	int c;
	FILE *file;
	
	// Jasotako izenari hasieran "assets\\" gehitu,fitxategiaren benetako kokalekua lortzeko ("assets" karpetan)
	string file_path = "assets\\";
	file_path = file_path + file_name;
	
	// Irakurri beharreko fitxategia ireki
	file = fopen(file_path.c_str(), "r");
	
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


void print_dialogue(string* text, int line_amount){

	
	/* Funtzio hau string bat jasotzen du eta "dialogo" moduan (karratuarekin) inprimatzen du,
		dialogoaren lerro kopurua pasa behar zaio ere
	
	 Hainbat lerroko dialogo bat sortzeko array batean pasa behar dira lerro bakoitza
	 OHARRA: array bat pasatzean errorerik ez jasotzeko, array-a pasa baino lehen deklaratu behar da*/
	
	printf("+                                                  +\n");
	
	int max_line_length = 48;
	
	// Dialogoaren lerro bakoitzeko
	for (int i = 0; i < line_amount; i++){
		printf("| ");
		
		printf("%s", text[i].c_str());
		
		
		int line_length = text[i].length();
		int spaces = max_line_length - line_length;
		
		for (int o = 0; o < spaces; o++){
			printf(" ");
		}
		
		printf(" |");
		
		printf("\n");
	}
	
	printf("+                                                  +\n");
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


int choose_pokemon(){
	
	/*Behin bakarrik dehituko den funtzioa, jokalariari pokemona aukeratzeko eskatzeko*/
	
    print_from_txt("Chimchar.txt");
    string initial_1_desc[] = {"Chimchar, suz-ko pokemona"};
    print_dialogue(initial_1_desc, 1);
    press_any_key_to_continue();
    
    print_from_txt("Squirtle.txt");
    string initial_2_desc[] = {"Squirtle, urez-ko pokemona"};
    print_dialogue(initial_2_desc, 1);
    press_any_key_to_continue();
    
    print_from_txt("Chikorita.txt");
    string initial_3_desc[] = {"Chikorita, landarez-ko pokemona"};
    print_dialogue(initial_3_desc, 1);
    press_any_key_to_continue();
    
    int user_input = 0;
    
    do
	{
    print_from_txt("oak.txt");
    string choose_a_pokemon[] = {"Esaidazu, zein pokemon nahi duzu?",
								"1 - Chimchar (Sua)",
								"2 - Squirtle (ura)",
								"3 - Chikorita (landarea)"};
	print_dialogue(choose_a_pokemon, 4);
	scanf("%d", &user_input);
	fflush(stdin);
	system("cls");
	} while ((user_input != 1) && (user_input != 2) && (user_input != 3));
    
	return user_input;
	
}


int main()
{	
	
	// Mugimenduen motak: Normala, Sua, Ura, Landarea, Izotza, Borroka, Pozoia, Lurra
	
	
	struct {
		// Pokemon bakoitzak horrelako estruktura bat izango du
		string name;
		string type;
		string moves[4];
		string move_types[4];
		int attack;
		int defense;
		int max_HP; // Bizitza puntu maximoak
		int HP; // Aldiuneko bizitza puntuak
	} player_pokemon, wild_pokemon, gym_pokemon, rival_pokemon;
	/* Jokoak 3 pokemonen kontra borrokatzeko aukera emango du:
	 Pokemon basatia, gimnasio buruaren pokemona eta gure aurkariaren pokemona */
	
	// Haien kontra burrokatuko dugun pokemonen definizioa
	
	/* Oharra: pokemonen mugimenduak (erasoak) definitzean banaka egin behar da*/
	
	// Pokemon basatia
	
	wild_pokemon.name = "Mudkip";
	wild_pokemon.type = "Ura";
	wild_pokemon.moves[1] = "Harramazkada";
	wild_pokemon.moves[2] = "Ur pistola";
	wild_pokemon.moves[3] = "Lurrikara";
	wild_pokemon.move_types[1] = "Normala";
	wild_pokemon.move_types[2] = "Ura";
	wild_pokemon.move_types[3] = "Lurra";
	wild_pokemon.attack = 1; // aldi baterakoa
	wild_pokemon.defense = 1; // aldi baterakoa
	wild_pokemon.max_HP = 1; // aldi baterakoa
	wild_pokemon.HP = wild_pokemon.max_HP;
	
	// Gimnasio buruaren pokemonaren definizioa
	
	gym_pokemon.name = "Sunflora";
	gym_pokemon.type = "Landarea";
	gym_pokemon.moves[1] = "Plakaketa";
	gym_pokemon.moves[2] = "Eguzki izpia";
	gym_pokemon.moves[3] = "Lokatz uhina";
	gym_pokemon.move_types[1] = "Normala";
	gym_pokemon.move_types[2] = "Landarea";
	gym_pokemon.move_types[3] = "Pozoia";
	gym_pokemon.attack = 1; // aldi baterakoa
	gym_pokemon.defense = 1; // aldi baterakoa
	gym_pokemon.max_HP = 1; // aldi baterakoa
	gym_pokemon.HP = gym_pokemon.max_HP;
	
	// Aurkariaren pokemonaren definizioa
	
	rival_pokemon.name = "Virizion";
	rival_pokemon.type = "Landarea";
	rival_pokemon.moves[1] = "Ezpata sakratua";
	rival_pokemon.moves[2] = "Harramazkada";
	rival_pokemon.moves[3] = "Hostotza";
	rival_pokemon.move_types[1] = "Borroka";
	rival_pokemon.move_types[2] = "Normala";
	rival_pokemon.move_types[3] = "Landarea";
	rival_pokemon.attack = 1; // aldi baterakoa
	rival_pokemon.defense = 1; // aldi baterakoa
	rival_pokemon.max_HP = 1; // aldi baterakoa
	rival_pokemon.HP = rival_pokemon.max_HP;
	
	//
	// Titulua
	//
	
	print_from_txt("banner.txt");
	print_from_txt("test.txt");
	
	string leihoa_maximizatu[] = {"Leihoa maximizatzea gomendatzen da"};
	print_dialogue(leihoa_maximizatu, 1);
	/*
	printf("+                                                  +\n");
	printf("| Leihoa maximizatzea gomendatzen da               |\n");
	printf("+                                                  +\n");
	*/
	press_any_key_to_continue();
	
	//
	// Hasiera / Aurkezpena
	//
	
	print_from_txt("oak.txt");
	string ongi_etorria[] = {"Kaixo, jokalari", "Ongi etorri Pokemon mundura!"};
	print_dialogue(ongi_etorria, 2);
	/*
	printf("+                                                  +\n");
	printf("| Kaixo, jokalari                                  |\n");
	printf("| Ongi etorri Pokemon mundura!                     |\n");
	printf("+                                                  +\n");
	*/
	press_any_key_to_continue();
	
	print_from_txt("oak.txt");
	string mezua[] = {"Oak Irakaslea nauzu, opari bat dut zuretzat..."};
	print_dialogue(mezua, 1);
	/*
	printf("+                                                  +\n");
	printf("| Oak Irakaslea nauzu, opari bat dut zuretzat...   |\n");
	printf("+                                                  +\n");
	*/
	press_any_key_to_continue();

	
	print_from_txt("oak.txt");
	string oparia_mezua[] = {"Pokemon bat oparituko dizut!", 
							 "Baina, horretarako, hauetako bat", 
							 "aukeratu behar duzu:"};
	print_dialogue(oparia_mezua, 3);
	/*
	printf("+                                                  +\n");
	printf("| Pokemon bat oparituko dizut!					   |\n");
	printf("| Baina, horretarako, hauetako bat				   |\n");
	printf("| aukeratu behar duzu: 							   |\n");
	printf("+                                                  +\n");
	*/
	press_any_key_to_continue();
	
	//
	// Hasierako pokemonaren aukeraketa
	//
	
	int chosen_pokemon = choose_pokemon();
	
	// Chimchar
	if (chosen_pokemon == 1)
	{
		player_pokemon.name = "Chimchar";
		player_pokemon.type = "Sua";
		player_pokemon.moves[1] = "Harramazkada";
		player_pokemon.moves[2] = "Su-jaurtigailua";
		player_pokemon.moves[3] = "Borroka estua";
		player_pokemon.move_types[1] = "Normala";
		player_pokemon.move_types[2] = "Sua";
		player_pokemon.move_types[3] = "Borroka";
		player_pokemon.attack = 1; // aldi baterakoa
		player_pokemon.defense = 1; // aldi baterakoa
		player_pokemon.max_HP = 1; // aldi baterakoa
		player_pokemon.HP = player_pokemon.max_HP;
	}
	// Squirtle
	else if (chosen_pokemon == 2)
	{
		player_pokemon.name = "Squirtle";
		player_pokemon.type = "Ura";
		player_pokemon.moves[1] = "Harramzkada";
		player_pokemon.moves[2] = "Ur pultusa";
		player_pokemon.moves[3] = "Izotz izpia";
		player_pokemon.move_types[1] = "Normala";
		player_pokemon.move_types[2] = "Ura";
		player_pokemon.move_types[3] = "Izotza";
		player_pokemon.attack = 1; // aldi baterakoa
		player_pokemon.defense = 1; // aldi baterakoa
		player_pokemon.max_HP = 1; // aldi baterakoa
		player_pokemon.HP = player_pokemon.max_HP;
	}
	// Chikorita
	else if (chosen_pokemon == 3)
	{
		player_pokemon.name = "Chikorita";
		player_pokemon.type = "Landarea";
		player_pokemon.moves[1] = "Harramazkada";
		player_pokemon.moves[2] = "Hosto zorrotza";
		player_pokemon.moves[3] = "Lokatz bonba";
		player_pokemon.move_types[1] = "Normala";
		player_pokemon.move_types[2] = "Landarea";
		player_pokemon.move_types[3] = "Pozoia";
		player_pokemon.attack = 1; // aldi baterakoa
		player_pokemon.defense = 1; // aldi baterakoa
		player_pokemon.max_HP = 1; // aldi baterakoa
		player_pokemon.HP = player_pokemon.max_HP;
	}
	
	print_from_txt(player_pokemon.name + ".txt");
	string pokemona_aukeratu_duzu[] = {player_pokemon.name + " aukeratu duzu!"};
	print_dialogue(pokemona_aukeratu_duzu, 1);

	// 
	// Istorioa / Erabakiak
	//
	
	/*
	Kodearen zati honetan, jokalariaren erabakien bitartez, zein pokemonaren
	 kontra borrokatuko den erabakiko da.
	*/
	
	// Borroka


	// Amaiera
}

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct pokemon{
	// Pokemon bakoitzak horrelako estruktura bat izango du
	string name;
	string master; // pokemonaren jabearen izena
	string type;
	string moves[4];
	string move_types[4];
	int attack;
	int defense;
	int max_HP; // Bizitza puntu maximoak
};

int print_from_txt(string file_name)
{
	/* .txt fitxategi baten izena pasatuz gero,
	   honen edukiak inprimatzen dituen funtzioa.
	   
	   [Oharra: .txt fitxategia /assets karpetan gordeta egon behar da]
	   
	   printt_from_txt("fitxategiaren_izena.txt")
	*/
	
	

	
	// Beharrezko aldagaiak deklaratu
	int c;
	FILE *file;
	
	// Jasotako izenari hasieran "assets\\" gehitu, fitxategiaren benetako kokalekua lortzeko ("assets" karpetan)
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


void print_dialogue(string* text, int line_amount, string talker = "Narratzailea"){

	/* 
		Funtzio hau string bat jasotzen du eta "dialogo" moduan (markoarekin) inprimatzen du,
		dialogoaren lerro kopurua ere pasa behar zaio.
		
		Aukerako aldagaia: hizlaria
	
	 	Hainbat lerroko dialogo bat sortzeko array batean pasa behar dira lerro bakoitza
	 	OHARRA: array bat pasatzean errorerik ez jasotzeko, array-a pasa baino lehen deklaratu behar da
	 	
	 	string mezua[] = {"Mezuaren", "Lerro", "bakoitza"};
	 	print_dialogue(mezua, 3); (mezua, mezuaren_lerro-kopurua)
	*/
	
	/*
		ADIBIDEA
		printf("+                                                  +\n");
		printf("| Kaixo, jokalari                                  |\n");
		printf("| Ongi etorri Pokemon mundura!                     |\n");
		printf("| Nola duzu izena?                                 |\n");
		printf("+                                                  +\n");
	*/

	// Zein pertsonai hitz egiten ari den adierazi (Narratzailea ez bada)
	if (talker != "Narratzailea"){
		printf("--[ %s ]--\n", talker.c_str());	
	}
	
	// Markoaren hasierako zatia
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
	
	/* Funtzio hau eneter-a sakatzea eskatzen du, irakurtzeko pausa balitz bezala.*/	
	
	printf("Enter sakatu jarraitzeko......");
	getchar(); // scanf balitz bezala baino motzagoa
	fflush(stdin);
	fflush(stdout);
	// Kontsola garbitzeko
	system("cls");
}


int choose_pokemon(){
	
	/*Behin bakarrik dehituko den funtzioa, jokalariari pokemona aukeratzeko eskatzeko*/
	
	
	// 3 pokemonak aurkeztu
	
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
    
    // Zer pokemon nahi den galdetu
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
    
    // Aukera itzuli
	return user_input;
	
}

int get_rival(int menu_code){
	
	while ((menu_code != 0) && (menu_code != 1) && (menu_code != 2) && (menu_code != 3))
	{
		string barkatu_hau_demo_bat_baino_ez_da[] =  {"Joko hau \"demo\" bat baino ez da.",
												  	"Beraz, istorio baten ordez menu bat",
													"erabiltzen da borrokan sartzeko"}; // '\' karakterea " inprimatzeko erabiltzen da
		print_dialogue(barkatu_hau_demo_bat_baino_ez_da, 3);
		
		printf(" 0 - Jokotik irten \n");
		printf(" 1 - Pokemon basatia (Erraza) \n");
		printf(" 2 - Gimnasio lider-a (Normala) \n");
		printf(" 3 - Lagun / Lehiakidea (Zaila) \n");
		
		scanf("%d", &menu_code);
	}
	
	return menu_code;
}


int get_amount_of_digits(int number){
	
	/*
	Zenbaki oso bat jasotzen du eta honen karaktere kopurua itzultzen du
	Adib: get..(543) --> return 3; get..(12) --> return 2
	Oharra: 4 digitorainoko zenbakiekin bakarri funtzionatzen du 
	*/
	
	if (number < 10)
	{
		return 1;
	} else if (number < 100)
	{
		return 2;
	}else if (number < 1000)
	{
		return 3;
	}else if (number < 10000)
	{
		return 4;
	}
}


void print_hp_bars(struct pokemon player_pokemon, struct pokemon enemy_pokemon, float player_HP, float enemy_HP){
	
	/*
		Bi pokemonen bizitza barrak inprimatzen dituen funtzioa
		
		Adib:
		+--------------------------------------------------+
		|pokemon: ########## (80 / 80) (landarea)		   |
		|pokemon: ########** (64 / 80) (Sua)			   |
		+--------------------------------------------------+
	*/
	
	printf("+--------------------------------------------------+\n");
	
	int needed_spaces = 50; // Bukaerako | non jarri kalkulatzeko ( "-" kopurua)
	int player_needed_chars = 0; // Bukaerako | non jarri kalkulatzeko
	/*
	Azalpena funtzioan zehar karaktere bat imprimatzen den bakoitzean aldagai honi 1 gehituko diogu
	Adib: printf("Pokemon: ###**") --> player_needed_chars + 14
	*/
	
	int player_max_hp = player_pokemon.max_HP;
	
	// HP-ak negatiboak badira...
	
	if (player_HP < 0){
		player_HP = 0;
	}
	if (enemy_HP < 0){
		enemy_HP = 0;
	}
	
	// 0-10 tartekoa, behar diren # kopurua (Gutxi gora behera, markadore hau ez da guztiz zehatza izango)
	int player_HP_percentage = (player_HP / player_max_hp) * 10;
	
	printf("|");
	
	// Imprimatu pokemonaren izena
	printf("%s : ", player_pokemon.name.c_str());
	player_needed_chars = player_needed_chars + 3 + player_pokemon.name.length();
	
	
	for (int i = 0; i < player_HP_percentage; i++)
	{
		printf("#");
		player_needed_chars++;
	}
	
	for (int i = 0; i < (10 - player_HP_percentage); i++)
	{
		printf("*");
		player_needed_chars++;
	}
	
	printf(" ( %.0f / %d ) (%s)", player_HP, player_max_hp, player_pokemon.type.c_str());
	player_needed_chars = player_needed_chars + 8 + get_amount_of_digits(player_HP) + get_amount_of_digits(player_max_hp) + player_pokemon.type.length() + 3;
	
	for (int i = 0; i < (needed_spaces - player_needed_chars); i++)
	{
		printf(" ");
	}
	printf("|");
	
	printf("\n");
	
	// GOIKO ZATIAREN BERDINA EGINGO DUGU AURKAKO POKEMONAREN BIDA BARRA IMPRIMATZEKO (Komentariorik gabe)
	
	int enemy_needed_chars = 0;
	
	int enemy_max_hp = enemy_pokemon.max_HP;
	
	int enemy_HP_percentage = (enemy_HP / enemy_max_hp) * 10;
	
	printf("|");
	
	printf("%s : ", enemy_pokemon.name.c_str());
	enemy_needed_chars = enemy_needed_chars + 3 + enemy_pokemon.name.length();
	
	
	for (int i = 0; i < enemy_HP_percentage; i++)
	{
		printf("#");
		enemy_needed_chars++;
	}
	
	for (int i = 0; i < (10 - enemy_HP_percentage); i++)
	{
		printf("*");
		enemy_needed_chars++;
	}
	
	printf(" ( %.0f / %d ) (%s)", enemy_HP, enemy_max_hp, enemy_pokemon.type.c_str());
	enemy_needed_chars = enemy_needed_chars + 8 + get_amount_of_digits(enemy_HP) + get_amount_of_digits(enemy_max_hp) + enemy_pokemon.type.length() + 3;
	
	for (int i = 0; i < (needed_spaces - enemy_needed_chars); i++)
	{
		printf(" ");
	}
	printf("|");
	
	printf("\n");
	
	
	printf("+--------------------------------------------------+\n");
	
}


float get_type_multiplier(string attacker, string attacked){
	
	/* 
		Funtzio hau erasoaren min biderkatzailea itzuliko du (motaren araberako, ikusi pokemonaren moten taula)
		0 --> Eraginik ez
		0.5 --> Ez oso eraginkorra
		1 --> Normala, ezer berezirik
		2 --> Oso eraginkorra
	*/
	
	// Mugimenduen motak: Normala, Sua, Ura, Landarea, Izotza, Borroka, Pozoia, Lurra
	
	if (attacked == "Normala")
	{
		if (attacker == "Borroka"){
			return 2;
		}else {
			return 1;
		}
		
		
	}else if (attacked == "Sua"){
		
		if ((attacker == "Ura") || (attacker == "Lurra")){
			return 2;
		}else if ((attacker == "Sua") || (attacker == "Izotza") || (attacker == "Landarea")){
			return 0.5;
		}else {
			return 1;
		}
		
		
	}else if (attacked == "Landarea"){
		
		if ((attacker == "Sua") || (attacker == "Izotza") || (attacker == "Pozoia")){
			return 2;
		} else if ((attacker == "Ura") || (attacker == "Landarea") || (attacker == "Lurra")){
			return 0.5;
		} else {
			return 1;
		}
		
		
	}else if (attacked == "Ura"){
		
		if (attacker == "Landarea"){
			return 2;
		} else if ((attacker == "Ura") || (attacker == "Sua") || (attacker == "Izotza")){
			return 0.5;
		} else {
			return 1;
		}
		
		
	}else if (attacked == "Izotza"){
		
		if ((attacker == "Sua") || (attacker == "Borroka")){
			return 2;
		} else if (attacker == "Izotza"){
			return 0.5;
		} else {
			return 1;
		}
		
		
	}else if (attacked == "Borroka"){
		
		// Joko honetan ez da x2 edo x0.5 egiten dion motarik (Hegalaria eta Gaiztoa ez daude programatuta, zerbait jartzeko da)
		if (attacker == "Hegalaria"){
			return 2;
		} else if (attacker == "Gaiztoa"){
			return 0.5;
		} else {
			return 1;
		}
		
		
	}else if (attacked == "Pozoia"){
		
		if (attacker == "Lurra"){
			return 2;
		} else if ((attacker == "Borroka") || (attacker == "Landarea") || (attacker == "Pozoia")){
			return 0.5;
		} else {
			return 1;
		}
		
		
	}else if (attacked == "Lurra"){
		
		if ((attacker == "Ura") || (attacker == "Izotza") || (attacker == "Landarea")){
			return 2;
		} else if (attacker == "Pozoia"){
			return 0.5;
		} else {
			return 1;
		}
		
	}
}


float calculate_damage(int attacker_pokemon_damage, int attacked_pokemon_defense, float type_multiplier){
	/*
		Pasatako pokemon batek beste bati eraso egitean egiten dion mina kalkulatzeko funtzioa
		
		fnc(erasotzailearen atakea (estatistika), erasotzailearen atakearen mota,
			erasotako pokemonaren defentsa (estatistika), erasotako pokemonaren mota)
	*/
	
	// Mina-ren formula
	float total_damage = (attacker_pokemon_damage - attacked_pokemon_defense) * type_multiplier;
	
	return total_damage;
}


int get_random_number(){
	
	// 1 - 3 arteko zenbaki aleatorioa itzultzen du
	
	int random = 1+ (rand() % 3);
	return random;
}

string stringize(int i){
	
	// int i: Zenbaki oso bat string bihurtzen du
	
	stringstream s;
	s << i;
	return s.str();
}



int do_enemy_turn(struct pokemon player_pokemon, struct pokemon enemy_pokemon, int player_HP, int enemy_HP){
	
	int erasoa = get_random_number(); // Aurkariaren pokemonak erabiliko duen atakearen zenbakia 
	float type_multiplier = get_type_multiplier(enemy_pokemon.move_types[erasoa], player_pokemon.type);
	
	// Aurkariaren erasoaren kalkulua	
	int damage_dealt_to_player = calculate_damage(enemy_pokemon.attack, player_pokemon.defense, type_multiplier);
	
	// Jokalariaren pokemonari erasoaren mina egin
	player_HP = player_HP - damage_dealt_to_player;
	
	// Egindakoa inprimatu (Motaren efektibotasunaren arabera mezu ezberdina)
	if (type_multiplier == 2){
		string happened[] = {enemy_pokemon.name + "-k " + enemy_pokemon.moves[erasoa] + " erabili du", "Oso eraginkorra da!", player_pokemon.name + "-k " + stringize(damage_dealt_to_player) + " HP galdu ditu"};
		print_dialogue(happened, 3);
	}else if (type_multiplier == 0.5){
		string happened[] = {enemy_pokemon.name + "-k " + enemy_pokemon.moves[erasoa] + " erabili du", "Ez da oso eraginkorra...", player_pokemon.name + "-k " + stringize(damage_dealt_to_player) + " HP galdu ditu"};
		print_dialogue(happened, 3);
	}else{ 
		string happened[] = {enemy_pokemon.name + "-k " + enemy_pokemon.moves[erasoa] + " erabili du", player_pokemon.name + "-k " + stringize(damage_dealt_to_player) + " HP galdu ditu"};
		print_dialogue(happened, 2);
	}
	
	
	return player_HP;
}


void pokemon_combat(struct pokemon player_pokemon, struct pokemon enemy_pokemon, string enemy_pokemon_sprite, string enemy_sprite = " "){
	
	system("cls");
	fflush(stdin);
	
	char turn = 'p'; // p = jokalaria ; e = aurkaria
	int player_HP = player_pokemon.max_HP; // Aldiuneko pokemonen bizitza puntuak
	int enemy_HP = enemy_pokemon.max_HP; //   Kalkuluak flaot-ekin egin arrren, zenbaki osoetara borobilduko dira
	int potion_amount = 2;
	
	
	if (enemy_sprite != " ") // Aurkaria eta gimnasio liderrarentzat
	{
		// Pertsonaiaren aurkezpena
		print_from_txt(enemy_sprite);
		string enemy_introduction[] = {enemy_pokemon.master, "Borroka batera desafiatu zaitu"};
		print_dialogue(enemy_introduction, 2, enemy_pokemon.master);
		
		press_any_key_to_continue();
		
		// Pertsonaiaren pokemonaren aurkezpena
		
		print_from_txt(enemy_pokemon_sprite);
		string enemy_pokemon_introduction[] = {enemy_pokemon.master + "-ek bere " + enemy_pokemon.name + " atera du"};
		print_dialogue(enemy_pokemon_introduction, 1);
		
		press_any_key_to_continue();
		system("cls");
		
	} else // pokemon basatia
	{
		print_from_txt(enemy_pokemon_sprite);
		string enemy_introduction[] = {enemy_pokemon.name + " basati bat agertu da!"};
		print_dialogue(enemy_introduction, 1);
		
		press_any_key_to_continue();
		system("cls");
		
	}
	
	// Borrokaren bukle nagusia
	
	while ((player_HP > 0) && (enemy_HP > 0))
	{
		print_hp_bars(player_pokemon, enemy_pokemon, player_HP, enemy_HP);	
		
		if (turn == 'e') // Makinaren txanda bada, egin eta hurrengo txandara pasa
		{
			player_HP = do_enemy_turn(player_pokemon, enemy_pokemon, player_HP, enemy_HP);
			print_hp_bars(player_pokemon, enemy_pokemon, player_HP, enemy_HP);
			press_any_key_to_continue();
			turn = 'p';
			continue; // Hurrengo iteraziora pasa (Jarraitu hurrengo while-aren "bueltarekin")
		}
	
		// Jokalariaren txanda
	
		int player_choice = -1; // Balio lehenetsia

	
		do {

			string zure_txanda[] = {"Jokalariaren txanda:"};
			print_dialogue(zure_txanda, 1);

			printf(" 0 - Amore eman\n");
			
			for(int i = 1; i <= 3; i++){
				printf(" %d - %s (%s)\n", i, player_pokemon.moves[i].c_str(), player_pokemon.move_types[i].c_str());
			}
			printf(" 4 - Edabe bat erabili (20 HP sendatu) (%d geratzen zaizkizu)\n", potion_amount);
			
			printf("\n");
			
			printf(" Zer egin behar du %s-ek ? ", player_pokemon.name.c_str());
			
			scanf(" %d", &player_choice);
			fflush(stdin);
			system("cls");
			
		} while ((player_choice != 0) && (player_choice != 1) && (player_choice != 2) && (player_choice != 3) && (player_choice != 4));

		print_hp_bars(player_pokemon, enemy_pokemon, player_HP, enemy_HP);

		if (player_choice == 0){ // Borroka galdu
			player_HP = 0;
			break;
		}
		
		else if (player_choice == 4){ // Edabe (pocion) bat erabili
		
			if (potion_amount == 0){
				// Edaberik ez, esan eta ez egin ezer (Jokalariaren txanda errepikatu)
				printf("Ez duzu edaberik...\n");
				press_any_key_to_continue();
				continue;
			}
		
			// Edabeak geratzen dira
		
			potion_amount = potion_amount - 1;
			player_HP = player_HP + 20;
			
			// Edabeak HP maximoa baino gehiago sendatzen ez duela ziurtatzeko
			if (player_HP > player_pokemon.max_HP){
				player_HP = player_pokemon.max_HP;
			}
			
			string sendatu_da[] = {" " + player_pokemon.name + "-ek 20 HP berreskuratu ditu!"};
			print_dialogue(sendatu_da, 1);
			print_hp_bars(player_pokemon, enemy_pokemon, player_HP, enemy_HP);
			press_any_key_to_continue();
		}
		
		else{ // Erasotu (Zati hau makinaren txandaren funtzioa "do_enemy_turn()" bezalakoa da)
		
			int erasoa = player_choice;
			float type_multiplier = get_type_multiplier(player_pokemon.move_types[erasoa], enemy_pokemon.type);
			
			int damage_dealt_to_enemy = calculate_damage(player_pokemon.attack, enemy_pokemon.defense, type_multiplier);
			
			// Mina egin
			enemy_HP = enemy_HP - damage_dealt_to_enemy;
			
			// Egindakoa inprimatu (Motaren efektibotasunaren arabera mezu ezberdina)
			if (type_multiplier == 2){
				string done[] = {player_pokemon.name + "-k " + player_pokemon.moves[erasoa] + " erabili du", "Oso eraginkorra da!", enemy_pokemon.name + "-k " + stringize(damage_dealt_to_enemy) + " HP galdu ditu"};
				print_dialogue(done, 3);
			}else if (type_multiplier == 0.5){
				string done[] = {player_pokemon.name + "-k " + player_pokemon.moves[erasoa] + " erabili du", "Ez da oso eraginkorra...", enemy_pokemon.name + "-k " + stringize(damage_dealt_to_enemy) + " HP galdu ditu"};
				print_dialogue(done, 3);
			}else{ 
				string done[] = {player_pokemon.name + "-k " + player_pokemon.moves[erasoa] + " erabili du", enemy_pokemon.name + "-k " + stringize(damage_dealt_to_enemy) + " HP galdu ditu"};
				print_dialogue(done, 2);
			}
			
			print_hp_bars(player_pokemon, enemy_pokemon, player_HP, enemy_HP);
			press_any_key_to_continue();
			
		}
		
		// Txanda makinari pasa
		turn = 'e';
	}
	// Programa hona iristen bada, borroka bukatu da
	
	if (enemy_HP <= 0){ // Jokalariak irabazi du
	
		string irabazi_duzu[] = {"YOU WIN!, Konbatea irabazi duzu!", "Probatu orain aurkari zailago batekin..."};
		print_dialogue(irabazi_duzu, 2);
		press_any_key_to_continue();
		
	}else { // Makinak irabazi du
		string galdu_duzu[] = {"GAME OVER, Konbatea galdu duzu...", "Hobetu zure estrategia hurrengorako!"};
		print_dialogue(galdu_duzu, 2);
		press_any_key_to_continue();
	}
	
	
}


int main()
{	
	
	// Mugimenduen motak: Normala, Sua, Ura, Landarea, Izotza, Borroka, Pozoia, Lurra
	
	struct pokemon player_pokemon, wild_pokemon, gym_pokemon, rival_pokemon;
	string dialogue[9]; // Aldagai hau print_dialogue() funtzioa deitzerakoan argumentuak pasatzeko erabiliko da
	
	/*
	 Jokoak 3 pokemonen kontra borrokatzeko aukera emango du:
	 Pokemon basatia, gimnasio buruaren pokemona eta gure (istoriako, ez badago progrmatuta ere) aurkariaren  pokemona 
	 */
	
	// Haien kontra burrokatuko dugun pokemonen definizioa
	
	/* Oharra: pokemonen mugimenduak (erasoak) definitzean banaka egin behar da*/
	
	// Pokemon basatia (Zailtasuna : Erraza)
	
	wild_pokemon.name = "Mudkip";
	wild_pokemon.type = "Ura";
	wild_pokemon.moves[1] = "Harramazkada";
	wild_pokemon.moves[2] = "Ur pistola";
	wild_pokemon.moves[3] = "Lurrikara";
	wild_pokemon.move_types[1] = "Normala";
	wild_pokemon.move_types[2] = "Ura";
	wild_pokemon.move_types[3] = "Lurra";
	wild_pokemon.attack = 20; // aldi baterakoa
	wild_pokemon.defense = 8; // aldi baterakoa
	wild_pokemon.max_HP = 70; // aldi baterakoa
	
	// Gimnasio buruaren pokemonaren definizioa (Zailtasuna : Normala)
	
	gym_pokemon.name = "Sunflora";
	gym_pokemon.type = "Landarea";
	gym_pokemon.master = "Brais";
	gym_pokemon.moves[1] = "Plakaketa";
	gym_pokemon.moves[2] = "Eguzki izpia";
	gym_pokemon.moves[3] = "Lokatz uhina";
	gym_pokemon.move_types[1] = "Normala";
	gym_pokemon.move_types[2] = "Landarea";
	gym_pokemon.move_types[3] = "Pozoia";
	gym_pokemon.attack = 20; // aldi baterakoa
	gym_pokemon.defense = 12; // aldi baterakoa
	gym_pokemon.max_HP = 80; // aldi baterakoa
	
	// Aurkariaren pokemonaren definizioa (Zailtasuna : Zaila)
	
	rival_pokemon.name = "Virizion";
	rival_pokemon.type = "Landarea";
	rival_pokemon.master = "Israel";
	rival_pokemon.moves[1] = "Ezpata sakratua";
	rival_pokemon.moves[2] = "Harramazkada";
	rival_pokemon.moves[3] = "Hostotza";
	rival_pokemon.move_types[1] = "Borroka";
	rival_pokemon.move_types[2] = "Normala";
	rival_pokemon.move_types[3] = "Landarea";
	rival_pokemon.attack = 30; // aldi baterakoa
	rival_pokemon.defense = 15; // aldi baterakoa
	rival_pokemon.max_HP = 100; // aldi baterakoa
	
	//
	// Titulua	
	//
	
	print_from_txt("header.txt");
	print_from_txt("credits.txt");
	
	dialogue[0] = "Leihoa maximizatzea gomendatzen da";
	print_dialogue(dialogue, 1);
	/*
	ADIBIDEA:
	printf("+                                                  +\n");
	printf("| Leihoa maximizatzea gomendatzen da               |\n");
	printf("+                                                  +\n");
	*/
	press_any_key_to_continue();
	
	//
	// Hasiera / Aurkezpena
	//
	
	print_from_txt("oak.txt");
	dialogue[0] = "Kaixo, jokalari";
	dialogue[1] = "Nola duzu izena?";
	print_dialogue(dialogue, 2, "?????????????");
	string player_name;
	cin >> player_name; // scanf-rekin eginez gero arazoak ematen ditu
	
	while (player_name.length() > 20){ // Jokalariaren izen agehienez 20 karakterekoa izan dadin

		system("cls"); // Kontsola garbitu
		print_from_txt("oak.txt");
		dialogue[0] = "Ez dut uste zure izena horren luzea denik...";
		dialogue[1] = "Izen motzago bat aukeratu:";
		print_dialogue(dialogue, 2, "?????????????");	
		cin >> player_name; // scanf-rekin eginez gero arazoak ematen ditu
	} 

	press_any_key_to_continue();
	
	print_from_txt("oak.txt");
	dialogue[0] = "Kaixo " + player_name +". Oak irakaslea naiz";
	dialogue[1] = "Ongi etorri pokemon mundura!";
	print_dialogue(dialogue, 2, "Oak irakaslea");
	/*
	printf("+                                                  +\n");
	printf("| Oak Irakaslea nauzu, opari bat dut zuretzat...   |\n");
	printf("+                                                  +\n");
	*/
	press_any_key_to_continue();

	
	print_from_txt("oak.txt");
	dialogue[0] = "Pokemon bat oparituko dizut!";
	dialogue[1] = "Baina, horretarako, hauetako bat";
	dialogue[2] = "aukeratu behar duzu:";
	print_dialogue(dialogue, 3, "Oak irakaslea");
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
		player_pokemon.attack = 45; // aldi baterakoa
		player_pokemon.defense = 8; // aldi baterakoa
		player_pokemon.max_HP = 50; // aldi baterakoa
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
		player_pokemon.attack = 35; // aldi baterakoa
		player_pokemon.defense = 12; // aldi baterakoa
		player_pokemon.max_HP = 60; // aldi baterakoa
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
		player_pokemon.attack = 20; // aldi baterakoa
		player_pokemon.defense = 18; // aldi baterakoa
		player_pokemon.max_HP = 80; // aldi baterakoa
	}
	
	print_from_txt(player_pokemon.name + ".txt");
	dialogue[0] = player_pokemon.name + " aukeratu duzu!";
	print_dialogue(dialogue, 1, "Oak irakaslea");
	press_any_key_to_continue();

	print_from_txt("oak.txt");
	dialogue[0] = "Ederki!";
	dialogue[1] = "Orain, zoaz zure lagun berriarekin abenturara!";
	print_dialogue(dialogue, 2, "Oak irakaslea");
	press_any_key_to_continue();

	// 
	// Aurkaria aukeratzeko menua --> Borroka
	//
	
	/*
	OHARRA: Joko hau demo bat baino ez denez, ez da istoriorik kontatuko. 
			Hemen, noren kontra borrokatzeko aukeratzeko menu bat agertuko da.
	*/
	
			int menu_code = -1;
		/*
		Aldagai honen arabera erabakiko da zer egin:
			- "1", "2", "3" :  Borrokatu (aurkarien aukerak)
			- "0" : Jokoa bukatu, programa itxi
			- "-1" : Balio lehenetsia, galdetu behar
		*/
	
	do { // menuaren bukle nagusia
	
		menu_code = get_rival(menu_code);
		
		if (menu_code == 0) // ateratzeko kodea bada, zuzenean irten
		{
			printf("\nIrteten....");
			exit(0);
		}
		
		switch (menu_code)
		{
			case 0: printf("\nIrteten....");
					exit(0);
			case 1: pokemon_combat(player_pokemon, wild_pokemon, "wild.txt");
				// Wild pokemon
					break;
			case 2: pokemon_combat(player_pokemon, gym_pokemon, "sunflora.txt", "gym_leader.txt");
				// Gym leader pokemon
					break;
			case 3: pokemon_combat(player_pokemon, rival_pokemon,"virizon.txt", "rival.txt");
				// Rival pokemon
					break;
			
			default: printf("ERROR: Invalid menu_code --> %d", menu_code);
		}
		
		
		menu_code = -1; // Aldagaia reseteatu hurrengo iteraziorako
	} while(menu_code != 0);
}

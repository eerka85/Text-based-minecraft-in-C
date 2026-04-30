//POMOC POMOC POMOC POMOC - verze 8.0(snad boss) verze 7.0 (healy, dice art(1)) verze 6.0 (bug fixes, vic v inv, crafting recepies, easy loadovani saveu) verze 5.0 (vic v inv, crafting recepies, easy loadovani saveu) verze 4.1(==SAVEOVANI==, UTF - 8 text vsude - ta setconsoleoutput fce v main, 2x kosticek,SHEEP ART, SKELL ART and ZOMBIE ART) 3.0 (clear screen + menu boss) + 2.0(plains + encounter + counterattack) 1.0(+ crafting armor/weapons + barvy + input int/string + inventory)
//NAPADY - hp doplnovani - jidlo system - nezapomen ukladat, heal
//       - dum? - zahrada, crafting table, furnace, animal farmu [village? - stardew valley npccka? item trade?]
//       - 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"
#define BLUE    "\x1b[34m"
#define GRAY	"\x1b[90m"
#define PURPLE  "\033[35m"


//zom//
#define BLACK   "\033[30m"
#define FOREST_GREEN    "\033[38;5;22m"     // A deep, dark green
#define LIME_GREEN      "\033[38;5;118m"    // A very bright, vivid green


//skel//
// The deep dark voids for the eyes and mouth 
#define SKEL_EYE_DARK    "\033[38;2;76;76;76m"   // Dark charcoal

// The shading/texture colors
#define SKEL_SHADOW      "\033[38;2;145;145;145m" // Deep shadow gray
#define SKEL_MEDIUM      "\033[38;2;172;172;172m" // Mid-tone gray

// The main "bone" colors
#define SKEL_BONE        "\033[38;2;193;193;193m" // Standard bone gray
#define SKEL_HIGHLIGHT   "\033[38;2;215;215;215m" // Lightest highlights


//sheep//
#define WHITE    "\033[38;2;255;255;255m" // Pure white highlights
#define SHEEP_WOOL_SHADOW   "\033[38;2;230;230;230m" // Light grey wool texture
//#define SHEEP_WOOL_DARK     "\033[38;2;213;213;213m" // Deep wool shadow - too lazy for ts rn

// Face/Skin Colors
#define SHEEP_SKIN          "\033[38;2;223;166;137m" // The main tan face color
//#define SHEEP_SKIN_SHADOW   "\033[38;2;184;133;106m" // Darker tan for the chin/edges - too lazy for ts rn

// Features
#define SHEEP_EYE_BLACK     "\033[38;2;0;0;0m"       // Pupil
#define SHEEP_NOSE_PINK     "\033[38;2;251;153;192m" // The pink nose/mouth area
#define SHEEP_NOSE_LIGHT    "\033[38;2;254;206;222m" // Highlight on the nose

//UNPUTY

void clean_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}
void input_string (char pole[], int velikost, char vypis []) {
	printf ("%s", vypis);

	if (fgets (pole, velikost, stdin) == NULL) {
		return;
	}
	int pozice = strcspn (pole, "\n");

	if (pole [pozice] == '\n') {
		pole[pozice] = '\0';
	}
	else {
		clean_buffer();
	}
}
int input_int(int min, int max) {
	int tmp = 0;
	while(1) {
		printf(YELLOW" CHOOSE: " RESET);
		int is_input_valid = scanf("%d", &tmp);
		clean_buffer();
		if(is_input_valid == 0 || tmp <min || tmp >max) {
			printf(BOLD YELLOW "##failed to load number##\n" RESET);
			continue;
		}
		else {
			return tmp;
		}
	}
}
void clear_screen() {
	printf(BLUE " \nCONTINUE? (press enter)" RESET);
	getchar();
	printf("\033[H\033[2J");
}
void del_screen(){
	printf(BLUE " \nCONTINUE? (press enter)" RESET);
	getchar();
	system("cls");
}
//ART
void print_zom(){
    int pole[8][8];
    for(int i = 0; i<8; i++){ //all dark zel
        for(int o = 0; o<8; o++){
            pole[i][o] = 1;
        }
    }
    pole[1][4] = 2;  //2. line
    pole[1][5] = 2;

    for(int i = 1; i<7; i++){// 3. line
        pole[2][i] = 2;
    }
    for(int i = 0; i<7; i++){// 4. line
        pole[3][i] = 2;
    }
    for(int i = 0; i<8; i++){// 5. line
        pole[4][i] = 2;
    }
    pole[4][1] = 3;
    pole[4][2] = 3;
    pole[4][5] = 3;
    pole[4][6] = 3;

    pole[5][1] = 2; //6. line
    pole[5][2] = 2;
    pole[5][5] = 2;
    pole[5][6] = 2;

    pole[6][1] = 2; //7. line
    pole[6][3] = 2;
    pole[6][4] = 2;
    pole[6][6] = 2;

    for(int i = 0; i<8; i++){ //print
        for(int o = 0; o<8; o++){
            if(pole[i][o] == 1){
                printf(FOREST_GREEN "\xE2\x96\x88" RESET);
				printf(FOREST_GREEN "\xE2\x96\x88" RESET);
            }
            else if(pole[i][o] == 2){
                printf(LIME_GREEN "\xE2\x96\x88" RESET);
				printf(LIME_GREEN "\xE2\x96\x88" RESET);
            }
            else{
                printf(BLACK "\xE2\x96\x88" RESET);
				printf(BLACK "\xE2\x96\x88" RESET);
            }
        }
        printf("\n");
    }

}
void print_skel(){
	int pole[8][8];
	for(int i = 0; i<8; i++){ //all dark gray
		for(int o = 0; o<8; o++){
			pole[i][o] = 2;
		}
	}
	for(int i = 0; i<8; i++){ //hair 1. line
		pole[0][i] = 1; 
	}
	for(int i = 0; i<8; i++){ //hair 2. line
		pole[1][i] = 1; 
	}
	pole[1][4] = 2; //celo 2. line
	pole[1][5] = 2;
	
	for(int i = 0; i<8; i++){ //bone 3. line
		pole[2][i] = 2; 
	}
	pole[2][0] = 1; //3. line hair

	for(int i = 0; i<8; i++){ //bone 4. line
		pole[3][i] = 2; 
	}

	for(int i = 0; i<8; i++){ //bone 5. line
		pole[4][i] = 2; 
	}
	pole[4][1] = 4; //eyes 5. line
	pole[4][2] = 4;
	pole[4][5] = 4;
	pole[4][6] = 4;

	for(int i = 0; i<8; i++){ //bone 6. line
		pole[5][i] = 2; 
	}
	pole[5][3] = 1; //nose 6. line
	pole[5][4] = 1;

	pole[6][0] = 1; //mid 7. line
	for(int i = 1; i<7; i++){ //mouth 7. line
		pole[6][i] = 4; 
	}
	pole[6][7] = 1; //shadow 7. line
	for(int i = 0; i<8; i++){ //shadow 8. line
		pole[7][i] = 5; 
	}

	for(int i = 0; i<8; i++){ //print
		for(int o = 0; o<8; o++){
			if(pole[i][o] == 1){
				printf(SKEL_MEDIUM "\xE2\x96\x88" RESET);
				printf(SKEL_MEDIUM "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 2){
				printf(SKEL_BONE "\xE2\x96\x88" RESET);
				printf(SKEL_BONE "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 3){
				printf(SKEL_HIGHLIGHT "\xE2\x96\x88" RESET);
				printf(SKEL_HIGHLIGHT "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 4){
				printf(SKEL_EYE_DARK "\xE2\x96\x88" RESET);
				printf(SKEL_EYE_DARK "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 5){
				printf(SKEL_SHADOW "\xE2\x96\x88" RESET);
				printf(SKEL_SHADOW "\xE2\x96\x88" RESET);
			}
			else{
				printf(GREEN "\xE2\x96\x88" RESET);
				printf(GREEN "\xE2\x96\x88" RESET);
			}
		}
		printf("\n");
	}
}

void print_sheep(){
	int pole[8][8];
	for(int i = 0; i<8; i++){ //all white wool
		for(int o = 0; o<8; o++){
			pole[i][o] = 5;
		}
	}
	for(int i = 1; i<7; i++){ //3. line
		pole[2][i] = 6;
	}
	pole[3][1] = 2; //4. line
	pole[3][2] = 1;
	pole[3][3] = 6;
	pole[3][4] = 6;
	pole[3][5] = 1;
	pole[3][6] = 2;
	for(int i = 1; i<7; i++){ //5. line
		pole[4][i] = 6;
	}
	pole[5][2] = 6; //6. line
	pole[5][3] = 4;
	pole[5][4] = 4;
	pole[5][5] = 6;

	pole[6][2] = 6; //7. line
	pole[6][3] = 3;
	pole[6][4] = 3;
	pole[6][5] = 6;


	for(int i = 0; i<8; i++){ //print
		for(int o = 0; o<8; o++){
			if(pole[i][o] == 1){
				printf(WHITE "\xE2\x96\x88" RESET);
				printf(WHITE "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 2){
				printf(SHEEP_EYE_BLACK "\xE2\x96\x88" RESET);
				printf(SHEEP_EYE_BLACK "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 3){
				printf(SHEEP_NOSE_LIGHT "\xE2\x96\x88" RESET);
				printf(SHEEP_NOSE_LIGHT "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 4){
				printf(SHEEP_NOSE_PINK "\xE2\x96\x88" RESET);
				printf(SHEEP_NOSE_PINK "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 5){
				printf(SHEEP_WOOL_SHADOW "\xE2\x96\x88" RESET);
				printf(SHEEP_WOOL_SHADOW "\xE2\x96\x88" RESET);
			}
			else if(pole[i][o] == 6){
				printf(SHEEP_SKIN "\xE2\x96\x88" RESET);
				printf(SHEEP_SKIN "\xE2\x96\x88" RESET);
			}
			else{
				printf(GREEN "\xE2\x96\x88" RESET);
				printf(GREEN "\xE2\x96\x88" RESET);
			}
		}
		printf("\n");
	}
}
// DICE
void dice(int k_1, int k_2){
	int d_1[7][7];
	for(int i = 0; i < 7; i++){
		for(int j = 0; j <7; j++){
			d_1[i][j] = 0;
		}
	}

	//tisk
	for(int i = 0; i < 7; i++){
		for(int j = 0; j <7; j++){
			if(d_1[i][j] = 1){
				printf(WHITE "\xE2\x96\x88" RESET);
				printf(WHITE "\xE2\x96\x88" RESET);
			}
		}
	}

}


//MENY

void menu() {
	clear_screen();
	printf(BOLD CYAN "\n=== ADVENTURE ===\n" RESET);
	printf(YELLOW " 1. CRAFT\n 2. MINE\n 3. FIGHT\n 4. INVENTORY\n 5. HEAL\n 0. LEAVE\n" RESET);
}

void menu_mine() {
	clear_screen();
	printf(BOLD CYAN "\n===MINING MENU===\n" RESET);
	printf(YELLOW " 1. MINING WOOD\n 2. MINING IRON\n 3. MINING DIAMONDS\n 0. BACK\n" RESET);
}
void menu_craft(int leather, int wool, int wood, int iron, int diamonds) {
	char H_color[10];
	char C_color[10];
	char L_color[10];
	char B_color[10];
	char S_color[10];
	char A_color[10];
	char BA_color[10];
	char P_color[10];

	clear_screen();
	printf(BOLD CYAN "\n=== CRAFTING MENU ===\n" RESET);
	//crafting requirements
	if(iron >= 5 || diamonds >= 5){
		printf(GREEN " 1. CRAFT HELMET\n" RESET);
	}
	else{
		printf(RED " 1. CRAFT HELMET\n" RESET);
	}
	if(iron >= 8 || diamonds >= 8){
		printf(GREEN " 2. CRAFT CHESTPLATE\n" RESET);
	}
	else{
		printf(RED " 2. CRAFT CHESTPLATE\n" RESET);
	}
	if(iron >= 6 || diamonds >= 6){
		printf(GREEN " 3. CRAFT LEGGINGS\n" RESET);
	}
	else{
		printf(RED " 3. CRAFT LEGGINGS\n" RESET);
	}
	if(iron >= 4 || diamonds >= 4){
		printf(GREEN " 4. CRAFT BOOTS\n" RESET);
	}
	else{
		printf(RED " 4. CRAFT BOOTS\n" RESET);
	}
	if((iron >= 2 || diamonds >= 2)&& wood >= 2){
		printf(GREEN " 5. CRAFT SWORD\n" RESET);
	}
	else{
		printf(RED " 5. CRAFT SWORD\n" RESET);
	}
	if((iron >= 3 || diamonds >= 3)&& wood >= 2){
		printf(GREEN " 6. CRAFT PICKAXE\n" RESET);
	}
	else{
		printf(RED " 6. CRAFT PICKAXE\n" RESET);
	}
	if((iron >= 3 || diamonds >= 3)&& wood >= 2){
		printf(GREEN " 7. CRAFT AXE\n" RESET);
	}
	else{
		printf(RED " 7. CRAFT AXE\n" RESET);
	}
	if(leather >= 5 || leather >= 5){
		printf(GREEN " 8. CRAFT BACKPACK\n" RESET);
	}
	else{
		printf(RED " 8. CRAFT BACKPACK\n" RESET);
	}
	printf(YELLOW " 0. BACK\n" RESET);

}
void menu_boss(){
	clear_screen();
	printf (BOLD CYAN "=== BOSS FIGHT MENU === \n" RESET);
	printf (YELLOW " 1. LEVEL - 1\n 2. LEVEL - 2\n 3. LEVEL - 3\n 4. LEVEL - 4\n 5. RANDOM LEVEL\n 0. BACK \n" RESET);
}
void boss_menu() {
    printf(BOLD CYAN "\n=== BOSS FIGHT MENU ===\n" RESET);
}
void colours (char crystal) {
    switch (crystal) {
        case 'R':
            printf(RED "Crystal is Red " RESET);
            break;
        case 'P':
            printf(PURPLE "Crystal is Purple " RESET);
            break;
        case 'B':
            printf(BLUE "Crystal is Blue " RESET);
            break;
    }
}
void menu_fighting() {
	clear_screen();
	printf(BOLD CYAN "\n=== FIGHTING MENU ===\n" RESET);
	printf(YELLOW " 1. BOSS FIGHT\n 2. EXPLORE (plains)\n 3. EXPLORE (caves)\n 0. BACK\n" RESET);
}
void menu_encounter(int chosen_mon, char mon_name[], int hp_mon, int MAX_hp_mon, int *player_hp_fighting) {
	clear_screen();
	switch (chosen_mon){
	case 1: //zombie
		print_zom();
	break;
	case 2: //skeleton
		print_skel();
	break;
	case 21: //sheep
		print_sheep();
		//printf("   __     __\n  /  \\~~~/  \\\n(    ..     )\n \\__-\\__/_/\n   \\_/  \\_/\n"); //to napsala vs :o
	break;
	}
	printf(GREEN "\nA wild %s has appeared! What will you do?\n"RESET, mon_name);
	printf(BOLD CYAN "\n=== ENCOUTER MENU ===\n" RESET);
	printf(RED " ENEMY HP = %d/%d\n" RESET, hp_mon, MAX_hp_mon);
	printf(GREEN " YOUR HP = %d/10\n" RESET, *player_hp_fighting);
	printf(YELLOW " 1.ATTACK\n 0.RUN\n" RESET);
}
//jidlo
int heal_player(int * player_hp_fighting){
	int volba_d = 0;
	int con_d_whil = 1;
	int villager_dice_roll = 0;
	int p_dice_roll = 0;
	printf(YELLOW "\n PLAY DICE WITH VILLAGER FOR FOOD?\n 1. YES\n 0. NO\n" RESET);
	volba_d = input_int(0, 1);
	switch(volba_d){
		case 0:
			return 0;
		break;
		case 1:
			while(con_d_whil){
				//vil roll - ((rand() %6)+1)
				villager_dice_roll = ((rand() %6)+1) + ((rand() %6)+1);
				printf(RED "\n The villager rolled %d," RESET, villager_dice_roll);

				printf(GREEN "\n Your turn, press ENTER to roll: ");
				getchar();
				p_dice_roll = ((rand() %6)+1) + ((rand() %6)+1);
				printf(RED "\n You rolled %d," RESET, p_dice_roll);
				if(p_dice_roll > villager_dice_roll){
					printf(GREEN "\n yay YOU WON yay\n Adding 3hp..." RESET);
					*player_hp_fighting = *player_hp_fighting +3;
					if(*player_hp_fighting > 10){
						*player_hp_fighting = 10;
					}
					con_d_whil = 0;
				}
				else if(villager_dice_roll == p_dice_roll){
					printf(WHITE "\n Draw...\n Adding 1 hp..."RESET);
					*player_hp_fighting = *player_hp_fighting +1;
					if(*player_hp_fighting > 10){
						*player_hp_fighting = 10;
					}
					printf(YELLOW "\n TRY AGAIN? (press ENTER)" RESET);
					getchar();
					clear_screen();
					continue;
				}
				else{
					printf(RED "\n xxx YOU LOST xxx" RESET);
					printf(YELLOW "\n TRY AGAIN? (press ENTER)" RESET);
					getchar();
					clear_screen();
					continue;
				}
			}
		break;
	}
	
}

//MINEY

int wood_mine (int chance_wood, int wood, int i_axe, int d_axe) {
	chance_wood = rand () % 100;
	if(i_axe == 1){
		chance_wood = chance_wood - 10;
	}
	else if(d_axe == 1){
		chance_wood = chance_wood - 20;
	}
	if (chance_wood <= 20) {
		wood += 3;
		printf(GREEN "Jackpot! You mined 3 logs!" RESET);
	}
	else if (chance_wood > 20 && chance_wood <= 50) {
		wood += 2;
		printf(GREEN "Congratulations! You mined 2 logs" RESET);
	}
	else if (chance_wood > 50 && chance_wood <= 100) {
		if (wood == 0) {
			wood += 2;
			printf(GREEN "Congratulations! You mined 2 logs" RESET);
		}
		else {
			wood += 1;
			printf(YELLOW "You got 1 log" RESET);
		}
	}
	return wood;
}

int iron_mine (int chance, int material, int i_pickaxe, int d_pickaxe) {
	chance = rand () % 100;
	if(i_pickaxe == 1){
		chance = chance - 10;
	}
	else if(d_pickaxe == 1){
		chance = chance - 20;
	}
	if (chance <= 20) {
		material += 2;
		printf(GREEN "Jackpot! You found 2 iron" RESET);
	}
	else if (chance > 20 && chance <= 50) {
		material += 1;
		printf(YELLOW "You got 1 iron" RESET);
	}
	else if (chance > 50 && chance <= 100) {
		material += 0;
		printf(RED "You got unlucky... 0 iron" RESET);
	}
	return material;
}

int diamond_mine (int chance, int material, int i_pickaxe, int d_pickaxe) {
	chance = rand () % 100;

	if(i_pickaxe == 1){
		chance = chance - 10;
	}
	else if(d_pickaxe == 1){
		chance = chance - 20;
	}

	if (chance <= 20) {
		material += 1;
		printf(GREEN "Jackpot! You found a diamond!" RESET);
	}
	else if (chance > 20 && chance <= 50) {
		material += 0;
		printf(YELLOW "No Diamonds, just some stone... you should try again :)" RESET);
	}
	else if (chance > 50 && chance <= 100) {
		material += 0;
		printf(RED "You got unlucky... you should give it one more shot!" RESET);
	}
	return material;
}
//COUNTERATTACK
int counterattack(int mon_attackdmg, int i_armor_count, int d_armor_count){
	int tmp = 0;
	tmp = rand() % 11;
	tmp = tmp - i_armor_count - d_armor_count*2;
	if(tmp == 10){
		printf(GREEN " ENEMY ATTACK CRITICALLY HIT! YOU TOOK %d DAMAGE\n" RESET, mon_attackdmg*2);
		return mon_attackdmg*2;
	}
	else if(tmp > 5){
		printf(RED " ENEMY ATTACK HIT! YOU TOOK %d DAMAGE\n" RESET, mon_attackdmg);
		return mon_attackdmg;
	}
	else{
		printf(GREEN " ENEMY ATTACK MISSED!\n" RESET);
		return 0;
	}

}
//ENCOUTER
int encounter(int chosen_mon, int d_sword, int i_sword, int * leather, int * wool, int *player_hp_fighting, int i_armor_count, int d_armor_count){
    //MON DATA
    char mon_name[20];
    int dontrun;
	int attackdmg = 1;
	int hp_mon = 0;
	int MAX_hp_mon = 0;
	int donthit = 4;
	int mon_attackdmg = 1;

	if(d_sword == 1){
		attackdmg = 3;
	}
	else if(i_sword == 1){
		attackdmg = 2;
	}

	//MON STATS
    switch(chosen_mon){
		case 1: //1 - zombie
			strcpy(mon_name, "zombie");
			dontrun = 6;
			hp_mon = 8;
			mon_attackdmg = 1;
			break;
		case 2: //2 - skeleton
			strcpy(mon_name, "skeleton");
			dontrun = 7;
			hp_mon = 5;
			mon_attackdmg = 2;
			break;
		case 21: //21 - sheep
			strcpy(mon_name, "sheep");
			dontrun = 1;
			hp_mon = 3;
			mon_attackdmg = 0;
			break;
    }
	MAX_hp_mon = hp_mon;

    //CODE
    int volba = 0;
    int nuhuh = 1;
    int tmp = 0;

    while(nuhuh == 1){
		if(hp_mon > 0){
			menu_encounter(chosen_mon, mon_name, hp_mon, MAX_hp_mon, *&player_hp_fighting);
			volba = input_int(0, 1);
			switch(volba){
				case 0: //RUN
				tmp = rand() % 11;
				tmp = tmp - dontrun;
				if(tmp >= 0){
					nuhuh = 0;
				}
				else{
					printf(RED " XXX COULDNT ESCAPE... XXX\n" RESET);
					*player_hp_fighting = *player_hp_fighting - counterattack(mon_attackdmg, i_armor_count, d_armor_count);
					if(*player_hp_fighting <= 0){
						printf(RED " YOU DIED... GAME OVER\n" RESET);
						exit(0);
					}
				}
				break;
				case 1: //ATTACK
					tmp = rand() % 11;
					tmp = tmp - donthit;
					if(tmp > 0){
						hp_mon = hp_mon - attackdmg;
						printf(BOLD " ATTACK HIT\n" RESET);
					}
					else{
						printf(BOLD " ATTACK MISSED\n" RESET);
						*player_hp_fighting = *player_hp_fighting - counterattack(mon_attackdmg, i_armor_count, d_armor_count);
						if(*player_hp_fighting <= 0){
							printf(RED " YOU DIED... GAME OVER\n" RESET);
							exit(0);
						}
					}

				break;
			}
		}
		else{ // if MON DEAD
			int rewtmp = 0;
			rewtmp = rand() % 3;

			//MON STATS 2
			switch(chosen_mon){
				case 1: //1 - zombie
				*leather = *leather + rewtmp;
				printf(GREEN "ENEMY ZOMBIE DIED\nYOU GAINED %d leather/s\n" RESET, rewtmp);
				break;
				case 2: //2 - skeleton
				*leather = *leather + rewtmp;
				printf(GREEN "ENEMY SKELETON DIED\nYOU GAINED %d leather/s\n" RESET, rewtmp);
				break;
				case 21: //21 - sheep
				*wool = *wool + rewtmp;
				printf(GREEN "ENEMY SHEEP DIED\nYOU GAINED %d wool/s\n" RESET, rewtmp);
				break;
			}

			nuhuh = 0;
			return 1;
		}
    }
    printf(GREEN "YYY ESCAPED SUCCESSFULLY YYY\n" RESET);
	return 0;
}
//BOSSOVE 
void samurai_fight(int *boss_hp, int *player_hp, int i_chestplate, int i_helmet, int i_leggings, int i_boots, int d_chestplate, int d_helmet, int d_leggings, int d_boots, int d_sword, int i_sword) {
    int p_attack = 0;
    int damage = 0;
    int p_crit_chance = 0;
    int p_dodge_chance = 0;
    int b_crit_chance = 0;
    int b_dodge_chance = 0;
    int i_armor = 0;
    int d_armor = 0;

    if (i_helmet > 0) {
        i_armor += 1;
    }
    if (i_chestplate > 0) {
        i_armor += 1;
    }
    if (i_leggings > 0) {
        i_armor += 1;
    }
    if (i_boots > 0) {
        i_armor += 1;
    }

    if (d_helmet > 0) {
        d_armor += 1;
    }
    if (d_chestplate > 0) {
        d_armor += 1;
    }
    if (d_leggings > 0) {
        d_armor += 1;
    }
    if (d_boots > 0) {
        d_armor += 1;
    }

    printf(CYAN "Boss HP: %d | Your HP: %d\n" RESET, *boss_hp, *player_hp);
    printf(YELLOW " 1. ATTACK\n 2. DODGE\n 3. DEFEND\n" RESET);

    p_attack = input_int(1, 3);

    p_crit_chance = rand() % 100;
    p_dodge_chance = rand() % 100;
    b_crit_chance = rand() % 100;
    b_dodge_chance = rand() % 100;

    switch (p_attack) {
		case 1:
			if (p_crit_chance <= 20) {
				damage = 2;
				*boss_hp -= damage;
				printf(GREEN "Good hit! You hit the samurai for %d damage!\n" RESET, damage);
			} 
			else {
				damage = 1;
				*boss_hp -= damage;
				printf(YELLOW "You hit the samurai for %d damage!\n" RESET, damage);
			}
			/*}
			else {
				if (p_crit_chance <= 20) {
	                damage = 2;
	                *boss_hp -= damage;
	                printf(GREEN "Critical hit! You hit the samurai for %d damage!\n" RESET, damage);
	            } else {
	                damage = 2;
	                *boss_hp -= damage;
	                printf(GREEN "Good hit! You hit the samurai for %d damage!\n" RESET, damage);
	            }
	        }*/
		break;

		case 2:
			if (i_armor > 0) {
				if (p_dodge_chance <= 20) {
					printf(GREEN "You successfully dodged the samurai's attack!\n" RESET);
					printf(GREEN "You have %d health remaining!\n" RESET, *player_hp);
				} 
				else if (p_dodge_chance > 20 && p_dodge_chance <= 50) {
					damage = 2;
					printf(RED "You got grazed trying to dodge the samurai's attack!\n" RESET);
					printf(RED "You got hit for %d damage!\n" RESET, damage);
					*player_hp -= damage;
					printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				} 
				else{
					damage = 3;
					printf(RED "You failed to dodge the samurai's attack!\n" RESET);
					printf(RED "You got hit for %d damage!\n" RESET, damage);
					*player_hp -= damage;
					printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				}
				break;
			}
		//break;
			else if (d_armor > 0) {
				if (p_dodge_chance <= 20) {
					printf(GREEN "You successfully dodged the samurai's attack!\n" RESET);
					printf(GREEN "You have %d health remaining!\n" RESET, *player_hp);
				}
				else if (p_dodge_chance > 20 && p_dodge_chance <= 50) {
					damage = 1;
					printf(RED "You got grazed trying to dodge the samurai's attack!\n" RESET);
					printf(RED "You got hit for %d damage!\n" RESET, damage);
					*player_hp -= damage;
					printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				} 
				else {
					damage = 2;
					printf(RED "You failed to dodge the samurai's attack!\n" RESET);
					printf(RED "You got hit for %d damage!\n" RESET, damage);
					*player_hp -= damage;
					printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				}
				break;
			}
		//break;
			else{
				if (p_dodge_chance <= 20) {
					printf(GREEN "You successfully dodged the samurai's attack!\n" RESET);
					printf(GREEN "You have %d health remaining!\n" RESET, *player_hp);
				}
				else if (p_dodge_chance > 20 && p_dodge_chance <= 50) {
					damage = 3;
					printf(RED "You got grazed trying to dodge the samurai's attack!\n" RESET);
					printf(RED "You got hit for %d damage!\n" RESET, damage);
					*player_hp -= damage;
					printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				} 
				else {
					damage = 4;
					printf(RED "You failed to dodge the samurai's attack!\n" RESET);
					printf(RED "You got hit for %d damage!\n" RESET, damage);
					*player_hp -= damage;
					printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				}
			}
		break;

		case 3:
			if (i_armor > 0) {
				damage = 2;
				printf(YELLOW "You defend against the samurai's attack, reducing the damage by 50%%!\n" RESET);
				printf(RED "You got hit for %d damage!\n" RESET, damage);
				*player_hp -= damage;
				printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				break; 
			}
			else if (d_armor > 0) {
				damage = 1;
				printf(YELLOW "You defend against the samurai's attack, reducing the damage by 50%%!\n" RESET);
				printf(RED "You got hit for %d damage!\n" RESET, damage);
				*player_hp -= damage;
				printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				break; 
			}
			else{
				damage = 3;
				printf(YELLOW "You defend against the samurai's attack, reducing the damage by 50%%!\n" RESET);
				printf(RED "You got hit for %d damage!\n" RESET, damage);
				*player_hp -= damage;
				printf(RED "You have %d health remaining!\n" RESET, *player_hp);
				break; 
			}
		break;
	}

	if (p_attack == 1) {
		if (i_armor > 0) {
				if (b_crit_chance <= 20) {
					damage = 4;
					printf(RED "The samurai lands a critical hit on you for %d damage!\n" RESET, damage);
					*player_hp -= damage;
				} 
				else if (b_crit_chance > 20 && b_crit_chance <= 50) {
					damage = 2;
					printf(RED "The samurai hits you for %d damage!\n" RESET, damage);
					*player_hp -= damage;
				} 
				else{
					printf(GREEN "The samurai's attack missed!\n" RESET);
				}
		}//NOVY
		else if (d_armor > 0) {
				if (b_crit_chance <= 20) {
					damage = 2;
					printf(RED "The samurai lands a critical hit on you for %d damage!\n" RESET, damage);
					*player_hp -= damage;
				} 
				else if (b_crit_chance > 20 && b_crit_chance <= 50) {
					damage = 1;
					printf(RED "The samurai hits you for %d damage!\n" RESET, damage);
					*player_hp -= damage;
				} 
				else{
					printf(GREEN "The samurai's attack missed!\n" RESET);
				}
		}
		else{//NOVY
				if (b_crit_chance <= 20) {
					damage = 6;
					printf(RED "The samurai lands a critical hit on you for %d damage!\n" RESET, damage);
					*player_hp -= damage;
				} 
				else if (b_crit_chance > 20 && b_crit_chance <= 50) {
					damage = 3;
					printf(RED "The samurai hits you for %d damage!\n" RESET, damage);
					*player_hp -= damage;
				} 
				else{
					printf(GREEN "The samurai's attack missed!\n" RESET);
				}
		}
	}	
	else if (p_attack == 2) {
		//nemusime? ig
	}
	/* else if (p_attack == 3) {
        if (b_crit_chance <= 20) {
            damage = 2;
            printf(RED "The samurai lands a critical hit on you for %d damage, but you defended against it!\n" RESET, damage);
            *player_hp -= damage;
        } else if (b_crit_chance > 20 && b_crit_chance <= 50) {
            damage = 0;
            printf(RED "The samurai hits you for %d damage, but you defended against it!\n" RESET, damage);
            *player_hp -= damage;
        } else {
            printf(GREEN "The samurai's attack missed!\n" RESET);
        }
     }
    }
    
    if (d_armor > 0) {
        if (b_crit_chance <= 20) {
            damage = 3;
            printf(RED "The samurai lands a critical hit on you for %d damage!\n" RESET, damage);
            *player_hp -= damage;
        } else if (b_crit_chance > 20 && b_crit_chance <= 50) {
            damage = 1;
            printf(RED "The samurai hits you for %d damage!\n" RESET, damage);
            *player_hp -= damage;
        } else {
            printf(GREEN "The samurai's attack missed!\n" RESET);
            else if (p_attack == 2) {
        }
     else if (p_attack == 3) {
        if (b_crit_chance <= 20) {
            damage = 1;
            printf(RED "The samurai lands a critical hit on you for %d damage, but you defended against it!\n" RESET, damage);
            *player_hp -= damage;
        } else if (b_crit_chance > 20 && b_crit_chance <= 50) {
            damage = 0;
            printf(RED "The samurai hits you for %d damage, but you defended against it!\n" RESET, damage);
            *player_hp -= damage;
        } else {
            printf(GREEN "The samurai's attack missed!\n" RESET);
        }
     }
        }
    }
    
    else if (p_attack == 2) {
        }
     else if (p_attack == 3) {
        if (b_crit_chance <= 20) {
            damage = 3;
            printf(RED "The samurai lands a critical hit on you for %d damage, but you defended against it!\n" RESET, damage);
            *player_hp -= damage;
        } else if (b_crit_chance > 20 && b_crit_chance <= 50) {
            damage = 0;
            printf(RED "The samurai hits you for %d damage, but you defended against it!\n" RESET, damage);
            *player_hp -= damage;
        } else {
            printf(GREEN "The samurai's attack missed!\n" RESET);
        }*/
}


//BIOMY FIGHT

int plains(int d_sword, int i_sword, int * leather, int * wool, int * player_hp_fighting, int i_armor_count, int d_armor_count){
    int dncycle = 1;
    int whi = 1;
    while(whi==1){
        dncycle = rand() % 2;
        if(dncycle == 0){ //NIGHT
            printf(BOLD "\nIts night...\n" RESET);
			int tmp = rand() % 2;
			if(tmp == 0){
				whi =encounter(1, d_sword, i_sword, leather, wool, player_hp_fighting, i_armor_count, d_armor_count);
			}
            else if(tmp == 1){
				whi = encounter(2, d_sword, i_sword, leather, wool, player_hp_fighting, i_armor_count, d_armor_count);
			}

        }
        else if(dncycle == 1){ //DAY
            printf(BOLD "\nIts a new day!\n" RESET);
            whi = encounter(21, d_sword, i_sword, leather, wool, player_hp_fighting, i_armor_count, d_armor_count);
        }
    }
    return 0;
}

//DATA SAVE
int getdatapls(int * leather, int * wool, int * wood, int * iron, int * diamonds, int * i_helmet, int * d_helmet, int * i_chestplate, int * d_chestplate, int * i_leggings, int * d_leggings, int * i_boots, int * d_boots, int * d_sword, int * i_sword, int * i_pickaxe, int * d_pickaxe, int * i_axe, int * d_axe){
	FILE * fptr_fce;
	char voleni_file_jmeno[30];
	int whil = 1;
	while(whil){
		input_string(voleni_file_jmeno, sizeof(voleni_file_jmeno), " CHOOSE FILE NAME: ");
		char voleni_file_jmeno_tricetpet[35];
		strcpy(voleni_file_jmeno_tricetpet, voleni_file_jmeno);
		strcat(voleni_file_jmeno_tricetpet, ".txt");
		fptr_fce = fopen(voleni_file_jmeno_tricetpet, "r");
			if(fptr_fce == NULL){
				printf("UNABLE TO OPEN SAVE (it prob. doesnt exit)");
				printf("TRY AGAIN?\n 1. YES\n 2. NO (start new game)\n");
				int retry = input_int(1, 2);
				if(retry == 2){
					printf("DATA NOT LOADED, STARTING NEW GAME");
					return 0;
				}
				else{
					continue;
				}
			}
			else{
				whil = 0;
			}
	}
		char s_data_save[10];

		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*leather = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*wool = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*wood = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*iron = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*diamonds = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*i_helmet = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*d_helmet = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*i_chestplate = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*d_chestplate = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*i_leggings = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*d_leggings = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*i_boots = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*d_boots = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*d_sword = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*i_sword = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*i_pickaxe = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*d_pickaxe = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*i_axe = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*d_axe = atoi(s_data_save);
	fclose(fptr_fce);
	printf("DATA SUCCESFULLY LOADED");
	return 0;

}

int main()
{
	int volba = 0;
	int size = 10;
	char inventory [size];
	int control = 0;
	int chance_mine = 0;
	int volba_mine = 0;
	int wool = 0;
	int wood = 0;
	int iron = 0;
	int diamonds = 0;
	int volba_craft = 0;
	int volba_fight = 0;
	int leather = 0;
	int crafting_mat_volba = 0;
	int backpack = 0;
	int i_helmet = 0;
	int d_helmet = 0;
	int d_chestplate = 0;
	int i_chestplate = 0;
	int i_leggings = 0;
	int d_leggings = 0;
	int i_boots = 0;
	int d_boots = 0;
	int d_sword = 0;
	int i_sword = 0;
	int i_pickaxe = 0;
	int d_pickaxe = 0;
	int i_axe = 0;
	int d_axe = 0;
	int valid = 0;
	int volim = 0;
	int player_hp_fighting = 10;
	int i_armor_count = 0;
	int d_armor_count = 0;
	const int cislo = 67;
	int boss_fight_volba = 0;
	int boss_loop = 0;
	srand(time(NULL));
	SetConsoleOutputCP(65001); //nastaveni UTF-8 pro windows, aby se zobrazovaly tyhle hezký kostičky :D (holy shit tohle napsalo vs za me)
	FILE *fptr; //pointer do save (POINTERRRRRR)
	//boss
	int volba_menu = 0;
	int volba_boss = 0;
	int boss_hp = 100;
	int player_hp = 100;
	int running = 1; 


	getdatapls(&leather, &wool, &wood, &iron, &diamonds, &i_helmet, &d_helmet, &i_chestplate, &d_chestplate, &i_leggings, &d_leggings, &i_boots, &d_boots, &d_sword, &i_sword, &i_pickaxe, &d_pickaxe, &i_axe, &d_axe);

	while (1) {
		i_armor_count = i_helmet + i_chestplate + i_leggings + i_boots;
		d_armor_count = d_helmet + d_chestplate + d_leggings + d_boots;
		menu();
		volim = input_int(0, 5);

		switch (volim) {
		case 0:
			printf(RED " \nSAVE 'N QUIT?\n" RESET);
			printf(YELLOW " 1. SAVE\n 2. DONT SAVE\n 3. BACK\n" RESET);
			valid = input_int(1, 3);
			if (valid == 1) {
				char voleni_file_jmeno[30];
				input_string(voleni_file_jmeno, sizeof(voleni_file_jmeno), " CHOOSE FILE NAME: ");
				char voleni_file_jmeno_tricetpet[35];
				strcpy(voleni_file_jmeno_tricetpet, voleni_file_jmeno);
				strcat(voleni_file_jmeno_tricetpet, ".txt");
				fptr = fopen(voleni_file_jmeno_tricetpet, "w");
				fprintf(fptr, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ", leather, wool, wood, iron, diamonds, i_helmet, d_helmet, i_chestplate, d_chestplate, i_leggings, d_leggings, i_boots, d_boots, d_sword, i_sword, i_pickaxe, d_pickaxe, i_axe, d_axe);
				fclose(fptr);
				printf(RED "SAVING AND ENDING THE GAME..." RESET);
				Sleep(500);
				return 0;
			}
			else if(valid == 2){
				printf(RED "ENDING THE GAME..." RESET);
				Sleep(500);
				return 0;
			}
			else{
				break;
			}
			break;
		case 1: // crafting
			menu_craft(leather, wool, wood, iron, diamonds);
			volba_craft = input_int(0, 8);
			switch (volba_craft) {

			case 1: // helmet
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 5 && i_helmet != 1) {
						printf(GREEN "IRON HELMET CRAFTED. WELL DONE!" RESET);
						i_helmet = 1;
						iron -= 5;
						printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
					}
					else {
						printf(RED "IRON HELMET COULDN'T BE CRAFTED..." RESET);
					}
				}
				else if (crafting_mat_volba == 2) {
					if (diamonds >= 5 && d_helmet != 1) {
						printf(GREEN "DIAMOND HELMET CRAFTED. WELL DONE!" RESET);
						d_helmet = 1;
						diamonds -= 5;
						printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						i_helmet = 0;
					}
					else {
						printf(RED "DIAMOND HELMET COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 2: // chestplate
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 8 && i_chestplate != 1) {
						printf(GREEN "IRON CHESTPLATE CRAFTED. WELL DONE!" RESET);
						i_chestplate = 1;
						iron -= 8;
						printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
					}
					else {
						printf(RED "IRON CHESTPLATE COULDN'T BE CRAFTED..." RESET);
					}
				}
				else if (crafting_mat_volba == 2) {
					if (diamonds >= 8 && d_chestplate != 1) {
						printf(GREEN "DIAMOND CHESTPLATE CRAFTED. WELL DONE!" RESET);
						d_chestplate = 1;
						diamonds -= 8;
						printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						i_chestplate = 0;
					}
					else {
						printf(RED "DIAMOND CHESTPLATE COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 3: // leggings
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 7 && i_leggings != 1) {
						printf(GREEN "IRON LEGGINGS CRAFTED. WELL DONE!" RESET);
						i_leggings = 1;
						iron -= 7;
						printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
					}
					else {
						printf(RED "IRON LEGGINGS COULDN'T BE CRAFTED..." RESET);
					}
				}
				else if (crafting_mat_volba == 2) {
					if (diamonds >= 7 && d_leggings != 1) {
						printf(GREEN "DIAMOND LEGGINGS CRAFTED. WELL DONE!" RESET);
						d_leggings = 1;
						diamonds -= 7;
						printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						i_leggings = 0;
					}
					else {
						printf(RED "DIAMOND LEGGINGS COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 4: // boots
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 4 && i_boots != 1) {
						printf(GREEN "IRON BOOTS CRAFTED. WELL DONE!" RESET);
						i_boots = 1;
						iron -= 4;
						printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
					}
					else {
						printf(RED "IRON BOOTS COULDN'T BE CRAFTED..." RESET);
					}
				}
				else if (crafting_mat_volba == 2) {
					if (diamonds >= 4 && d_boots != 1) {
						printf(GREEN "DIAMOND BOOTS CRAFTED. WELL DONE!" RESET);
						d_boots = 1;
						diamonds -= 4;
						printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						i_boots = 0;
					}
					else {
						printf(RED "DIAMOND BOOTS COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 5: // sword
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 2 && i_sword != 1 && wood >= 2) {
						printf(GREEN "IRON SWORD CRAFTED. WELL DONE!" RESET);
						i_sword = 1;
						iron -= 2;
						wood -= 2;
						printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
						printf(YELLOW " YOU HAVE %d WOOD" RESET, wood);
					}
					else {
						printf(RED "IRON SWORD COULDN'T BE CRAFTED..." RESET);
					}
				}
				else if (crafting_mat_volba == 2) {
					if (diamonds >= 2 && d_sword != 1 && wood >= 2) {
						printf(GREEN "DIAMOND SWORD CRAFTED. WELL DONE!" RESET);
						d_sword = 1;
						diamonds -= 2;
						wood -= 2;
						printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						printf(YELLOW " YOU HAVE %d WOOD" RESET, wood);
						i_sword = 0;
					}
					else {
						printf(RED "DIAMOND SWORD COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 6: // pickaxe
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 3 && i_pickaxe != 1 && wood >= 2) {
						printf(GREEN "IRON PICKAXE CRAFTED. WELL DONE!" RESET);
						i_pickaxe = 1;
						iron -= 3;
						printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
						wood -= 2;
						printf(YELLOW " YOU HAVE %d WOOD" RESET, wood);
					}
					else {
						printf(RED "IRON PICKAXE COULDN'T BE CRAFTED..." RESET);
					}
				}
				else if (crafting_mat_volba == 2) {
					if (diamonds >= 3 && d_pickaxe != 1 && wood >= 2) {
						printf(GREEN "DIAMOND PICKAXE CRAFTED. WELL DONE!" RESET);
						d_pickaxe = 1;
						diamonds -= 3;
						wood -= 2;
						printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						printf(YELLOW " YOU HAVE %d WOOD" RESET, wood);
						i_pickaxe = 0;
					}
					else {
						printf(RED "DIAMOND PICKAXE COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 7: // axe
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				control = 0;
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 3 && i_axe != 1 && wood >= 2) {
						printf(GREEN "IRON AXE CRAFTED. WELL DONE!" RESET);
						i_axe = 1;
						iron -= 3;
						wood -= 2;
						printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
						printf(YELLOW " YOU HAVE %d WOOD" RESET, wood);
					}
					else {
						printf(RED "IRON AXE COULDN'T BE CRAFTED..." RESET);
					}
				}
				else if (crafting_mat_volba == 2) {
					if (diamonds >= 3 && d_axe != 1 && wood >= 2) {
						printf(GREEN "DIAMOND AXE CRAFTED. WELL DONE!" RESET);
						d_axe = 1;
						diamonds -= 3;
						wood -= 2;
						printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						printf(YELLOW " YOU HAVE %d WOOD" RESET, wood);
						i_axe = 0;
					}
					else {
						printf(RED "DIAMOND AXE COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 8: // backpack
				if (leather >= 5 && backpack != 1) {
					printf(GREEN "BACKPACK CRAFTED... + 10 INVENTORY SPACE\n" RESET);
					backpack = 1;
					leather -= 5;
					printf(YELLOW " YOU HAVE %d LEATHER" RESET, leather);
				}
				else if (backpack == 1) {
					printf(RED "You already have a backpack!\n" RESET);
				}
				else {
					printf(RED "BACKPACK COULDN'T BE CRAFTED... Not enough leather! Need 5.\n" RESET);
				}
				break;

			case 0: // back
				break;
			}
			
			break;

		case 2: // mining
			menu_mine();
			volba_mine = input_int(0, 3);

			switch (volba_mine) {
			case 1:
				wood = wood_mine(chance_mine, wood, i_axe, d_axe);
				printf(YELLOW "\nYou have %d logs\n" RESET, wood);
				break;

			case 2:
				iron = iron_mine(chance_mine, iron, i_pickaxe, d_pickaxe);
				printf(YELLOW "\nYou have %d iron\n" RESET, iron);
				break;

			case 3:
				diamonds = diamond_mine(chance_mine, diamonds, i_pickaxe, d_pickaxe);
				printf(YELLOW "\nYou have %d diamonds\n" RESET, diamonds);
				break;

			case 0:
				break;
			}
			break;

		case 3: // fighting goldddd
    menu_fighting();
    volba_fight = input_int(0, 3);
    switch (volba_fight) {
        case 0: // go back
            break;
        case 1: // boss fight
            boss_loop = 1;
            while (boss_loop == 1) {
                menu_boss();
                boss_fight_volba = input_int(0, 5);

                switch (boss_fight_volba) {
                    case 0: // Back
                        boss_loop = 0;
                        break;
                    case 1: // Boss Selection Menu
                        boss_menu();
                        volba_boss = input_int(0, 5);

                        switch (volba_boss) {
                            case 0:
                                break;
                            case 1: // samurai
                                boss_hp = 100;
                                player_hp = 100;
                                printf(CYAN "You are fighting against the samurai...\n" RESET);
                                while (boss_hp > 0 && player_hp > 0) {
                                    samurai_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                    if (player_hp <= 0) {
                                        printf(RED "\nYou were defeated by the samurai!\n" RESET);
                                        break;    
                                    } else if (boss_hp <= 0) {
                                        printf(GREEN "\nYou defeated the samurai!\n" RESET);
                                        break;    
                                    }
                                }
                                break;
                            /*case 2: // mage
                                boss_hp = 10;
                                player_hp = 100;
                                while (boss_hp > 0 && player_hp > 0) {
                                    mage_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                    if (player_hp <= 0) {
                                        printf(RED "\nYou were defeated by the mage!\n" RESET);
                                        break;    
                                    } else if (boss_hp <= 0) {
                                        printf(GREEN "\nYou defeated the mage!\n" RESET);
                                        break;    
                                    }
                                }
                                break;
                            case 3: // tank
                                boss_hp = 200;
                                player_hp = 100;
                                while (boss_hp > 0 && player_hp > 0) {
                                    tank_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                    if (player_hp <= 0) {
                                        printf(RED "\nYou were defeated by the tank!\n" RESET);
                                        break;    
                                    } else if (boss_hp <= 0) {
                                        printf(GREEN "\nYou defeated the tank!\n" RESET);
                                        break;    
                                    }
                                }
                                break;
                            case 4: // assassin
                                boss_hp = 100;
                                player_hp = 100;
                                while (boss_hp > 0 && player_hp > 0) {
                                    assassin_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                    if (player_hp <= 0) {
                                        printf(RED "\nYou were defeated by the assassin!\n" RESET);
                                        break;    
                                    } else if (boss_hp <= 0) {
                                        printf(GREEN "\nYou defeated the assassin!\n" RESET);
                                        break;    
                                    }
                                }
                                break;*/
                            case 5: // random
                                boss_hp = 100;
                                player_hp = 100;
                                int random_boss = rand() % 4 + 1;
                                switch (random_boss) {
                                    case 1: // random samurai
                                        printf(CYAN "You are fighting against the samurai...\n" RESET);
                                        while (boss_hp > 0 && player_hp > 0) {
                                            samurai_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                            if (player_hp <= 0) { break; } 
                                            else if (boss_hp <= 0) { break; }
                                        }
                                        break;
                                    /*case 2: // random mage
                                        while (boss_hp > 0 && player_hp > 0) {
                                            mage_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                            if (player_hp <= 0) { break; } 
                                            else if (boss_hp <= 0) { break; }
                                        }
                                        break;
                                    case 3: // random tank
                                        while (boss_hp > 0 && player_hp > 0) {
                                            tank_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                            if (player_hp <= 0) { break; } 
                                            else if (boss_hp <= 0) { break; }
                                        }
                                        break;
                                    case 4: // random assassin
                                        while (boss_hp > 0 && player_hp > 0) {
                                            assassin_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword); 
                                            if (player_hp <= 0) { break; } 
                                            else if (boss_hp <= 0) { break; }
                                        }
                                        break;*/
                                }
                                break;
                        } // end volba_boss switch
                        break; // end case 1 of boss_fight_volba
                    
                    case 2: printf(GREEN "You chose mage boss!\n" RESET); break;
                    case 3: printf(GREEN "You chose tank boss!\n" RESET); break;
                    case 4: printf(GREEN "You chose assassin boss!\n" RESET); break;
                } // end boss_fight_volba switch
            } // end boss_loop while
            break; 

        case 2: // explore
            valid = plains(d_sword, i_sword, &leather, &wool, &player_hp_fighting, i_armor_count, d_armor_count);
            if(valid != 0) printf("plains fce failed :(");
            break;
        case 3: // dungeon
            break;
    } // end volba_fight switch
    break; // end main case 3
		case 4: // inventory
			printf(BOLD CYAN "\n=== INVENTORY ===\n" RESET);
			printf(RED " Health:              %d/10\n" RESET, player_hp_fighting);
			printf(YELLOW " Logs:             %d\n" RESET, wood);
			printf(YELLOW " Iron:             %d\n" RESET, iron);
			printf(YELLOW " Diamonds:         %d\n" RESET, diamonds);
			printf(YELLOW " Leather:          %d\n" RESET, leather);
			printf(YELLOW " Wool:             %d\n" RESET, wool);
			printf(CYAN " diamond sword:      %d\n" RESET, d_sword);
			printf(GRAY " iron sword:         %d\n" RESET, i_sword);
			printf(CYAN " diamond pickaxe:    %d\n" RESET, d_pickaxe);
			printf(GRAY " iron pickaxe:       %d\n" RESET, i_pickaxe);
			printf(CYAN " diamond axe:        %d\n" RESET, d_axe);
			printf(GRAY " iron axe:           %d\n" RESET, i_axe);
			printf(CYAN " diamond helmet:     %d\n" RESET, d_helmet);
			printf(GRAY	 " iron helmet:       %d\n" RESET, i_helmet);
			printf(CYAN " diamond chestplate: %d\n" RESET, d_chestplate);
			printf(GRAY " iron chestplate:    %d\n" RESET, i_chestplate);
			printf(CYAN " diamond leggings:   %d\n" RESET, d_leggings);
			printf(GRAY " iron leggings:      %d\n" RESET, i_leggings);
			printf(CYAN " diamond boots:      %d\n" RESET, d_boots);
			printf(GRAY " iron boots:         %d\n" RESET, i_boots);
		break;
		case 5: //eat
			heal_player(&player_hp_fighting);
		break;
		}
	}

	return 0;
}

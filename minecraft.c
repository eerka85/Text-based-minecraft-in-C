//POMOC POMOC POMOC POMOC - verze 11.0 (mage s  dlescreen, samurai, random boss) verze 10.0 (tank, mlib, art) verze 9.0 (dice, phub) verze 8.0(old samuraj) verze 7.0 (healy, dice art(1)) verze 6.0 (bug fixes, vic v inv, crafting recepies, easy loadovani saveu) verze 5.0 (vic v inv, crafting recepies, easy loadovani saveu) verze 4.1(==SAVEOVANI==, UTF - 8 text vsude - ta setconsoleoutput fce v main, 2x kosticek,SHEEP ART, SKELL ART and ZOMBIE ART) 3.0 (clear screen + menu boss) + 2.0(plains + encounter + counterattack) 1.0(+ crafting armor/weapons + barvy + input int/string + inventory)
//NAPADY - 
//       - dum? - zahrada, crafting table, furnace, animal farmu [village? - stardew valley npccka? item trade?]
//		 - gold?
//       - trophy room pro boss fighty? (soucasti domu?)
//		 - lore?
// stehlik mrda dvanactky
//		
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <conio.h>
#include <sys/time.h>
#include "mlib.h"
#include "art.h"
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
		printf(YELLOW"\n CHOOSE: " RESET);
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
	printf(BLUE "\n CONTINUE? (press enter)" RESET);
	getchar();
	printf("\033[H\033[2J");
}
void del_screen(){
	system("cls");
}



//MENY

void menu() {
	clear_screen();
	printf(BOLD CYAN "\n=== ADVENTURE ===\n" RESET);
	printf(YELLOW " 1. CRAFT\n 2. MINE\n 3. FIGHT\n 4. INVENTORY\n 5. HEAL\n 0. LEAVE" RESET);
}

void menu_mine() {
	clear_screen();
	printf(BOLD CYAN "\n===MINING MENU===\n" RESET);
	printf(YELLOW " 1. MINING WOOD\n 2. MINING IRON\n 3. MINING DIAMONDS\n 0. BACK" RESET);
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
	printf (YELLOW " 1. LEVEL - 1 Samurai \n 2. LEVEL - 2 Mage \n 3. LEVEL - 3 Tank \n 4. LEVEL - 4 WIP\n 5. RANDOM LEVEL\n 0. BACK" RESET);
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
	printf(YELLOW " 1. BOSS FIGHT\n 2. EXPLORE (plains)\n 3. EXPLORE (caves)\n 0. BACK" RESET);
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
	printf(YELLOW " 1.ATTACK\n 0.RUN" RESET);
}
//jidlo
int heal_player(int * player_hp_fighting){
	int volba_d = 0;
	int con_d_whil = 1;
	int villager_dice_roll = 0;
	int p_dice_roll = 0;
	int dv1;
	int dv2;
	int dp1;
	int dp2;
	printf(YELLOW "\n PLAY DICE WITH VILLAGER FOR FOOD?\n 1. YES\n 0. NO" RESET);
	volba_d = input_int(0, 1);
	switch(volba_d){
		case 0:
			return 0;
		break;
		case 1:
			while(con_d_whil){
				//vil roll - ((rand() %6)+1)
				dv1 =((rand() %6)+1);
				dv2 =((rand() %6)+1);
				dice(dv1, dv2);
				villager_dice_roll = dv1 + dv2;
				printf(RED "\n The villager rolled %d," RESET, villager_dice_roll);

				printf(GREEN "\n Your turn, press ENTER to roll: ");
				getchar();
				dp1 = ((rand() %6)+1);
				dp2 = ((rand() %6)+1);
				dice(dp1, dp2);
				p_dice_roll = dp1 + dp2;
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
int dodge_TANK(){
	//zapamatovani beatu? 
	//vygeneruje beat a b b a
	struct timeval start, stop;
	int velikost_abpol = 7; 
	char abpol[velikost_abpol];
	char uzpol[velikost_abpol];
	int computar = 0;
	for(int i = 0; i < velikost_abpol-1; i++){ //generovani ababbababbabab
		abpol[i] = rand() % (98-97 +1) +97;
	}
	abpol[velikost_abpol-1] = '\0';
	printf(YELLOW "\n You get ready for a dodge\n (repeat this 6*a or b sequence after 321 go)");
	printf(RED "\n Show sequence?" RESET);
	getchar();
	printf("\n");
	for(int i = 0; i < velikost_abpol-1; i++){
		printf("%c ", abpol[i]);
	}
	printf("\n Hiding sequence in 3");
	Sleep(750);
	printf("\n Hiding sequence in 2");
	Sleep(750);
	printf("\n Hiding sequence in 1");
	Sleep(750);
	del_screen();

	//uzivatel musi zopakovat
	printf(RED "\n Start inputing sequence?" RESET);
	clean_buffer();
	gettimeofday(&start, NULL);
	while(_kbhit()){ //_kbhit vraci tru nebo false jestli je neco v bufferu? myslim idk
		_getch(); //mrdne vec z bufferu dopici
	}
	while(1){
	input_string(uzpol, velikost_abpol, "\ntype: ");
		computar = strcmp(uzpol, abpol);
		printf("%s ", abpol);
		printf("%s ", uzpol);
		if(computar == 0){
			break;
		}
		else{
			printf("\n Try again");
		}
	}
	gettimeofday(&stop, NULL);
	//podle ryvhlosti vetsi sance na dodge?
	// Calculate total elapsed time in microseconds
    long long start_usec = (long long)start.tv_sec * 1000000 + start.tv_usec;
    long long stop_usec = (long long)stop.tv_sec * 1000000 + stop.tv_usec;
    long long elapsed_usec = stop_usec - start_usec;

	// Convert to seconds and remaining milliseconds
    long seconds = elapsed_usec / 1000000;
    long milliseconds = (elapsed_usec % 1000000) / 1000;

	printf("Ended at %ld seconds and %ld milliseconds\n", seconds, milliseconds);
	if(elapsed_usec < 3000000){
		printf(BOLD GREEN "\n YOU DODGED!");
		return 1;
	}
	else{
		printf(RED "\n YOU GOT HIT" RESET);
		return 0;
	}	
	
}
int dmg_TANK(){ //vracet dmg
	//pocitat milisekundy od 321 ted?
	struct timeval start, stop;
	char naps_att[100] = {0};
	int factcheck = 0;
	printf(YELLOW "\n You get ready for an attack\n (type attack after 321 go)" RESET);
	printf(RED "\n Are you ready?" RESET);
	getchar();
	printf(BOLD CYAN "\n type attack in\n" RESET);
	printf(RED "3\n" RESET);
	Sleep(1000);
	printf(RED "2\n" RESET);
	Sleep(1000);
	printf(RED "1\n" RESET);
	Sleep(1050); 
	
	while(_kbhit()){ //_kbhit vraci tru nebo false jestli je neco v bufferu? myslim idk
		_getch(); //mrdne vec z bufferu dopici
	}
	gettimeofday(&start, NULL);
	printf(GREEN "GO! : " RESET);
	do{
		input_string(naps_att, sizeof(naps_att), "");
		factcheck = strcmp("attack", naps_att);
		if(factcheck != 0){
			printf(BOLD RED "\n wrong input\n Try again: " RESET);
		}
		else{
			break;
		}
	}while(factcheck != 0);

	gettimeofday(&stop, NULL);
	// Calculate total elapsed time in microseconds
    long long start_usec = (long long)start.tv_sec * 1000000 + start.tv_usec;
    long long stop_usec = (long long)stop.tv_sec * 1000000 + stop.tv_usec;
    long long elapsed_usec = stop_usec - start_usec;

	// Convert to seconds and remaining milliseconds
    long seconds = elapsed_usec / 1000000;
    long milliseconds = (elapsed_usec % 1000000) / 1000;

	printf("Ended at %ld seconds and %ld milliseconds\n", seconds, milliseconds);
	printf("%lld", elapsed_usec);
	if(elapsed_usec < 1000000){
		printf(BOLD GREEN "\n CRITICAL HIT!");
		return 2;
	}
	else if(elapsed_usec < 3000000){
		printf(GREEN "\n ATTACK HIT" RESET);
		return 1;
	}
	else{
		printf(GREEN "\n ATTACK MISSED" RESET);
		return 0;
	}
	
	
}
int tank_fight(int i_armor_count, int d_armor_count){ //idk jestli se hodi mezi ostatni bossfighty...
	int PLAYER_lives = 4;				//PLAYER
	int max_PLAYER_lives = PLAYER_lives;
	int PLAYER_decision_roud = 0;

	int MAUS_lives = 10;				//MOOSE xd
	int max_MAUS_lives = MAUS_lives;
	int MAUS_decision_roud = 0;
	
	int decide_chance = 0;
	int tank_attack_dmg = 2; 
	int dodge = 0;

	clear_screen();

	printf(YELLOW "\n You walk around hilly plains and suddenly you hear a strange soud..." RESET);
	printf(CYAN "\n Take a closer look?\n 0. = NAH\n 1. = YEA" RESET);
	int rlynga = input_int(0, 1);
	if(rlynga == 0){
		return 0;
	}
	printf(YELLOW "\n Behind one of the hills appears.... " RESET);
	Sleep(2000);
	printf(RED "A 128mm long cannon???" RESET);
	Sleep(1000);
	printf(BOLD RED "\n\n === A MAUS tank appeared to have noticed you! ===\n" RESET);
	
	do{
		if(MAUS_lives <=0){ //win
			printf(BOLD GREEN "\n You managed to defeat the TANK boss, congratulations..." RESET);
			return 0;
		}
		if(PLAYER_lives > 4){ //too much HP
			PLAYER_lives = 4;
		}
		printf(RED "\n MAUS HP = %d/%d" RESET, MAUS_lives, max_MAUS_lives);
		printf(GREEN "\n YOUR HP = %d/%d" RESET, PLAYER_lives, max_PLAYER_lives);

		//PLAYER decides what to do
		//1 - attack 2x 
		//2 - try dodge and attack
		//3 - pray +1 hp - can be disrupted by an attack (godess art?)
		printf(BOLD CYAN "\n What will you do?" RESET);
		printf(YELLOW "\n 1. ATTACK twice\n 2. try to DODGE and then ATTACK\n 3. PRAY" RESET);
		PLAYER_decision_roud = input_int(1, 3);


		//tank decides what to do
		//1 - heal
		//2 - attack
		if(MAUS_lives < max_MAUS_lives){
			decide_chance = rand() % 100;
			if(decide_chance > 75){
				MAUS_decision_roud = 1;
			}
			else{
				MAUS_decision_roud = 2;
			}
		}
		else{
			MAUS_decision_roud = 2;
		}

		//stuff happens
		switch(MAUS_decision_roud){
			case 1://heal
				printf(YELLOW "\n The tank tries to reinforce its hull" RESET);
				decide_chance = rand() % 100;
				if(decide_chance > 60){
					MAUS_lives++;
					printf("\n TANK healed 1 hp");
				}

				switch(PLAYER_decision_roud){
					case 1://attacked
						printf(GREEN "\n Ambush it while its distracted!" RESET);
						MAUS_lives = MAUS_lives - dmg_TANK(); 
						clear_screen();
						printf(GREEN "\n Attack it again!" RESET);
						MAUS_lives = MAUS_lives - dmg_TANK(); 
					break;
					case 2://do a at
						printf(YELLOW "\n Theres nothing to dodge..." RESET);
						printf(GREEN "\n Ambush it while its distracted!" RESET);
						MAUS_lives = MAUS_lives - dmg_TANK(); 
					break;
					case 3://pray
						printf(YELLOW "\n You use this chance to pray to BENJAMIN NETENYAHU" RESET);
						printf("\n.");
						Sleep(500);
						printf("\n.");
						Sleep(500);
						printf("\n.");
						Sleep(500);
						printf("\n.");
						Sleep(500);

						decide_chance = rand() % 100;
						if(decide_chance > 65){ //vtipny by bylo kdyby vic zlata znamenalo lepsi sance
							printf(GREEN "\n The jewish spirit within you blooms\n Healed 1 HP!" RESET);
							PLAYER_lives++;
						}
						else{
							printf(RED "\n Nothing happends..." RESET);
						}
					break;
				}
			break;
			case 2://at
				printf(YELLOW "\n The tank aims its cannon in your direction" RESET);
				if(MAUS_lives < max_MAUS_lives/2){
					printf(RED " angrily" RESET);
				}

				switch(PLAYER_decision_roud){
					case 1:
						printf(YELLOW"\n The tank attempts to fire at you");
						decide_chance = rand() % 100;
						decide_chance = decide_chance - (i_armor_count*10); //idk jesti fachci - melo by zmensut sanci na hit
						if(decide_chance >30){
							printf(RED "\n The tank fires and the tank round hits you!"RESET);
							if(d_armor_count <1){ //no dia
								printf(RED "\n You lose %dhp"RESET, tank_attack_dmg);
								PLAYER_lives = PLAYER_lives - tank_attack_dmg;
							}
							else{ //dia
								printf(RED "\n You lose %dhp"RESET, tank_attack_dmg / 2);
								PLAYER_lives = PLAYER_lives - tank_attack_dmg / 2;
							}
						}
						else{
								printf("\n The tank missed");
						}

						printf("\n Your turn to attack! give him back what he deserves!");
						MAUS_lives = MAUS_lives - dmg_TANK(); 
						clear_screen();

						printf("\n Attack again once more!");
						MAUS_lives = MAUS_lives - dmg_TANK(); 
						clear_screen();
					break;
					case 2:
						printf(YELLOW"\n The tank attempts to fire at you");
						dodge = dodge_TANK();
						if(dodge == 1){
							printf("\n The TANKs attack just barely missed you!");
						}
						else if(dodge == 0){
							decide_chance = rand() % 100;
							decide_chance = decide_chance - (i_armor_count*10); //idk jesti fachci - melo by zmensut sanci na hit
							if(decide_chance >30){
								printf(RED "\n The tank fires and the tank round hits you!"RESET);
								if(d_armor_count <1){ //no dia
									printf(RED "\n You lose %dhp"RESET, tank_attack_dmg);
									PLAYER_lives = PLAYER_lives - tank_attack_dmg;
								}
								else{ //dia
									printf(RED "\n You lose %dhp"RESET, tank_attack_dmg / 2);
									PLAYER_lives = PLAYER_lives - tank_attack_dmg / 2;
								}
							}	
							else{
								printf("\n The tank missed");
							}
						}
						printf("\n Your turn to attack! give him back what he deserves!");
						MAUS_lives = MAUS_lives - dmg_TANK(); 
						clear_screen();
					break;
					case 3:
						printf(YELLOW"\n The tank attempts to fire at you");
						decide_chance = rand() % 100;
						decide_chance = decide_chance - (i_armor_count*10); //idk jesti fachci - melo by zmensut sanci na hit
						if(decide_chance >30){
							printf(RED "\n The tank fires and the tank round hits you!"RESET);
							if(d_armor_count <1){ //no dia
								printf(RED "\n You lose %dhp"RESET, tank_attack_dmg);
								PLAYER_lives = PLAYER_lives - tank_attack_dmg;
							}
							else{ //dia
								printf(RED "\n You lose %dhp"RESET, tank_attack_dmg / 2);
								PLAYER_lives = PLAYER_lives - tank_attack_dmg / 2;
							}
						}
						else{
							printf("\n The tank missed");
						}

						printf(YELLOW "\n You use this chance to pray to BENJAMIN NETENYAHU" RESET);
						printf("\n.");
						Sleep(500);
						printf("\n.");
						Sleep(500);
						printf("\n.");
						Sleep(500);
						printf("\n.");
						Sleep(500);

						decide_chance = rand() % 100;
						if(decide_chance > 65){
							printf(GREEN "\n The jewish spirit within you blooms\n Healed 1 HP!" RESET); //hava nagila or sum shit
							PLAYER_lives++;
						}
						else{
							printf(RED "\n Nothing happends..." RESET);
						}
					break;
				}
				

			break;
		}


	} while(PLAYER_lives > 0); //main do while cycyle end
	printf("You died..."); //dodelat? - ztratit par goldu insted of exit?
	exit(0);
}

void samurai_fight(int *boss_hp, int *player_hp, int i_chestplate, int i_helmet, int i_leggings, int i_boots,
                   int d_chestplate, int d_helmet, int d_leggings, int d_boots, int d_sword, int i_sword) {
    int p_attack = 0;
    int damage = 0;
    int p_crit_chance = 0;
    int p_dodge_chance = 0;
    int b_crit_chance = 0;
    int b_dodge_chance = 0;
    int i_armor = 0;
    int d_armor = 0;

    if (i_helmet > 0)     i_armor += 1;
    if (i_chestplate > 0) i_armor += 1;
    if (i_leggings > 0)   i_armor += 1;
    if (i_boots > 0)      i_armor += 1;

    if (d_helmet > 0)     d_armor += 1;
    if (d_chestplate > 0) d_armor += 1;
    if (d_leggings > 0)   d_armor += 1;
    if (d_boots > 0)      d_armor += 1;

    printf(CYAN "Boss HP: %d | Your HP: %d\n" RESET, *boss_hp, *player_hp);
    printf(YELLOW " 1. ATTACK\n 0. QUIT\n" RESET);

    p_attack = input_int(0, 1);

    p_crit_chance  = rand() % 100;
    p_dodge_chance = rand() % 100;
    b_crit_chance  = rand() % 100;
    b_dodge_chance = rand() % 100;

    switch (p_attack) {
        case 1:
            damage = 1;
            if (d_sword > 0) {
                damage += 3;
            } else if (i_sword > 0) {
                damage += 1;
            }
            if (p_crit_chance <= 20) {
                damage *= 2;
                printf(GREEN "Critical Hit! You dealt %d damage.\n" RESET, damage);
            } else {
                printf(GREEN "You dealt %d damage.\n" RESET, damage);
            }
            *boss_hp -= damage;
            printf(RED "Boss HP: %d | Your HP: %d\n" RESET, *boss_hp, *player_hp);
            break;

        case 0:
         *boss_hp = 0;
            if (b_crit_chance <= 20) {
                damage = 10;
                *player_hp -= damage;
                printf(RED "Boss lands a hit while you try to escape! You took %d damage.\n" RESET, damage);
                return;
            } else if (b_crit_chance <= 60) {
                damage = 5;
                *player_hp -= damage;
                printf(RED "Boss lands a hit while you try to escape! You took %d damage.\n" RESET, damage);
                return;
            } else {
                damage = 0;
                printf(GREEN "Boss tried to hit you while you escaped but missed!\n" RESET);
                return;
            }
    }
    if (*player_hp <= 0) {
        printf(RED "\nYou were defeated by the samurai!\n" RESET);
        return;
        } 
        else if (*boss_hp <= 0) {
        printf(GREEN "\nYou defeated the samurai!\n" RESET);
        return;
        }

    printf(RED "Boss attacks!\n" RESET);
    printf(YELLOW "\n 1. Dodge\n 2. Block\n" RESET);
    p_attack = input_int(1, 2);

    switch (p_attack) {
        case 1:
            if (p_dodge_chance <= 30) {
                printf(GREEN "You successfully dodged the attack!\n" RESET);
            } else if (p_dodge_chance <= 60) {
                damage = 2;
                *player_hp -= damage;
                printf(RED "Dodge failed! You took %d damage.\n" RESET, damage);
            } else {
                damage = 5;
                *player_hp -= damage;
                printf(RED "Dodge failed completely! You took %d damage.\n" RESET, damage);
            }
            break;
        case 2:
            if (b_crit_chance <= 20) {
                damage = 2;
                *player_hp -= damage;
                printf(GREEN "You partially blocked the attack! Damage reduced to %d.\n" RESET, damage);
            } else {
                damage = 0;
                printf(GREEN "You successfully blocked the attack!\n" RESET);
            }
            break;
  
    }

}

void mage_fight(int *boss_hp, int *player_hp, int i_chestplate, int i_helmet, int i_leggings, int i_boots, int d_chestplate, int d_helmet, int d_leggings, int d_boots, int d_sword, int i_sword) {
    int p_attack = 0;
    int damage = 0;
    int p_crit_chance = 0;
    int p_dodge_chance = 0;
    int b_crit_chance = 0;
    int b_dodge_chance = 0;
    int i_armor = 0;
    int d_armor = 0;
    int attack = 0;
    int cycle = 0;
    int round = 0;
    int crystal1_hp = 30;
    int crystal2_hp = 30;
    int crystal3_hp = 30;

    if (i_helmet > 0)     i_armor += 1;
    if (i_chestplate > 0) i_armor += 1;
    if (i_leggings > 0)   i_armor += 1;
    if (i_boots > 0)      i_armor += 1;

    if (d_helmet > 0)     d_armor += 1;
    if (d_chestplate > 0) d_armor += 1;
    if (d_leggings > 0)   d_armor += 1;
    if (d_boots > 0)      d_armor += 1;

    



    int colour_1 = rand() % 3 + 1;
    int colour_2 = rand() % 3 + 1;
    int colour_3 = rand() % 3 + 1;

    char crystal_1 = (colour_1 == 1) ? 'R' : (colour_1 == 2) ? 'P' : 'B';
    char crystal_2 = (colour_2 == 1) ? 'R' : (colour_2 == 2) ? 'P' : 'B';
    char crystal_3 = (colour_3 == 1) ? 'R' : (colour_3 == 2) ? 'P' : 'B';

    char crystal[3] = {crystal_1, crystal_2, crystal_3};
    

    

    printf(CYAN "The mage used magic to block your attack!\n" RESET);
    printf(CYAN "The mage has casted his HP crystals, break his crystals to kill him!\n" RESET);
    printf(BLUE "If a crystal is blue, the mage casted an ice attack, you need to defend!\n" RESET);
    printf(RED "If a crystal is red, the mage casted a fire attack, you need to dodge!\n" RESET);
    printf(PURPLE "If a crystal is purple, the mage casted a shadow attack, you need to attack!\n" RESET);
    printf(YELLOW "Quick! Memorise the colours of the crystals!\n" RESET);

    printf(YELLOW "The crystals are:\n" RESET);
    colours(crystal[0]);
    colours(crystal[1]);
    colours(crystal[2]);
	printf ("\n");
	del_screen();

    while (*boss_hp > 0 && *player_hp > 0) {
        p_crit_chance = rand() % 100;
        b_crit_chance = rand() % 100; 

        if (*boss_hp <= 0) {
            printf(GREEN "\nYou defeated the great mage!\n" RESET);
            return;
        }
        
        if (round > 0 && round % 3 == 0) {
            crystal[0] = (rand() % 3 == 0) ? 'R' : (rand() % 2 == 0) ? 'P' : 'B';
            crystal[1] = (rand() % 3 == 0) ? 'R' : (rand() % 2 == 0) ? 'P' : 'B';
            crystal[2] = (rand() % 3 == 0) ? 'R' : (rand() % 2 == 0) ? 'P' : 'B';
			printf ("\n");
            colours(crystal[0]);
            colours(crystal[1]);
            colours(crystal[2]);
            printf ("\n");
            del_screen();
        }
        printf (CYAN"1. Attack\n0. Quit\n" RESET);
        p_attack = input_int(0, 1);
        switch (p_attack) {
        case 1:
            damage = 1;
            if (d_sword > 0) {
                damage += 3;
            } else if (i_sword > 0) {
                damage += 1;
            }
            if (p_crit_chance <= 20) {
                damage *= 2;
                printf(GREEN "Critical Hit! You dealt %d damage.\n" RESET, damage);
                } 
                else {
                printf(GREEN "You dealt %d damage.\n" RESET, damage);

            }
            printf(RED "Boss HP: %d | Your HP: %d\n" RESET, *boss_hp, *player_hp);
            if (crystal1_hp > 0) {
                crystal1_hp -= damage;
            }
            else if (crystal2_hp > 0) {
                crystal2_hp -= damage;
            }
            else if (crystal3_hp > 0) {
                crystal3_hp -= damage;
            }
           if (crystal1_hp <= 0 && crystal2_hp <= 0 && crystal3_hp <= 0) {
                *boss_hp = 0;
                printf(GREEN "\nYou defeated the mage!\n" RESET);
                return;
            }
            printf(RED"1. crystal HP: %d\n2. crystal HP: %d\n3. crystal HP: %d\n" RESET, crystal1_hp, crystal2_hp, crystal3_hp);
            break;

        case 0:
         *boss_hp = 0;
            if (b_crit_chance <= 20) {
                damage = 10;
                *player_hp -= damage;
                printf(RED "Boss lands a hit while you try to escape! You took %d damage.\n" RESET, damage);
                return;
            } else if (b_crit_chance <= 60) {
                damage = 5;
                *player_hp -= damage;
                printf(RED "Boss lands a hit while you try to escape! You took %d damage.\n" RESET, damage);
                return;
            } else {
                damage = 0;
                printf(GREEN "Boss tried to hit you while you escaped but missed!\n" RESET);
                return;
            }
    }
        printf(YELLOW "The mage is preparing his next attack!\n" RESET);
        printf(YELLOW" 1. ATTACK\n 2. DODGE\n 3. DEFEND\n" RESET);
        p_attack = input_int(1, 3);
        switch (p_attack) {
            // Blue - Defend, Red - Dodge, Purple - Attack
        case 1:
            if (crystal[cycle % 3] == 'P') {
                printf(GREEN "You successfully countered the shadow attack!\n" RESET);
            }
            else {
                damage = 2;
                *player_hp -= damage;
                printf(RED "Counter failed! You took %d damage.\n" RESET, damage);
            }
        break;

        case 2:
            if (crystal[cycle % 3] == 'R') {
                printf(GREEN "You successfully dodged the fire attack!\n" RESET);
            }
            else {
                damage = 2;
                *player_hp -= damage;
                printf(RED "Dodge failed! You took %d damage.\n" RESET, damage);
            }
        break;

        case 3:
            if (crystal[cycle % 3] == 'B') {
                printf(GREEN "You successfully defended the ice attack!\n" RESET);
            }
            else {
                damage = 2;
                *player_hp -= damage;
                printf(RED "Defend failed! You took %d damage.\n" RESET, damage);
            }
        break;
        }
        cycle++;
        round++;
        attack++;
    }
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
void assassin_fight(int *boss_hp, int *player_hp, int i_chestplate, int i_helmet, int i_leggings, int i_boots, int d_chestplate, int d_helmet, int d_leggings, int d_boots, int d_sword, int i_sword) {
    printf(CYAN "WIP - You are fighting against the assassin...\n" RESET);
}

//DATA SAVE
int getdatapls(int * no_of_TANKs_defeated, int * player_hp_fighting, int * leather, int * wool, int * wood, int * iron, int * diamonds, int * i_helmet, int * d_helmet, int * i_chestplate, int * d_chestplate, int * i_leggings, int * d_leggings, int * i_boots, int * d_boots, int * d_sword, int * i_sword, int * i_pickaxe, int * d_pickaxe, int * i_axe, int * d_axe){
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
				printf(" UNABLE TO OPEN SAVE (it prob. doesnt exit)");
				printf(" TRY AGAIN?\n 1. YES\n 2. NO (start new game)\n");
				int retry = input_int(1, 2);
				if(retry == 2){
					printf("\n DATA NOT LOADED, STARTING NEW GAME");
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
		*no_of_TANKs_defeated = atoi(s_data_save);
		fgets(s_data_save, sizeof(s_data_save), fptr_fce);
		*player_hp_fighting = atoi(s_data_save);
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
	int no_of_TANKs_defeated = 0;

	srand(time(NULL));
	SetConsoleOutputCP(65001); //nastaveni UTF-8 pro windows, aby se zobrazovaly tyhle hezký kostičky :D (holy shit tohle napsalo vs za me)
	FILE *fptr; //pointer do save (POINTERRRRRR)
	//boss
	int volba_menu = 0;
	int volba_boss = 0;
	int boss_hp = 100;
	int player_hp = 100;
	int running = 1; 

	//zavolani fce, ulozeni v main, v deklaraci fce, fgets, printf v inv - 5 veci kde pridat do save
	getdatapls(&no_of_TANKs_defeated, &player_hp_fighting, &leather, &wool, &wood, &iron, &diamonds, &i_helmet, &d_helmet, &i_chestplate, &d_chestplate, &i_leggings, &d_leggings, &i_boots, &d_boots, &d_sword, &i_sword, &i_pickaxe, &d_pickaxe, &i_axe, &d_axe);

	while (1) {
		i_armor_count = i_helmet + i_chestplate + i_leggings + i_boots;
		d_armor_count = d_helmet + d_chestplate + d_leggings + d_boots;
		menu();
		volim = input_int(0, 5);

		switch (volim) {
		case 0:
			printf(RED " \nSAVE 'N QUIT?\n" RESET);
			printf(YELLOW " 1. SAVE\n 2. DONT SAVE\n 3. BACK" RESET);
			valid = input_int(1, 3);
			if (valid == 1) {
				char voleni_file_jmeno[30];
				input_string(voleni_file_jmeno, sizeof(voleni_file_jmeno), " CHOOSE FILE NAME: ");
				char voleni_file_jmeno_tricetpet[35];
				strcpy(voleni_file_jmeno_tricetpet, voleni_file_jmeno);
				strcat(voleni_file_jmeno_tricetpet, ".txt");
				fptr = fopen(voleni_file_jmeno_tricetpet, "w");
				fprintf(fptr, " %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",no_of_TANKs_defeated, player_hp_fighting, leather, wool, wood, iron, diamonds, i_helmet, d_helmet, i_chestplate, d_chestplate, i_leggings, d_leggings, i_boots, d_boots, d_sword, i_sword, i_pickaxe, d_pickaxe, i_axe, d_axe);
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
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 5 && i_helmet != 1) {
						printf(GREEN "IRON HELMET CRAFTED. WELL DONE!" RESET);
						i_helmet = 1;
						iron -= 5;
						printf(YELLOW " YOU HAVE %d IRON\n" RESET, iron);
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
						printf(YELLOW " YOU HAVE %d DIAMONDS\n" RESET, diamonds);
						i_helmet = 0;
					}
					else {
						printf(RED "DIAMOND HELMET COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 2: // chestplate
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 8 && i_chestplate != 1) {
						printf(GREEN "IRON CHESTPLATE CRAFTED. WELL DONE!" RESET);
						i_chestplate = 1;
						iron -= 8;
						printf(YELLOW " YOU HAVE %d IRON\n" RESET, iron);
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
						printf(YELLOW " YOU HAVE %d DIAMONDS\n" RESET, diamonds);
						i_chestplate = 0;
					}
					else {
						printf(RED "DIAMOND CHESTPLATE COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 3: // leggings
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 7 && i_leggings != 1) {
						printf(GREEN "IRON LEGGINGS CRAFTED. WELL DONE!" RESET);
						i_leggings = 1;
						iron -= 7;
						printf(YELLOW " YOU HAVE %d IRON\n" RESET, iron);
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
						printf(YELLOW " YOU HAVE %d DIAMONDS\n" RESET, diamonds);
						i_leggings = 0;
					}
					else {
						printf(RED "DIAMOND LEGGINGS COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 4: // boots
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 4 && i_boots != 1) {
						printf(GREEN "IRON BOOTS CRAFTED. WELL DONE!" RESET);
						i_boots = 1;
						iron -= 4;
						printf(YELLOW " YOU HAVE %d IRON\n" RESET, iron);
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
						printf(YELLOW " YOU HAVE %d DIAMONDS\n" RESET, diamonds);
						i_boots = 0;
					}
					else {
						printf(RED "DIAMOND BOOTS COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 5: // sword
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 2 && i_sword != 1 && wood >= 2) {
						printf(GREEN "IRON SWORD CRAFTED. WELL DONE!" RESET);
						i_sword = 1;
						iron -= 2;
						wood -= 2;
						printf(YELLOW " YOU HAVE %d IRON\n" RESET, iron);
						printf(YELLOW " YOU HAVE %d WOOD\n" RESET, wood);
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
						printf(YELLOW " YOU HAVE %d DIAMONDS\n" RESET, diamonds);
						printf(YELLOW " YOU HAVE %d WOOD\n" RESET, wood);
						i_sword = 0;
					}
					else {
						printf(RED "DIAMOND SWORD COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 6: // pickaxe
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 3 && i_pickaxe != 1 && wood >= 2) {
						printf(GREEN "IRON PICKAXE CRAFTED. WELL DONE!" RESET);
						i_pickaxe = 1;
						iron -= 3;
						printf(YELLOW " YOU HAVE %d IRON\n" RESET, iron);
						wood -= 2;
						printf(YELLOW " YOU HAVE %d WOOD\n" RESET, wood);
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
						printf(YELLOW " YOU HAVE %d DIAMONDS\n" RESET, diamonds);
						printf(YELLOW " YOU HAVE %d WOOD\n" RESET, wood);
						i_pickaxe = 0;
					}
					else {
						printf(RED "DIAMOND PICKAXE COULDN'T BE CRAFTED..." RESET);
					}
				}
				break;

			case 7: // axe
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back" RESET);
				control = 0;
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
					if (iron >= 3 && i_axe != 1 && wood >= 2) {
						printf(GREEN "IRON AXE CRAFTED. WELL DONE!" RESET);
						i_axe = 1;
						iron -= 3;
						wood -= 2;
						printf(YELLOW " YOU HAVE %d IRON\n" RESET, iron);
						printf(YELLOW " YOU HAVE %d WOOD\n" RESET, wood);
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
						printf(YELLOW " YOU HAVE %d DIAMONDS\n" RESET, diamonds);
						printf(YELLOW " YOU HAVE %d WOOD\n" RESET, wood);
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
					printf(YELLOW " YOU HAVE %d LEATHER\n" RESET, leather);
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
        case 1:
			menu_boss();
			volba_boss = input_int(0, 5);

			switch (volba_boss) {
				case 0:
				break;

				case 1: // samurai
					boss_hp = 100;
					player_hp = 100;
					printf(CYAN "You are fighting against the samurai...\n" RESET);
					while (boss_hp > 0 && player_hp > 0) {
						samurai_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots,d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword);
						
					}
				break;

				case 2: // mage
					boss_hp = 10;
					player_hp = 100;
					while (boss_hp > 0 && player_hp > 0) {
						mage_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots, d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword);
						if (player_hp <= 0) {
							printf(RED "\nYou were defeated by the mage!\n" RESET);
								break;
						}
							
						} 
					
				break;

				case 3: // tank
					int pakvyl = tank_fight(i_armor_count, d_armor_count); //raise defeat counter
					if(pakvyl == 0){
						no_of_TANKs_defeated++;
					}
				break;
				case 4: // assassin
					boss_hp = 100;
					player_hp = 100;
					while (boss_hp > 0 && player_hp > 0) {
						assassin_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots,
										d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword);
						if (player_hp <= 0) {
							printf(RED "\nYou were defeated by the assassin!\n" RESET);
							break;
						} else if (boss_hp <= 0) {
							printf(GREEN "\nYou defeated the assassin!\n" RESET);
							break;
						}
					}
				break;

				case 5:  // random
					int random_boss = rand() % 4;
					random_boss++;
					boss_hp = 100;
					player_hp = 100;
					switch (random_boss) {
						case 1:
							printf(CYAN "You are fighting against the samurai...\n" RESET);
							while (boss_hp > 0 && player_hp > 0) {
								samurai_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots,d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword);
								if (player_hp <= 0) { printf(RED "\nYou were defeated by the samurai!\n" RESET); break; }
								else if (boss_hp <= 0) { printf(GREEN "\nYou defeated the samurai!\n" RESET); break; }
							}
							break;
						case 2:
							while (boss_hp > 0 && player_hp > 0) {
								mage_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots,
											d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword);
								if (player_hp <= 0) { printf(RED "\nYou were defeated by the mage!\n" RESET); break; }
								else if (boss_hp <= 0) { printf(GREEN "\nYou defeated the mage!\n" RESET); break; }
							}
							break;
						case 3:
							tank_fight(i_armor_count, d_armor_count);
						case 4:
							while (boss_hp > 0 && player_hp > 0) {

								printf("WIP...");
								break;

								assassin_fight(&boss_hp, &player_hp, i_chestplate, i_helmet, i_leggings, i_boots,
												d_chestplate, d_helmet, d_leggings, d_boots, d_sword, i_sword);
								if (player_hp <= 0) { printf(RED "\nYou were defeated by the assassin!\n" RESET); break; }
								else if (boss_hp <= 0) { printf(GREEN "\nYou defeated the assassin!\n" RESET); break; }
							}
							break;
					}
				break;
				
			} //end switch
		break; //break case 1 bossove

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
			printf(RED    " Health:           %d/10\n" RESET, player_hp_fighting);
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
			printf(GRAY	" iron helmet:        %d\n" RESET, i_helmet);
			printf(CYAN " diamond chestplate: %d\n" RESET, d_chestplate);
			printf(GRAY " iron chestplate:    %d\n" RESET, i_chestplate);
			printf(CYAN " diamond leggings:   %d\n" RESET, d_leggings);
			printf(GRAY " iron leggings:      %d\n" RESET, i_leggings);
			printf(CYAN " diamond boots:      %d\n" RESET, d_boots);
			printf(GRAY " iron boots:         %d\n" RESET, i_boots);

			printf(BOLD YELLOW " TANKS DEFEATED:         %d\n" RESET, no_of_TANKs_defeated);
		break;
		case 5: //eat
			heal_player(&player_hp_fighting);
		break;
		}
	}

	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

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
int input_int(int min, int max){
    int tmp = 0;
    while(1){
        printf(YELLOW" CHOOSE: " RESET);
        int control = scanf("%d", &tmp);
        clean_buffer();
        if(control == 0 || tmp <min || tmp >max){
            printf(BOLD YELLOW "##failed to load number##\n" RESET);
            continue;
        }
        else{
            return tmp;
        }
    }
}


void clear (){
	for ( int i = 0; i <= 20; i ++){
		printf ("\n");
	}
}
void pause (){
	printf (YELLOW "\nPress ENTER to continue..." RESET);
	getchar();
}

void menu() {
	printf(BOLD CYAN "\n=== ADVENTURE ===\n" RESET);
	printf(YELLOW " 1. CRAFT\n 2. MINE\n 3. FIGHT\n 4. INVENTORY\n 0. LEAVE\n" RESET);
}

void menu_mine() {
	clear();
	printf(BOLD CYAN "\n===MINING MENU===\n" RESET);
	printf(YELLOW " 1. MINING WOOD\n 2. MINING IRON\n 3. MINING DIAMONDS\n 0. BACK\n" RESET);
}

void menu_boss(){
	printf ("=== BOSS FIGHT MENU === \n");
	printf (" 1. LEVEL - 1\n 2. LEVEL - 2\n 3. LEVEL - 3\n 4. LEVEL - 4\n 5. RANDOM LEVEL\n 0. BACK \n");
}

int wood_mine (int chance_wood, int wood) {
	chance_wood = rand () % 100;
	if (chance_wood <= 20) {
		wood += 3;
		printf(GREEN "Jackpot! You mined 3 logs!" RESET);
		pause();
		clear();
	}
	else if (chance_wood > 20 && chance_wood <= 50) {
		wood += 2;
		printf(GREEN "Congratulations! You mined 2 logs" RESET);
		pause();
		clear();
	}
	else if (chance_wood > 50 && chance_wood <= 100) {
		if (wood == 0) {
			wood += 2;
			printf(GREEN "Congratulations! You mined 2 logs" RESET);
			pause();
		clear();
		}
		else {
			wood += 1;
			printf(YELLOW "You got 1 log" RESET);
			pause();
		clear();
		}
	}
	return wood;
}

int iron_mine (int chance, int material) {
	chance = rand () % 100;
	if (chance <= 20) {
		material += 2;
		printf(GREEN "Jackpot! You found 2 iron" RESET);
		pause();
		clear();
	}
	else if (chance > 20 && chance <= 50) {
		material += 1;
		printf(YELLOW "You got 1 iron" RESET);
		pause();
		clear();
	}
	else if (chance > 50 && chance <= 100) {
		material += 0;
		printf(RED "You got unlucky... 0 iron" RESET);
		pause();
		clear();
	}
	return material;
}

int diamond_mine (int chance, int material) {
	chance = rand () % 100;
	if (chance <= 20) {
		material += 1;
		printf(GREEN "Jackpot! You found a diamond!" RESET);
		pause();
		clear();
	}
	else if (chance > 20 && chance <= 50) {
		material += 0;
		printf(YELLOW "No Diamonds, just some stone... you should try again :)" RESET);
		pause();
		clear();
	}
	else if (chance > 50 && chance <= 100) {
		material += 0;
		printf(RED "You got unlucky... you should give it one more shot!" RESET);
		pause();
		clear();
	}
	return material;
}

void menu_craft() {
	clear();
	printf(BOLD CYAN "\n=== CRAFTING MENU ===\n" RESET);
	printf(YELLOW " 1. HELMET\n 2. CHESTPLATE\n 3. LEGGINGS\n 4. BOOTS\n 5. SWORD\n 6. PICKAXE\n 7. AXE\n 8. BACKPACK\n 0. BACK\n" RESET);
}

void menu_fighting() {
	clear();
	printf(BOLD CYAN "\n=== FIGHTING MENU ===\n" RESET);
	printf(YELLOW " 1. BOSS FIGHT\n 2. ADVENTURE\n 0. BACK\n" RESET);
}

int main()
{
	int boss_fight_volba = 0;
	int volba = 0;
	int size = 10;
	char inventory [size];
	int control = 0;
	int chance_mine = 0;
	int volba_mine = 0;
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
	int boss_attack = 0;
	int boss_hp = 100;
	int player_hp_fighting = 20;
	int player_attack = 0; // 1-2-3
	int boss_loop = 0; 
	int damage = 0;
	int armor = 0;

	srand(time(NULL));

	while (1) {
		menu();
		volba = input_int(0, 4);

		switch (volba) {
		case 0:
			printf(RED "ENDING THE GAME..." RESET);
			return 0;

		case 1: // crafting
			menu_craft();
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
						pause();
						clear();
				    }
				    else {
				        printf(RED "IRON HELMET COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 5 && d_helmet != 1) {
				        printf(GREEN "DIAMOND HELMET CRAFTED. WELL DONE!" RESET);
				        d_helmet = 1;
				        diamonds -= 5;
				        printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						pause();
						clear();
				    }
				    else {
				        printf(RED "DIAMOND HELMET COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
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
						pause();
						clear();
				    }
				    else {
				        printf(RED "IRON CHESTPLATE COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 8 && d_chestplate != 1) {
				        printf(GREEN "DIAMOND CHESTPLATE CRAFTED. WELL DONE!" RESET);
				        d_chestplate = 1;
				        diamonds -= 8;
				        printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						pause();
						clear();
				    }
				    else {
				        printf(RED "DIAMOND CHESTPLATE COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
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
						pause();
						clear();
				    }
				    else {
				        printf(RED "IRON LEGGINGS COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 7 && d_leggings != 1) {
				        printf(GREEN "DIAMOND LEGGINGS CRAFTED. WELL DONE!" RESET);
				        d_leggings = 1;
				        diamonds -= 7;
				        printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						pause();
						clear();
				    }
				    else {
				        printf(RED "DIAMOND LEGGINGS COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
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
						pause();
						clear();
				    }
				    else {
				        printf(RED "IRON BOOTS COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 4 && d_boots != 1) {
				        printf(GREEN "DIAMOND BOOTS CRAFTED. WELL DONE!" RESET);
				        d_boots = 1;
				        diamonds -= 4;
				        printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						pause();
						clear();
				    }
				    else {
				        printf(RED "DIAMOND BOOTS COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				break;

			case 5: // sword
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 2 && i_sword != 1 && wood >= 1) {
				        printf(GREEN "IRON SWORD CRAFTED. WELL DONE!" RESET);
				        i_sword = 1;
				        iron -= 2;
				        printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
						pause();
						clear();
				    }
				    else {
				        printf(RED "IRON SWORD COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 2 && d_sword != 1 && wood >= 1) {
				        printf(GREEN "DIAMOND SWORD CRAFTED. WELL DONE!" RESET);
				        d_sword = 1;
				        diamonds -= 2;
				        printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						pause();
						clear();
				    }
				    else {
				        printf(RED "DIAMOND SWORD COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
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
						pause();
						clear();
				    }
				    else {
				        printf(RED "IRON PICKAXE COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 3 && d_pickaxe != 1 && wood >= 2) {
				        printf(GREEN "DIAMOND PICKAXE CRAFTED. WELL DONE!" RESET);
				        d_pickaxe = 1;
				        diamonds -= 3;
				        printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						pause();
						clear();
				    }
				    else {
				        printf(RED "DIAMOND PICKAXE COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				break;

			case 7: // axe
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				control = 0;
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 3 && i_axe != 1) {
				        printf(GREEN "IRON AXE CRAFTED. WELL DONE!" RESET);
				        i_axe = 1;
				        iron -= 3;
				        printf(YELLOW " YOU HAVE %d IRON" RESET, iron);
						pause();
						clear();
				    }
				    else {
				        printf(RED "IRON AXE COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 3 && d_axe != 1) {
				        printf(GREEN "DIAMOND AXE CRAFTED. WELL DONE!" RESET);
				        d_axe = 1;
				        diamonds -= 3;
				        printf(YELLOW " YOU HAVE %d DIAMONDS" RESET, diamonds);
						pause();
						clear();
				    }
				    else {
				        printf(RED "DIAMOND AXE COULDN'T BE CRAFTED..." RESET);
						pause();
						clear();
				    }
				}
				break;

			case 8: // backpack
				if (leather >= 5 && backpack != 1) {
					printf(GREEN "BACKPACK CRAFTED... + 10 INVENTORY SPACE\n" RESET);
					backpack = 1;
					leather -= 5;
					printf(YELLOW " YOU HAVE %d LEATHER" RESET, leather);
					pause();
					clear();
				}
				else if (backpack == 1) {
					printf(RED "You already have a backpack!\n" RESET);
					pause();
					clear();
				}
				else {
					printf(RED "BACKPACK COULDN'T BE CRAFTED... Not enough leather! Need 5.\n" RESET);
					pause();
					clear();
				}
				break;

			case 0: // back
			pause();
			clear();
				break;
			}
			break;

		case 2: // mining
			menu_mine();
			volba_mine = input_int(0, 3);

			switch (volba_mine) {
			case 1:
				wood = wood_mine(chance_mine, wood);
				printf(YELLOW "\nYou have %d logs\n" RESET, wood);
				pause();
				clear();
				break;

			case 2:
				iron = iron_mine(chance_mine, iron);
				printf(YELLOW "\nYou have %d iron\n" RESET, iron);
				pause();
				clear();
				break;

			case 3:
				diamonds = diamond_mine(chance_mine, diamonds);
				printf(YELLOW "\nYou have %d diamonds\n" RESET, diamonds);
				pause();
				clear();
				break;

			case 0:
			pause();
		clear();
				break;
			}
			break;

		case 3: // fighting
            menu_fighting();
            volba_fight = input_int(0, 2);

            switch (volba_fight) {
            case 0:
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
                    case 1: // samurai
                    break;
					case 2: // mage
					break;
					case 3: // tank
					break;
					case 4: // assassin
					break;
					case 5: // random
					break;
					}
                } 
                break; 

            case 2: // adventure
                printf(CYAN "stehlikovo part ...\n" RESET);
                pause(); 
                clear();
                break;
            }
            break;

		case 4:
			printf(BOLD CYAN "\n=== INVENTORY ===\n" RESET);
			printf(YELLOW " Logs:     %d\n" RESET, wood);
			printf(YELLOW " Iron:     %d\n" RESET, iron);
			printf(YELLOW " Diamonds: %d\n" RESET, diamonds);
			printf(YELLOW " Leather:  %d\n" RESET, leather);
			pause();
			clear();
			break;
		}
	}

	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
/*#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif*/
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"


/*void enable_ansi() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}*/

void clear_screen() {
    clear_screen();
    enable_ansi();
}

// INPUT
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

void press_to_continue() {
    printf(YELLOW "\nPress ENTER to continue..." RESET);
    getchar(); // Wait for user input
}

// MENU
void menu_craft() {
	printf(BOLD CYAN "\n=== CRAFTING MENU ===\n" RESET);
	printf(YELLOW " 1. HELMET\n 2. CHESTPLATE\n 3. LEGGINGS\n 4. BOOTS\n 5. SWORD\n 6. PICKAXE\n 7. AXE\n 8. BACKPACK\n 0. BACK\n" RESET);
}

void menu_fighting() {
	printf(BOLD CYAN "\n=== FIGHTING MENU ===\n" RESET);
	printf(YELLOW " 1. BOSS FIGHT\n 2. ADVENTURE\n 0. BACK\n" RESET);
}

void menu() {
	printf(BOLD CYAN "\n=== ADVENTURE ===\n" RESET);
	printf(YELLOW " 1. CRAFT\n 2. MINE\n 3. FIGHT\n 4. INVENTORY\n 0. LEAVE\n" RESET);
}

void menu_mine() {
	printf(BOLD CYAN "\n===MINING MENU===\n" RESET);
	printf(YELLOW " 1. MINING WOOD\n 2. MINING IRON\n 3. MINING DIAMONDS\n 0. BACK\n" RESET);
}
// GAME LOGIC
int wood_mine (int chance_wood, int wood) {
	chance_wood = rand () % 100;
	if (chance_wood <= 20) {
		wood += 3;
		printf(GREEN "\nJackpot! You mined 3 logs!\n" RESET);
	}
	else if (chance_wood > 20 && chance_wood <= 50) {
		wood += 2;
		printf(GREEN "\nCongratulations! You mined 2 logs\n" RESET);
	}
	else if (chance_wood > 50 && chance_wood <= 100) {
		if (wood == 0) {
			wood += 2;
			printf(GREEN "\nCongratulations! You mined 2 logs\n" RESET);
		}
		else {
			wood += 1;
			printf(YELLOW "\nYou got 1 log\n" RESET);
		}
	}
	return wood;
}

int iron_mine (int chance, int material) {
	chance = rand () % 100;
	if (chance <= 20) {
		material += 2;
		printf(GREEN "\nJackpot! You found 2 iron\n" RESET);
	}
	else if (chance > 20 && chance <= 50) {
		material += 1;
		printf(YELLOW "\nYou got 1 iron\n" RESET);
	}
	else if (chance > 50 && chance <= 100) {
		material += 0;
		printf(RED "\nYou got unlucky... 0 iron\n" RESET);
	}
	return material;
}

int diamond_mine (int chance, int material) {
	chance = rand () % 100;
	if (chance <= 20) {
		material += 1;
		printf(GREEN "\nJackpot! You found a diamond!\n" RESET);
	}
	else if (chance > 20 && chance <= 50) {
		material += 0;
		printf(YELLOW "\nNo Diamonds, just some stone... you should try again :)\n" RESET);
	}
	else if (chance > 50 && chance <= 100) {
		material += 0;
		printf(RED "\nYou got unlucky... you should give it one more shot!\n" RESET);
	}
	return material;
}


// MAIN
int main()
{
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

	srand(time(NULL));
	enable_ansi();

	while (1) {
		system(CLEAR);
		menu();
		volba = input_int(0, 4);

		switch (volba) {
		case 0:
			printf(RED "ENDING THE GAME..." RESET);
			return 0;

		case 1: // crafting
			system(CLEAR);
			menu_craft();
			volba_craft = input_int(0, 8);
			system(CLEAR);
			switch (volba_craft) {

			case 1: // helmet
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 5 && i_helmet != 1) {
				        printf(GREEN "\nIRON HELMET CRAFTED. WELL DONE!\n" RESET);
				        i_helmet = 1;
				        iron -= 5;
				        printf(YELLOW "\n YOU HAVE %d IRON\n" RESET, iron);
				    }
				    else {
				        printf(RED "\nIRON HELMET COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 5 && d_helmet != 1) {
				        printf(GREEN "\nDIAMOND HELMET CRAFTED. WELL DONE!\n\n" RESET);
				        d_helmet = 1;
				        diamonds -= 5;
				        printf(YELLOW "\n YOU HAVE %d DIAMONDS\n" RESET, diamonds);
				    }
				    else {
				        printf(RED "DIAMOND HELMET COULDN'T BE CRAFTED..." RESET);
				    }
				}
				press_to_continue();
				break;

			case 2: // chestplate
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 8 && i_chestplate != 1) {
				        printf(GREEN "\nIRON CHESTPLATE CRAFTED. WELL DONE\n" RESET);
				        i_chestplate = 1;
				        iron -= 8;
				        printf(YELLOW "\n YOU HAVE %d IRON\n" RESET, iron);
				    }
				    else {
				        printf(RED "\nIRON CHESTPLATE COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 8 && d_chestplate != 1) {
				        printf(GREEN "\nDIAMOND CHESTPLATE CRAFTED. WELL DONE!\n" RESET);
				        d_chestplate = 1;
				        diamonds -= 8;
				        printf(YELLOW "\n YOU HAVE %d DIAMONDS\n" RESET, diamonds);
				    }
				    else {
				        printf(RED "\nDIAMOND CHESTPLATE COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				press_to_continue();
				break;

			case 3: // leggings
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 7 && i_leggings != 1) {
				        printf(GREEN "\nIRON LEGGINGS CRAFTED. WELL DONE!\n" RESET);
				        i_leggings = 1;
				        iron -= 7;
				        printf(YELLOW "\n YOU HAVE %d IRON\n" RESET, iron);
				    }
				    else {
				        printf(RED "\nIRON LEGGINGS COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 7 && d_leggings != 1) {
				        printf(GREEN "\nDIAMOND LEGGINGS CRAFTED. WELL DONE!\n" RESET);
				        d_leggings = 1;
				        diamonds -= 7;
				        printf(YELLOW "\n YOU HAVE %d DIAMONDS\n" RESET, diamonds);
				    }
				    else {
				        printf(RED "\nDIAMOND LEGGINGS COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				press_to_continue();
				break;

			case 4: // boots
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 4 && i_boots != 1) {
				        printf(GREEN "\nIRON BOOTS CRAFTED. WELL DONE!\n" RESET);
				        i_boots = 1;
				        iron -= 4;
				        printf(YELLOW "\n YOU HAVE %d IRON\n" RESET, iron);
				    }
				    else {
				        printf(RED "\nIRON BOOTS COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 4 && d_boots != 1) {
				        printf(GREEN "\nDIAMOND BOOTS CRAFTED. WELL DONE!\n" RESET);
				        d_boots = 1;
				        diamonds -= 4;
				        printf(YELLOW "\n YOU HAVE %d DIAMONDS\n" RESET, diamonds);
				    }
				    else {
				        printf(RED "\nDIAMOND BOOTS COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				press_to_continue();
				break;

			case 5: // sword
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 2 && i_sword != 1 && wood >= 1) {
				        printf(GREEN "\nIRON SWORD CRAFTED. WELL DONE!\n" RESET);
				        i_sword = 1;
				        iron -= 2;
				        printf(YELLOW "\n YOU HAVE %d IRON\n" RESET, iron);
				    }
				    else {
				        printf(RED "\nIRON SWORD COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 2 && d_sword != 1 && wood >= 1) {
				        printf(GREEN "\nDIAMOND SWORD CRAFTED. WELL DONE!\n" RESET);
				        d_sword = 1;
				        diamonds -= 2;
				        printf(YELLOW "\n YOU HAVE %d DIAMONDS\n" RESET, diamonds);
				    }
				    else {
				        printf(RED "\nDIAMOND SWORD COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				press_to_continue();
				break;

			case 6: // pickaxe
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 3 && i_pickaxe != 1 && wood >= 2) {
				        printf(GREEN "\nIRON PICKAXE CRAFTED. WELL DONE!\n" RESET);
				        i_pickaxe = 1;
				        iron -= 3;
				        printf(YELLOW "\n YOU HAVE %d IRON\n" RESET, iron);
				    }
				    else {
				        printf(RED "\nIRON PICKAXE COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 3 && d_pickaxe != 1 && wood >= 2) {
				        printf(GREEN "\nDIAMOND PICKAXE CRAFTED. WELL DONE!\n" RESET);
				        d_pickaxe = 1;
				        diamonds -= 3;
				        printf(YELLOW "\n YOU HAVE %d DIAMONDS\n" RESET, diamonds);
				    }
				    else {
				        printf(RED "\nDIAMOND PICKAXE COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				press_to_continue();
				break;

			case 7: // axe
				printf(YELLOW "\n 1. Iron\n 2. Diamond\n 0. Back\n" RESET);
				control = 0;
				crafting_mat_volba = input_int(0, 2);
				if (crafting_mat_volba == 1) {
				    if (iron >= 3 && i_axe != 1) {
				        printf(GREEN "\nIRON AXE CRAFTED. WELL DONE\n!" RESET);
				        i_axe = 1;
				        iron -= 3;
				        printf(YELLOW "\n YOU HAVE %d IRON\n" RESET, iron);
				    }
				    else {
				        printf(RED "\nIRON AXE COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				else if (crafting_mat_volba == 2) {
				    if (diamonds >= 3 && d_axe != 1) {
				        printf(GREEN "\nDIAMOND AXE CRAFTED. WELL DONE!\n" RESET);
				        d_axe = 1;
				        diamonds -= 3;
				        printf(YELLOW "\n YOU HAVE %d DIAMONDS\n" RESET, diamonds);
				    }
				    else {
				        printf(RED "\nDIAMOND AXE COULDN'T BE CRAFTED...\n" RESET);
				    }
				}
				press_to_continue();
				break;

			case 8: // backpack
				if (leather >= 5 && backpack != 1) {
					printf(GREEN "\nBACKPACK CRAFTED... + 10 INVENTORY SPACE\n" RESET);
					backpack = 1;
				}
				else if (backpack == 1) {
					printf(RED "\nYou already have a backpack!\n" RESET);
				}
				else {
					printf(RED "\nBACKPACK COULDN'T BE CRAFTED... Not enough leather! Need 5.\n" RESET);
				}
				press_to_continue();
				break;

			case 0: // back
				break;
			}
			break;

		case 2: // mining
			system(CLEAR);
			menu_mine();
			volba_mine = input_int(0, 3);
			system(CLEAR);

			switch (volba_mine) {
			case 1:
				wood = wood_mine(chance_mine, wood);
				printf(YELLOW "\nYou have %d logs\n" RESET, wood);
				press_to_continue();
				break;

			case 2:
				iron = iron_mine(chance_mine, iron);
				printf(YELLOW "\nYou have %d iron\n" RESET, iron);
				press_to_continue();
				break;

			case 3:
				diamonds = diamond_mine(chance_mine, diamonds);
				printf(YELLOW "\nYou have %d diamonds\n" RESET, diamonds);
				press_to_continue();
				break;

			case 0:
				break;
			}
			break;

		case 3: // fighting
			system(CLEAR);
			menu_fighting();
			volba_fight = input_int(0, 2);
			system(CLEAR);

			switch (volba_fight) {
			case 0:
				break;
			case 1: // boss fight
				press_to_continue();
				break;
			case 2: // adventure
				press_to_continue();
				break;
			}
			break;

		case 4: // inventory
			system(CLEAR);
			printf(BOLD CYAN "\n=== INVENTORY ===\n" RESET);
			printf(YELLOW " Logs:     %d\n" RESET, wood);
			printf(YELLOW " Iron:     %d\n" RESET, iron);
			printf(YELLOW " Diamonds: %d\n" RESET, diamonds);
			printf(YELLOW " Leather:  %d\n" RESET, leather);
			press_to_continue();
			break;
		}
	}

	return 0;
}
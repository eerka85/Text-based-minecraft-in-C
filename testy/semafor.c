#include <stdio.h>

// 1. Definice stavů pomocí ENUM
typedef enum {
    CERVENA,
    CERVENO_ZLUTA,
    ZELENA,
    ZLUTA
} TypStavu;

int main() {
    // Inicializace
    TypStavu aktualniStav = CERVENA;
    int casV_Sekundach = 0;

    printf("--- SIMULACE SEMAFORU SPUSTENA ---\n");

    // Nekonečná smyčka (v embedded standard)
    while (1) {
        
        // 2. Logika výstupů (Co se děje v daném stavu)
        switch (aktualniStav) {
            case CERVENA:
                printf("[ STOP ] Cervena sviti... (%d s)\n", casV_Sekundach);
                break;
            case CERVENO_ZLUTA:
                printf("[ POZOR ] Cervena a zluta sviti... (%d s)\n", casV_Sekundach);
                break;
            case ZELENA:
                printf("[ JED   ] Zelena sviti... (%d s)\n", casV_Sekundach);
                break;
            case ZLUTA:
                printf("[ BRZDI ] Zluta sviti... (%d s)\n", casV_Sekundach);
                break;
        }

        // 3. Logika přechodů (Kdy se stav změní)
        casV_Sekundach++;

        if (aktualniStav == CERVENA && casV_Sekundach >= 5) {
            aktualniStav = CERVENO_ZLUTA;
            casV_Sekundach = 0; // Vynulovat čas pro nový stav
        } 
        else if (aktualniStav == CERVENO_ZLUTA && casV_Sekundach >= 2) {
            aktualniStav = ZELENA;
            casV_Sekundach = 0;
        } 
        else if (aktualniStav == ZELENA && casV_Sekundach >= 5) {
            aktualniStav = ZLUTA;
            casV_Sekundach = 0;
        } 
        else if (aktualniStav == ZLUTA && casV_Sekundach >= 2) {
            aktualniStav = CERVENA;
            casV_Sekundach = 0;
        }

        // Simulace reálného času (v reálném embedded by to byl HW timer)
        // Pro účely testu v konzoli zastavíme program po 20 sekundách
        if (casV_Sekundach > 20) break; 
        
        // Malá pauza, aby se text v konzoli dal číst (není to profi, ale pro test stačí)
        for(volatile int i = 0; i < 100000000; i++); 
    }

    return 0;
}
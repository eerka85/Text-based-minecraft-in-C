#include <stdio.h>


int fce_z_hlavni_veci(){
    return 67;
}

#include "moje_fc.h" //musi byt tady a ne na radku 2

int main(){
    int promena_v_hlavni_veci = 0;
    printf("%d\n", promena_v_hlavni_veci);
    uz_mi_hrabe(&promena_v_hlavni_veci);
    printf("%d\n", promena_v_hlavni_veci);
    getchar();
}

/* Converting constants to scientific notation */
#include <stdio.h>
#include <math.h>

#define LIGHT_SPEED 2.99792  
#define CHARGE_OF_AN_ELECTRON 1.602177
#define AVOGADRO_NUMBER 6.022
#define ACCELERATION_IN_METRES_PER_SECONDS 9.8 
#define ACCELERATION_IN_FEETS_PER_SECONDS 32
#define MASS_OF_THE_EARTH 5.98
#define RADIUS_OF_THE_MOON 1.74
#define UNIT_LENGTH 'm'
#define UNIT_TIME 's'

int main(void){

    printf("Charge of an electron: %e \n",LIGHT_SPEED+ UNIT_TIME);
    printf("Speed of Light: %g\n" , LIGHT_SPEED);
    printf("%e %c/%c\n", ACCELERATION_IN_METRES_PER_SECONDS, UNIT_LENGTH, UNIT_TIME);
    


}
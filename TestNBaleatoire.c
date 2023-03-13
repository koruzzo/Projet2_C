/*//////////////////////////////////////////////////////////////////*/
/* La fonction "ValeurAleatoire" qui récupère un nombre du mersenne */
/*      twister, le modifie si besoin, le transforme en int et      */
/*                          le retourne                             */
/*//////////////////////////////////////////////////////////////////*/



/*    DEBUT DU CODE    */

/*Déclarations des librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Implémentation du code contenant le mersenne twister afin d'avoir un nombre aléatoire*/
#include "MT.c"



int main(){

int NBMAX =-1;
int n = 0;
int ConvertionNB = 10;
double ReceptionNB;


/*Initialisation du mersenne twister via l'envoie d'une clée*/
unsigned long init[4]={0x244, 0x573, 0x991, 0x236}, length = 4;
init_by_array(init, length);

int C0=0,C1=0,C2=0,C3=0,C4=0,C5=0,C6=0,C7=0;// Variable prenant le nombre de fois que sont trouvé les chiffres de 0 à 7

while(NBMAX < 0){//"NBMAX" ne peut etre inférieur à 0
    printf("Combien de nombre voulez vous :");
    printf("\n");
    scanf("%d", &NBMAX );// nombre de boucle voulue
}



while(n != NBMAX){

ConvertionNB = 10;

while(ConvertionNB >= 8){//La boucle s'arrete quand ConvertionNB <= 7
    ReceptionNB = genrand_real1();//Appel à la fonction genrand_real1 du mersenne twister
    //"genrand_real1" donne un nombre à virgule entre o et 1

    ReceptionNB *= 10;//On modifie la valeur pour avoir un chiffre avant la virgule
    ConvertionNB = ReceptionNB;

/*Ici on supprime le chiffre donné avant la virgule si il n'est pas <= 7 pour en mettre un autre*/
if(ConvertionNB >7 ){
    while(ConvertionNB >7 ){
        ReceptionNB = ReceptionNB - ConvertionNB;
        ReceptionNB *= 10;
        ConvertionNB = ReceptionNB;
}
}
}
if(ConvertionNB == 0){
   n++;
   C0++;
}

else if(ConvertionNB == 1){
   n++;
   C1++;
}
else if(ConvertionNB == 2){
   n++;
   C2++;
}
else if(ConvertionNB == 3){
   n++;
   C3++;
}
else if(ConvertionNB == 4){
   n++;
   C4++;
}
else if(ConvertionNB == 5){
   n++;
   C5++;
}
else if(ConvertionNB == 6){
   n++;
   C6++;
}
else if(ConvertionNB == 7){
   n++;
   C7++;
}

}
printf("\n");
printf("\n");
printf("fini");
printf("\n");
printf("NB de 0 = %d ",C0);
printf("\n");
printf("NB de 1 = %d ",C1);
printf("\n");
printf("NB de 2 = %d ",C2);
printf("\n");
printf("NB de 3 = %d ",C3);
printf("\n");
printf("NB de 4 = %d ",C4);
printf("\n");
printf("NB de 5 = %d ",C5);
printf("\n");
printf("NB de 6 = %d ",C6);
printf("\n");
printf("NB de 7 = %d ",C7);
printf("\n");


return ConvertionNB;
}

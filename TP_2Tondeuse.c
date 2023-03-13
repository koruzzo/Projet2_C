/*//////////////////////////////////*/
/*                                  */
/*                                  */
/*            TP_Rojet              */
/*       Projet_Informatique        */
/*                                  */
/*                                  */
/*//////////////////////////////////*/


/*    DEBUT DU CODE    */

/*Declarations des librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <math.h>
//#include <time.h>
/* ************************* */



/*Implementation du code contenant le mersenne twister afin d'avoir un nombre aleatoire*/
#include "MT.c"


/*Appel a la fonction "ValeurAleatoire" pour garantir son placement en fin de code*/
int ValeurAleatoire();




/*//////////////////////////////////////////////////////////////*/
/*                                                              */
/*  Le main du programme est separe en trois parties :          */
/*  1- Declaration des variables et obtention des informations  */
/*  2- Boucle de fonctionnement de la Tondeuse automatique R    */
/*  3- Boucle de fonctionnement de la Tondeuse automatique T    */
/*                                                              */
/*//////////////////////////////////////////////////////////////*/



int main(){

/*Initialisation du mersenne twister via l'envoie d'une cle a changer pour tirage different*/
unsigned long init[4]={0x446, 0x992, 0x446, 0x121}, length = 4;
init_by_array(init, length);



/*//////////////////////////////////////////////////////////////////*/
/*PARTIE-1 : Declaration des variables et obtention des informations*/
/*//////////////////////////////////////////////////////////////////*/


/*"cmpTondeuseR" est le score de tonte de R et on l'etablie a 1 car on compte l'herbe supprimee pour poser R*/
int cmpTondeuseR=1;


/*"cmpTondeuseT" est le score de tonte de T et on l'etablie a 1 car on compte l'herbe supprimee pour poser T*/
int cmpTondeuseT=1;


int L = 0 ,C = 0; //L = Ligne et C = Colonne pour obtenir la taille voulue du terrain par l'utilisateur


/*La Tondeuse T peut commencer avec 3 configurations*/
int modeT = -1;
//SI modeT = 0 on n'utilise pas T
//SI modeT = 1 l'utilisateur choisis la position de T     ->(LT,CT)
//Si modeT = 2 position de base pour T                    ->(L/2,C/2)

int LT=-1, CT=-1;// LT = Ligne de T et CT = Colonne de T


/*La Tondeuse R peut commencer avec 5 configurations*/
int modeR = -1 ;
//SI modeR = 1 debut en HAUT a gauche    ->(0,0)
//SI modeR = 2 debut en HAUT a droite    ->(0,C-1)
//SI modeR = 3 debut en BAS a gauche     ->(L-1,0)
//SI modeR = 4 debut en BAS a droite     ->(L-1,C-1)
//Si modeR = 0 on n'utulise pas T


/*"GouD" ou "Gauche ou droite" defini vers quelle direction va la tondeuse R*/
int GouD;
//SI GouD = 1 , R va a gauche
//SI GouD = 2 , R va a droite


/*On demande la valeur de L, C, et modeR a l'utilisateur*/
printf("Donnez la taille du terrain a tondre");
printf("\n");
printf("\n");

/*Boucle assurant le respect des conditions d'attribution*/
while(L <= 1){//L ne peut etre inferieur ou egale a 1
    printf("Nombre de ligne :");
    scanf("%d", &L );
    printf("\n");
}
printf("\n");

/*Boucle assurant le respect des conditions d'attribution*/
while(C <= 1){//C ne peut etre inferieur ou egale a 1
    printf("\Nombre de colonne :");
    scanf("%d", &C );
    printf("\n");
}
printf("\n");

/*Boucle assurant le respect des conditions d'attribution pour R*/
while(modeR < 0 || modeR >= 5){//"modeR" est compris entre 0 et 4
    printf("Quel mode pour robot R ? (0 = desactiver R, 1 = debut haut gauche, 2 = debut haut droite, 3 = debut bas gauche, 4 = debut bas droite) :");
    printf("\n");
    scanf("%d", &modeR );
}
printf("\n");
printf("\n");


/*Boucle assurant le respect des conditions d'attribution pour les modes de T*/
while(modeT < 0 || modeT > 2){//"modeT" est compris entre 0 et 2
    printf(" Quel mode pour robot T ? (0 = desactiver T, 1 = choix de la position, 2 = position de base (centre)  :");
    printf("\n");
    scanf("%d", &modeT );
}



/*Variable T pour Temps defini a 0 et augmentera de 1 a chaque tour*/
int T = 0;

/*Declaration du tableau de caracteres en char*/
char CHAMP[L][C];


int i, j;//Variable utile au reperage dans le tableau en fonction des boucles


/*Affichage du terrain sans les tondeuses T et R en temps T = 0 via une double boucle for*/
printf(" T = %d ",T);
printf("\n");
for(i=0;i!=L;i++){
    for(j=0;j!=C;j++){

        CHAMP[i][j]='~';
        printf(" %c ",CHAMP[i][j]);

}
printf("\n");
}
printf("\n");


/*Disposition de la tondeuse R en fonction des 4 valeurs possibles de modeR*/
if(modeR == 0){
cmpTondeuseR=0;//On ne place pas R, elle n'a donc pas de score de pose
}
else if(modeR == 1){
    CHAMP[0][0]='R';
}
else if(modeR == 2){
    CHAMP[0][C-1]='R';
}
else if(modeR == 3){
    CHAMP[L-1][0]='R';
    GouD=2;
}
else if(modeR == 4){
    CHAMP[L-1][C-1]='R';
    GouD=1;
}

printf("\n");
printf("\n");


/*Disposition de la tondeuse T en fonction des 3 valeurs possibles de modeT*/
if(modeT == 1){

    i=1;//On ce sert de i comme valeur d'entree et de sortie de la boucle

    while(i==1){

        /*Boucle assurant le respect des conditions d'attribution pour LT*/
        while(LT < 0 || LT > L-1){//"LT" est compris entre 0 et L-1
            printf("\n");
            printf(" numero de la ligne LT ? :");
            scanf("%d", &LT );
            printf("\n");
        }

        /*Boucle assurant le respect des conditions d'attribution pour CT*/
        while(CT < 0 || CT > C-1){//"CT" est compris entre 0 et C-1
            printf("\n");
            printf(" numero de la colonne CT ? :");
            scanf("%d", &CT );
            printf("\n");
        }

        /*Condition d'echec ou de reussite*/
        if(CHAMP[LT][CT]=='R'){//Ici T veut prendre la place de R, ce qui est impossible
            printf(" Erreur la tondeuse R est deja la, essayer autre part  :");
            LT=-1;//On remet a -1 pour relancer la boucle
            CT=-1;//On remet a -1 pour relancer la boucle
        }
        else{//Placement reussi
            i=0;//On arrete la boucle principale
            CHAMP[LT][CT]='T';
        }
    }
}
else if(modeT==2){
    /*Disposition de base de la tondeuse T au centre theorique du tableau*/
    CHAMP[L/2][C/2]='T';

}

else if(modeT==0){
cmpTondeuseT=0;//On ne place pas T, elle n'a donc pas de score de pose
}


printf(" T = %d ",T);//On affiche T
printf("\n");
printf("\n");

/*Affichage du terrain avec les tondeuses T et R desormais placees, en temps T = 0 via une double boucle for*/
for(i=0;i!=L;i++){
    for(j=0;j!=C;j++){

        printf(" %c ",CHAMP[i][j]);

}
printf("\n");
}
printf("\n");
T++;

/*"cmpFinal" prend le nombre total d'herbe a tondre en score a obtenir pour finir la simulation*/
int cmpFinal = L*C ;


int x, w;//Autres variables utiles au reperage dans le tableau en fonction des boucles

/*"dejaFait" est une variable servant de condition afin d'eviter une repatition des actions deja effectuees */
int dejaFait = 0;//"dejaFait" peut prendre ainsi 4 valeurs differentes avec R et 8 avec T


/*"NBaleatoire" est une variable contenant la valeur retournee de la fonction "ValeurAleatoire"*/
int NBaleatoire;



/*/////////////////////////////////////////////////////////////////////////////////////*/
/*DEBUT DE LA BOUCLE GLOBAL "WHILE" GARANTISSANT L'ARRET QUAND TOUTE L'HERBE EST TONDUE*/
/*/////////////////////////////////////////////////////////////////////////////////////*/


while ((cmpTondeuseR + cmpTondeuseT)  < cmpFinal){//Le score total des tondeuses ne peut etre superieur au score total possible

printf("\n");
printf("\n");
printf(" T = %d  Point de R = %d | Point de T = %d ",T ,cmpTondeuseR ,cmpTondeuseT);//On affiche le score actuel ainsi que le temps T
printf("\n");
printf("\n");



/*On appelle la fonction "ValeurAleatoire" et on attribue sa valeur retournee a la variable "NBaleatoire"*/
NBaleatoire = ValeurAleatoire();


if(modeR == 0 && modeT == 0){
    printf("Pas de Tondeuse :[ ");
    return 0;
}


/*//////////////////////////////////////////////////////////////////*/
/*PARTIE-2 : Boucle de fonctionnement de la Tondeuse automatique R  */
/*//////////////////////////////////////////////////////////////////*/

        for(i=0;i!=L;i++){
            for(j=0;j!=C;j++){

//////////////////////////Changement de ligne pour mode R = 1//////////////////////////
if (CHAMP[i][j]=='R' && j==C-1 && i!= L-1 && CHAMP[i+1][j]!='T' && (i+1) % 2 != 0 && modeR == 1){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i+1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i+1][j]='R';//Deplacement de R
    dejaFait=1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if (CHAMP[i][j]=='R' && j==0 && i!= L-1 && CHAMP[i+1][j]!='T' && (i+1) % 2 == 0 && modeR == 1){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i+1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i+1][j]='R';//Deplacement de R
    dejaFait=1;//On donne une valeur a"dejaFait" si l'action a ete effectuee
break;
}

else if (CHAMP[i][j]=='R' && (j==C-1 || j==0 )&& i!= L-1 && CHAMP[i+1][j]=='T' && ((i+1) % 2 != 0 || (i+1) % 2 == 0) && modeR == 1){
//Si la tondeuse T bloque l'action alors on passe a la boucle suivante
break;
}


//////////////////////////Changement de ligne pour mode R = 2//////////////////////////
if (CHAMP[i][j]=='R' && j==C-1 && i!= L-1 && CHAMP[i+1][j]!='T' && (i+1) % 2 == 0 && modeR == 2){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i+1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i+1][j]='R';//Deplacement de R
    dejaFait=1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if (CHAMP[i][j]=='R' && j==0 && i!= L-1 && CHAMP[i+1][j]!='T' && (i+1) % 2 != 0 && modeR == 2){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i+1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i+1][j]='R';//Deplacement de R
    dejaFait=1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}

else if (CHAMP[i][j]=='R' && (j==C-1 || j==0 ) && i!= L-1 && CHAMP[i+1][j]=='T' && ((i+1) % 2 != 0 || (i+1) % 2 == 0) && modeR == 2){
//Si la tondeuse T bloque l'action alors on passe a la boucle suivante
break;
}


//////////////////////////Changement de ligne pour mode R = 3//////////////////////////
if (CHAMP[i][j]=='R' && j==C-1 && i!= 0 && CHAMP[i-1][j]!='T' && GouD==2 && modeR == 3){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i-1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i-1][j]='R';//Deplacement de R
    GouD=1;//On change la direction
    dejaFait=1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if (CHAMP[i][j]=='R' && j==0 && i!= 0 && CHAMP[i-1][j]!='T' && GouD==1  && modeR == 3){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i-1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i-1][j]='R';//Deplacement de R
    GouD=2;//On change la direction
    dejaFait=1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}

else if (CHAMP[i][j]=='R' && (j==C-1 || j==0 ) && i!= 0 && CHAMP[i-1][j]=='T' && ( GouD==1 || GouD==2 )&& modeR == 3){
//Si la tondeuse T bloque l'action alors on passe a la boucle suivante
break;
}


//////////////////////////Changement de ligne pour mode R = 4//////////////////////////
if (CHAMP[i][j]=='R' && j==0 && i!= 0 && CHAMP[i-1][j]!='T' && GouD==1 && modeR == 4){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i-1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i-1][j]='R';//Deplacement de R
    GouD=2;//On change la direction
    dejaFait=1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if (CHAMP[i][j]=='R' && j==C-1 && i!= 0 && CHAMP[i-1][j]!='T' && GouD==2 && modeR == 4){//Condition pour avoir un deplacement

    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    if(CHAMP[i-1][j]=='~'){
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
    }
    CHAMP[i-1][j]='R';//Deplacement de R
    GouD=1;//On change la direction
    dejaFait=1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}

else if (CHAMP[i][j]=='R' && (j==C-1 || j==0 ) && i!= 0 && CHAMP[i-1][j]=='T' && ( GouD==1 || GouD==2 )&& modeR == 3){
//Si la tondeuse T bloque l'action alors on passe a la boucle suivante
break;
}


/*///////////////////////////////////////////////////////////////////////////////////////////////*/
/* Les actions de "mouvement" ont globalement la meme description que les "changements de ligne" */
/*///////////////////////////////////////////////////////////////////////////////////////////////*/


    else{
//////////////////////////////////////////////////Mouvement du mode 1//////////////////////////////////////////////////
if (modeR == 1){
    if(CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='~' && (i+1)%2 != 0 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=2;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='_'&& (i+1) % 2 != 0 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='_'&& (i+1) % 2 == 0 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='~'&& (i+1) % 2 == 0 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else{
    if (CHAMP[i][j]=='R'){//Si la tondeuse T bloque l'action alors on passe le tour
        dejaFait=4;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
}
}

//////////////////////////////////////////////////Mouvement du mode 2//////////////////////////////////////////////////
else if (modeR == 2){
    if(CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='~' && (i+1)%2 != 0 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=2;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='_'&& (i+1) % 2 != 0 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='_'&& (i+1) % 2 == 0 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}

else if( CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='~'&& (i+1) % 2 == 0 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else{
    if (CHAMP[i][j]=='R'){//Si la tondeuse T bloque l'action alors on passe le tour
        dejaFait=4;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
}
}

//////////////////////////////////////////////////Mouvement du mode 3//////////////////////////////////////////////////
if (modeR == 3){
    if(CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='~' && GouD==2 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=2;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='_'&& GouD==2 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='_'&& GouD==1 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}

else if( CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='~'&& GouD==1 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else{
    if (CHAMP[i][j]=='R'){//Si la tondeuse T bloque l'action alors on passe le tour
        dejaFait=4;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
}
}

//////////////////////////////////////////////////Mouvement du mode 4//////////////////////////////////////////////////
else if (modeR == 4){
    if(CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='~' && GouD==1 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=2;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j-1]=='_'&& GouD==1 && CHAMP[i][j-1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j-1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='_'&& GouD==2 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else if( CHAMP[i][j]=='R'&& CHAMP[i][j+1]=='~'&& GouD==2 && CHAMP[i][j+1]!='T'){//Condition pour avoir un deplacement

        CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
        CHAMP[i][j+1]='R';//Deplacement de R
        cmpTondeuseR++;//Si il y a de l'herbe alors on augmente le score de R
        dejaFait=3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
else{
    if (CHAMP[i][j]=='R'){//Si la tondeuse T bloque l'action alors on passe le tour
        dejaFait=4;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}
}
}
}
}
/*Conditions pour eviter les repetitions du code*/
if (dejaFait==1 || dejaFait==2 || dejaFait==3 || dejaFait==4){
    dejaFait=0;//On remet a 0
break;
}
}

//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////










/*//////////////////////////////////////////////////////////////////*/
/*PARTIE-3 : Boucle de fonctionnement de la Tondeuse automatique T  */
/*//////////////////////////////////////////////////////////////////*/


        for(i=0;i!=L;i++){
            for(j=0;j!=C;j++){

        /*
2 3 4
1 T 5
0 7 6
        */


//////////////////////////////////////////////////Direction  0//////////////////////////////////////////////////
if(CHAMP[i][j]=='T' && CHAMP[i+1][j-1]!='R' && NBaleatoire == 0 && i != L-1 && j != 0){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i+1][j-1]=='~'){
        CHAMP[i+1][j-1]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i+1][j-1]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' && NBaleatoire == 0 && ( i == L-1 || j == 0 || CHAMP[i+1][j-1]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 1;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}


//////////////////////////////////////////////////Direction  1//////////////////////////////////////////////////
else if(CHAMP[i][j]=='T' && CHAMP[i][j-1]!='R' && NBaleatoire == 1 && j != 0){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 2;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i][j-1]=='~'){
        CHAMP[i][j-1]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i][j-1]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' &&NBaleatoire == 1 && ( j == 0|| CHAMP[i][j-1]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 2;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}


//////////////////////////////////////////////////Direction  2//////////////////////////////////////////////////
else if(CHAMP[i][j]=='T' && CHAMP[i-1][j-1]!='R' && NBaleatoire == 2 && i != 0 && j != 0){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i-1][j-1]=='~'){
        CHAMP[i-1][j-1]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i-1][j-1]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' &&NBaleatoire == 2 && ( i == 0 || j == 0 || CHAMP[i-1][j-1]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}


//////////////////////////////////////////////////Direction 3//////////////////////////////////////////////////
else if(CHAMP[i][j]=='T' && CHAMP[i-1][j]!='R' && NBaleatoire == 3 && i != 0){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 3;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i-1][j]=='~'){
        CHAMP[i-1][j]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i-1][j]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' &&NBaleatoire == 3 && (i == 0 || CHAMP[i-1][j]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 4;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}


//////////////////////////////////////////////////Direction  4//////////////////////////////////////////////////
else if(CHAMP[i][j]=='T' && CHAMP[i-1][j+1]!='R' && NBaleatoire == 4 && i != 0 && j != C-1){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 4;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i-1][j+1]=='~'){
        CHAMP[i-1][j+1]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i-1][j+1]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' &&NBaleatoire == 4 && (i == 0 || j == C-1 || CHAMP[i-1][j+1]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 5;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}


//////////////////////////////////////////////////Direction 5//////////////////////////////////////////////////
else if(CHAMP[i][j]=='T' && CHAMP[i][j+1]!='R' && NBaleatoire == 5 && j != C-1){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 5;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i][j+1]=='~'){
        CHAMP[i][j+1]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i][j+1]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' &&NBaleatoire == 5 && ( j == C-1 || CHAMP[i][j+1]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 6;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}


//////////////////////////////////////////////////Direction 6//////////////////////////////////////////////////
else if(CHAMP[i][j]=='T' && CHAMP[i+1][j+1]!='R' && NBaleatoire == 6 && i != L-1 && j != C-1){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 6;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i+1][j+1]=='~'){
        CHAMP[i+1][j+1]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i+1][j+1]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' &&NBaleatoire == 6 && (i == L-1 || j == C-1 || CHAMP[i+1][j+1]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 7;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}


//////////////////////////////////////////////////Direction  7//////////////////////////////////////////////////
else if(CHAMP[i][j]=='T' && CHAMP[i+1][j]!='R' && NBaleatoire == 7 && i != L-1){//Condition pour avoir un deplacement
    CHAMP[i][j]='_';//On tond le terrain derriere le passage de la tondeuse
    dejaFait = 8;//On donne une valeur a "dejaFait" si l'action a ete effectuee
    if (CHAMP[i+1][j]=='~'){
        CHAMP[i+1][j]='T';//Deplacement de T
        cmpTondeuseT+=1;//Si il y a de l'herbe alors on augmente le score de T
break;
}
else{
    CHAMP[i+1][j]='T';//Deplacement de T
break;
}
}
else if(CHAMP[i][j]=='T' &&NBaleatoire == 7 && ( i == L-1 || CHAMP[i+1][j]=='R')){//R bloque T ou T bloquee par un mur
    dejaFait = 8;//On donne une valeur a "dejaFait" si l'action a ete effectuee
break;
}

}


/*Conditions pour eviter les repetitions du code*/
if (dejaFait==1 || dejaFait==2 || dejaFait==3 || dejaFait==4|| dejaFait==5|| dejaFait==6|| dejaFait==7|| dejaFait==8){
    dejaFait=0;//On remet a 0
break;
}
}
T++;//Chaques passages de boucle augmente le temps T de +1

/*Affichage du tableau avec une double boucle for*/
for(x=0;x!=L;x++){
    for(w=0;w!=C;w++){
        printf(" %c ",CHAMP[x][w]);
    }
printf("\n");
}

printf("\n");
}

/*FIN DU PROGRAMME ET AFFICHAGE DU SCORE*/
printf("/*/////////////////////*/");
printf("\n");
printf("/* SIMULATION TERMINEE */");
printf("\n");
printf("/*/////////////////////*/");
printf("\n");
/*Affichage du tableau avec une double boucle for*/
for(x=0;x!=L;x++){
    for(w=0;w!=C;w++){
        printf(" %c ",CHAMP[x][w]);
    }
printf("\n");
}
printf("\n");
printf("/*////////*/");
printf("\n");
printf("/* SCORES */");
printf("\n");
printf("/*////////*/");
printf("\n");
printf("Nombres de points : tondeuse R = %d | tondeuse T = %d",cmpTondeuseR,cmpTondeuseT);
printf("\n");
printf("Nombre en temp T = %d",T);
printf("\n");
printf("\n");

return 0;
}


/*//////////////////////////////////////////////////////////////////*/
/* La fonction "ValeurAleatoire" qui recupere un nombre du mersenne */
/*      twister, le modifie si besoin, le transforme en int et      */
/*                          le retourne                             */
/*//////////////////////////////////////////////////////////////////*/

int ValeurAleatoire(){

int ConvertionNB = 10;
double ReceptionNB;

while(ConvertionNB >= 8){//La boucle s'arrete quand ConvertionNB <= 7
    ReceptionNB = genrand_real1();//Appel a la fonction genrand_real1 du mersenne twister
    //"genrand_real1" donne un nombre a virgule entre o et 1

    ReceptionNB *= 10;//On modifie la valeur pour avoir un chiffre avant la virgule
    ConvertionNB = ReceptionNB;

/*Ici on supprime le chiffre donne avant la virgule si il n'est pas <= 7 pour en mettre un autre*/
if(ConvertionNB >7 ){
    while(ConvertionNB >7 ){
        ReceptionNB = ReceptionNB - ConvertionNB;
        ReceptionNB *= 10;
        ConvertionNB = ReceptionNB;
}
}
}
return ConvertionNB;
}

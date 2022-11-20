#include <stdio.h>
#include <stdlib.h>
#define SIN_TAB_SIZE 20
#define FILTRE_SIZE 6

float resultat_convolution[SIN_TAB_SIZE] = {0};

void calcul_convolution(float *filtre, float *signal, int length_filtre, int length_signal);

int main()
{
    int i = 0;

    float filtre[FILTRE_SIZE]={1,1,1,0,0,0};

    float signal[SIN_TAB_SIZE]={0.5,0.2,0.3,1.1,2.1,3,4.4,5.5,6.6,1.0,2.3,3.3,4.2,5.3,6.6,0.5,1.2,1.3,2.2,2.5};

    printf("Hello world!\n, %d",SIN_TAB_SIZE);

    calcul_convolution(filtre,signal,FILTRE_SIZE,SIN_TAB_SIZE);

    printf("\n\t Voici les coefficients du produit de convolution : \n\t");

    for(i=0;i<SIN_TAB_SIZE;i++){
        printf("%lf\t",resultat_convolution[i]);
    }

    return 0;
}

void calcul_convolution(float *filtre, float *signal, int length_filtre, int length_signal){

    int i=0,j=0;

    //--------------- Je suppose que la taille du filtre est plus petit que celle du signal
    if(length_filtre >= length_signal ){
        //---- C'est qu'il y a un problème
        printf("\n------------------------------------------------------------------------------------------------------------");
        printf("\n\n\t Il y a probleme, la taille du filtre est plus grande que celle du signal\n");
        printf("\n------------------------------------------------------------------------------------------------------------");
    }else{

        for(i=0;i<length_signal;i++){
            for(j=0;j<length_filtre;j++){
                    if((i-j)>=0){
                            resultat_convolution[i]+= filtre[j]*signal[i-j];
                    }
            }
        }
    }

}

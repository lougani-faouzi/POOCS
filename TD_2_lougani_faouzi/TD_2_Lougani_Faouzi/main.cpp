#include<iostream>
#include "main_functions.h"

int main() {
   
  enum class ChoixCalcul {stationnaire,transitoire};
  auto choix_calcul=ChoixCalcul::transitoire;
  
  switch(choix_calcul){

        case ChoixCalcul::stationnaire:
             initParticles();
             computParticles(1.0);
             printParticles(1.0);
        break;

        case ChoixCalcul::transitoire:
             float i=0.0;
             while (i<1.0)
             // ici j ai défini l interval [0,1] et un pas de 0.2
               {
               computParticles(i);
               printParticles(i);
               i=i+0.2;
               }
        
        break;
           }
           
   return 0;
}


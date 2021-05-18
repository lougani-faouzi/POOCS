//
// Created by dechaiss on 11/11/20.
//

#ifndef TD_PARTICLES_H
#define TD_PARTICLES_H

#include <iostream>
#include <fstream>
#include <vector>

class GasField{

/* la declaration d'un static vitesse_gaz afin que ce 
dernier soit accésible par n'importe classe (notre cas particule comme exemple)
il faut  declarer get_vitesse() comme une evaluation d expression*/
private: constexpr static double vitesse_gaz=1.0;
public :
	 constexpr static double get_vitesse()
	{
         return vitesse_gaz;
        
        }
};



class Particles {

int nb_particles=10;

std::vector<double> positions;
std::vector<double> vitesses;



public:

   

  void init(){ 
  /* init  permettra d'initialiser les positions et vitesses a 0
  Pour l'export comme dans l'enoncé il ya pas de contrainte (création d'une fonction export ...)
  j'ai prix l'initiative d'exporter directement une fois on initialise dans nos fichiers 
  */
  try{
   std::cout << "--- init particles ---" << std::endl;   
       for( int i=0; i<nb_particles;++i){
       positions.push_back(0.0);
                                        }
       for( int i=0; i<nb_particles;++i){
       vitesses.push_back(0.0);
             	                         }

      
       std::cout <<"--- Export particles positions at time t = 0 in file particles_positions "<< std::endl;
       std::ofstream fichier { "particle_positions.txt" };
       for (auto const & p : positions)
       {
        fichier << p << std::endl;
       }
       fichier.close();
	
       std::cout <<"--- Export particles velocities at time t = 0 in file particles_velocities "<< std::endl;
       std::ofstream fichier1 { "particle_velocities.txt" };
       for (auto const & v : vitesses)
       {
        fichier1 << v << std::endl;
       }
        fichier1.close();
        
        if(positions.empty() and vitesses.empty())
        {
           throw std::string("initialisation error ");
        }
        
      }//end try 
        catch (std::string const& chaine )
        {
            std::cerr <<chaine<< std::endl;
        }
  }

  void computeEvolution(double time){
   /*
   on initialise :
   les vitesses avec la vitesse de gas avec std::fill
   les positions avec vitesse du gaz*(temps-temps initial)
   l'acces a la vitesse du gas se fais avec GasField::get_vitesse() 
   */
   std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
   double temps_initial=0.0,pos=0.0; 
   
   
   std::fill(vitesses.begin(),vitesses.end(),GasField::get_vitesse());
   std::ofstream fichier1 { "particle_velocities.txt" };
   for (auto const & v : vitesses)
    {
        fichier1 << v << std::endl;
    }
   std::cout <<"--- Export particles velocities at time t = "<< time <<" in file particles_velocities "<< std::endl;
   
   pos += GasField::get_vitesse()*(time-temps_initial);
   std::fill(positions.begin(),positions.end(),pos);
   std::ofstream fichier { "particle_positions.txt" };
   for (auto const & p : positions)
    {
        fichier << p << std::endl;
    }
   std::cout <<"--- Export particles positions at time t = " << time <<" in file particles_positions "<< std::endl;
                             
  }

   void print(double time) {
    std::cout << "--- print particle positions at time : " << time << " ---" << std::endl;

  }
};

#endif // TD_PARTICLES_H

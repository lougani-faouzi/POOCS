//
// Created by dechaiss on 11/11/20.
//

#ifndef TD_PARTICLES_H
#define TD_PARTICLES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <math.h>
#include<iostream>

class UnsteadyGasField{

public:
	  double velocity(double pos_x){
              double v=0.0;
              double pi=std::atan(1)*4;
              v=sin(-pi*pos_x);                             
              return v;                              
                                     }


};




class GasField{

private: constexpr static double vitesse_gaz=1.0;
public :
	 constexpr static double get_vitesse()
	{
         return vitesse_gaz;
        
        }
};


enum class ResolutionMethod {Method1, Method2};

/*l'enum class ResolutionMethod permet d'initialiser 

Method1=localisée en un point
Method2=initialisation uniforme en espace 
*/



class Particles {

int nb_particles=200;

std::vector<double> positions;
std::vector<double> vitesses;



public:

   
  
   
  void init(ResolutionMethod rm){ 
  
    switch (rm) {
    case ResolutionMethod::Method1:
       {
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
      break;  
   
    
    case ResolutionMethod::Method2: 
    {
      std::cout << "--- init particles ---" << std::endl;  

      double pas_uniforme=2.0/nb_particles; //ici le but est d'avoir un pas uniforme entre -1 et 1
      double new_pos=-1.0;
      for(int i=0; i<nb_particles;++i){
      positions.push_back(new_pos);
      new_pos=new_pos+pas_uniforme;
                                      }
      
    }          	                         
 
    
    break;
     
     
             }   
	
  }

  void computeEvolution(double time){

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
  
  // La methode ci aprés est surchargée 
  // on a position_particule=position_initiale+(temps*valeur_de_gas_pour_chaque position)
  // vitesse_particule=vitesse_de_gas_pour_chaque_position
  // computeEvolution permet d'exporter en plus en chaque time un fichier particle_positions_time.txt
  // et un fichier particle_velocity_time.txt
  
  void computeEvolution(double time, UnsteadyGasField gas_field){
   std::vector<double> temp;
   std::vector<double> temp1;
  
   if(time==0.0){
   
   
   
   std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
  
   for(const auto& p: positions) 
   {
	temp.push_back(p+(time*gas_field.velocity(p)));
   
   }   
   std::ofstream fichier0 { "particle_positions_0.txt" };
   for (auto const & p : temp)
   {
        fichier0 << p << std::endl;
   }
   fichier0.close();
   std::cout <<"--- Export particles positions at time t = " << time <<" in file particles_positions "<< std::endl;
   
   
   
     
   for(const auto& p: temp) 
   {
       temp1.push_back(gas_field.velocity(p));
   }
   std::ofstream fichier00 { "particle_velocities_0.txt" };
   for (auto const & t : temp1)
   {
        fichier00 << t << std::endl;
   }
   fichier00.close();
   std::cout <<"--- Export particles velocities at time t = "<< time <<" in file particles_velocities "<< std::endl;
      
  
  }
  
   if(time==0.2){
   
   
   
   std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
  
   for(const auto& p: positions) 
   {
	temp.push_back(p+(time*gas_field.velocity(p)));
   
   }   
   std::ofstream fichier1 { "particle_positions_0_2.txt" };
   for (auto const & p : temp)
   {
        fichier1 << p << std::endl;
   }
   fichier1.close();
   std::cout <<"--- Export particles positions at time t = " << time <<" in file particles_positions "<< std::endl;
   
   
   
     
   for(const auto& p: temp) 
   {
       temp1.push_back(gas_field.velocity(p));
   }
   std::ofstream fichier11 { "particle_velocities_0_2.txt" };
   for (auto const & t : temp1)
   {
        fichier11 << t << std::endl;
   }
   fichier11.close();
   std::cout <<"--- Export particles velocities at time t = "<< time <<" in file particles_velocities "<< std::endl;
      
  
  }
  
     if(time==0.4){
   
   
   
   std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
  
   for(const auto& p: positions) 
   {
	temp.push_back(p+(time*gas_field.velocity(p)));
   
   }   
   std::ofstream fichier2 { "particle_positions_0_4.txt" };
   for (auto const & p : temp)
   {
        fichier2 << p << std::endl;
   }
   fichier2.close();
   std::cout <<"--- Export particles positions at time t = " << time <<" in file particles_positions "<< std::endl;
   
   
   
     
   for(const auto& p: temp) 
   {
       temp1.push_back(gas_field.velocity(p));
   }
   std::ofstream fichier22 { "particle_velocities_0_4.txt" };
   for (auto const & t : temp1)
   {
        fichier22 << t << std::endl;
   }
   fichier22.close();
   std::cout <<"--- Export particles velocities at time t = "<< time <<" in file particles_velocities "<< std::endl;
      
  
  }
  
  if(time==0.6){
   
   
   
   std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
  
   for(const auto& p: positions) 
   {
	temp.push_back(p+(time*gas_field.velocity(p)));
   
   }   
   std::ofstream fichier2 { "particle_positions_0_4.txt" };
   for (auto const & p : temp)
   {
        fichier2 << p << std::endl;
   }
   fichier2.close();
   std::cout <<"--- Export particles positions at time t = " << time <<" in file particles_positions "<< std::endl;
   
   
   
     
   for(const auto& p: temp) 
   {
       temp1.push_back(gas_field.velocity(p));
   }
   std::ofstream fichier22 { "particle_velocities_0_4.txt" };
   for (auto const & t : temp1)
   {
        fichier22 << t << std::endl;
   }
   fichier22.close();
   std::cout <<"--- Export particles velocities at time t = "<< time <<" in file particles_velocities "<< std::endl;
      
  
  }
  
    
  
     if(time==0.8){
   
   
   
   std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
  
   for(const auto& p: positions) 
   {
	temp.push_back(p+(time*gas_field.velocity(p)));
   
   }   
   std::ofstream fichier4 { "particle_positions_0_8.txt" };
   for (auto const & p : temp)
   {
        fichier4 << p << std::endl;
   }
   fichier4.close();
   std::cout <<"--- Export particles positions at time t = " << time <<" in file particles_positions "<< std::endl;
   
   
   
     
   for(const auto& p: temp) 
   {
       temp1.push_back(gas_field.velocity(p));
   }
   std::ofstream fichier44 { "particle_velocities_0_8.txt" };
   for (auto const & t : temp1)
   {
        fichier44 << t << std::endl;
   }
   fichier44.close();
   std::cout <<"--- Export particles velocities at time t = "<< time <<" in file particles_velocities "<< std::endl;
      
  
  }
  
  
}  

   void print(double time) {
    std::cout << "--- print particle positions at time : " << time << " ---" << std::endl;

  }
};

#endif // TD_PARTICLES_H

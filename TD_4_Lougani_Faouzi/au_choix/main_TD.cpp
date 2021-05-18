#include "Simulator.h"
#include "SteadySimulator.h"
#include "UnsteadySimulator.h"
#include <iostream>
#include <memory>
#include <cstring>

enum class SimulationType {SteadyState,UnsteadyState};
 
std::unique_ptr<Simulator> createSimulator(SimulationType simulation_type) {
  
  std::unique_ptr<Simulator>simulator=nullptr;
  switch (simulation_type)
  {
  
  case SimulationType::SteadyState:
    simulator=std::make_unique<SteadySimulator>();
    break;
    
  case SimulationType::UnsteadyState:
    simulator=std::make_unique<UnsteadySimulator>();
    break;
  }
  
  return simulator;
 
}

int main(int argc,char **argv){
// choix du mode de la simulation avec l'arg ./Main.exe --steady ou ./Main.exe --unsteady

std::cout<< "LOUGANI FAOUZI SIMULATOR CHOISE "<<std::endl;
std::cout<< " "<<std::endl;

 if(argc==2)
 {
   if (strcmp(argv[1],"--steady")==0)
   {	       
   		auto simulation_type = SimulationType::SteadyState;
   		std::unique_ptr<Simulator>simulator=createSimulator(simulation_type);
   		simulator->compute();
	        return 0;
   }      
   
   else if (strcmp(argv[1],"--unsteady")==0)
   {	       
	       auto simulation_type = SimulationType::UnsteadyState;
               std::unique_ptr<Simulator>simulator=createSimulator(simulation_type);
               simulator->compute();
	       return 0;
   } 	
   else 
	       
	       
	       std::cout<< "args error "<<std::endl;
	       return 0;
	    
 }else 

 std::cout<< "args error "<<std::endl;
 return 0;
}

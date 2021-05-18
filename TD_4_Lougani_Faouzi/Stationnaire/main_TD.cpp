#include "Simulator.h"
#include "SteadySimulator.h"
#include "UnsteadySimulator.h"
#include <iostream>
#include <memory>

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

int main(){
// Simulateur lancant une simulation stationnaire au temps 1
// pour l executable c'est ./Main.exe

std::cout<< "LOUGANI FAOUZI STEADY SIMULATOR  "<<std::endl;
std::cout<< " "<<std::endl;

auto simulation_type = SimulationType::SteadyState;
std::unique_ptr<Simulator>simulator=createSimulator(simulation_type);
simulator->compute();

  return 0;
}

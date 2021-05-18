#include "Simulator.h"
#include "SteadySimulator.h"
#include "UnsteadySimulator.h"
#include <iostream>
#include <memory>

/*
 Dans cette partie on stocke les simulateurs dans des 
 std::unique_ptr<Simulator> et non des pointeurs Simulator*
 le stockage avec Simulator* est commenté 
*/


enum class SimulationType {SteadyState,UnsteadyState};
 
 
std::unique_ptr<Simulator> createSimulator(SimulationType simulation_type) {
  //Simulator* simulator = nullptr;
  std::unique_ptr<Simulator>simulator=nullptr;
  switch (simulation_type)
  {
  case SimulationType::SteadyState:
    //simulator= new SteadySimulator{};
    simulator=std::make_unique<SteadySimulator>();

    break;
  case SimulationType::UnsteadyState:
    //simulator = new UnsteadySimulator{};
    simulator=std::make_unique<UnsteadySimulator>();
    break;
  }
  
  return simulator;
 
}

int main(){
 
auto simulation_type = SimulationType::SteadyState;
 /* Simulator* simulator = createSimulator(simulation_type);
  simulator->compute();
*/  
std::unique_ptr<Simulator>simulator=createSimulator(simulation_type);
simulator->compute();
  return 0;
}

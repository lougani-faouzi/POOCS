//
// Created by dechaiss on 11/11/20.
//

#ifndef TD_UNSTEADYSIMULATOR_H
#define TD_UNSTEADYSIMULATOR_H

#include "Simulator.h"
#include "Particles.h"

class UnsteadySimulator : public Simulator {
  Particles m_particles;
public:

  void compute() override {
    UnsteadyGasField g;
    auto method=ResolutionMethod::Method2;
    //la fonction init doit prendre en parametre le mode d'initialisation afin de 
    //faire fonctionner l'enum_class
    m_particles.init(method);
    auto final_time = 1.0;
    auto initial_time = 0.0;
    auto delta_t = 0.2;
    auto current_time = initial_time;
    while (current_time < final_time){
      m_particles.computeEvolution(current_time,g);
      m_particles.print(current_time);
      current_time += delta_t;
    }
  }
};

#endif // TD_UNSTEADYSIMULATOR_H



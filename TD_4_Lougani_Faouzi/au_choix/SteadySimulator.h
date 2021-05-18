//
// Created by dechaiss on 11/11/20.
//

#ifndef TD_STEADYSIMULATOR_H
#define TD_STEADYSIMULATOR_H

#include "Simulator.h"
#include "Particles.h"

class SteadySimulator : public Simulator {
  Particles m_particles;
public:
 
  void compute() override {
    auto method=ResolutionMethod::Method1; 
    //la fonction init doit prendre en parametre le mode d'initialisation afin de 
    //faire fonctionner l'enum_class
    m_particles.init(method);
    auto final_time = 1.0;
    m_particles.computeEvolution(final_time);
    m_particles.print(final_time);
  }
};

#endif // TD_STEADYSIMULATOR_H

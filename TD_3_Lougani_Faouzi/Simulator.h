//
// Created by dechaiss on 11/11/20.
//

#ifndef TD_SIMULATOR_H
#define TD_SIMULATOR_H

class Simulator {
public:
  virtual ~Simulator() = default;
  virtual void compute() = 0;
};

#endif // TD_SIMULATOR_H

#include "gtest/gtest.h"
#include "main_functions.h"
#include<iostream>


TEST(MainFunctionTest,InitParticlesTest){
  initParticles();
}

TEST(MainFunctionTest,PrintParticlesTest){
  printParticles(0);
}

TEST(MainFunctionTest,ComputParticlesTest){
 computParticles(0);
}

// fonctions que j ai ajouté d'aprés l'affichage
TEST(MainFunctionTest,ComputeUnsteadyStateTest){ 
  computeUnsteadyState();
}

TEST(MainFunctionTest,ComputesteadyStateTest){
  computesteadyState();
}

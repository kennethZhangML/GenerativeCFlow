// langevin_equation.h
#include <iostream>
#include <random>

#ifndef PATHINTEGRALF_H
#define PATHINTEGRALF_H

class RandomFluctuations {
private:
  std::default_random_engine generator;
  std::normal_distribution<double> distribution;

public:
  RandomFluctuations(double mean, double stddev);
  double getFluctuation();
};

class LangevinEquation {
private:
  double tau;
  double T;
  int d;
  double *x;
  double *omega;
  double *f;
  RandomFluctuations *fluctuations;

public:
  LangevinEquation(int dimension, double simulationTime, double mean,
                   double stddev);
  ~LangevinEquation();
  void setInitialState(double *initialX);
  void calculateFlow();
  void step(double dt);
  double *getState();
  double getTime();
};

#endif

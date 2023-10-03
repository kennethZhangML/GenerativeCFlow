#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <string>
#include <vector>

class RandomFluctuations {
private:
  std::default_random_engine generator;
  std::normal_distribution<double> distribution;

public:
  RandomFluctuations(double mean, double stddev) : distribution(mean, stddev) {}

  double getFluctuation() { return distribution(generator); }
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
                   double stddev) {
    d = dimension;
    T = simulationTime;
    tau = 0.0;

    x = new double[d];
    omega = new double[d];
    f = new double[d];

    fluctuations = new RandomFluctuations(mean, stddev);
  }

  ~LangevinEquation() {
    delete[] x;
    delete[] omega;
    delete[] f;
    delete fluctuations;
  }

  void setInitialState(double *initialX) {
    for (int i = 0; i < d; i++) {
      x[i] = initialX[i];
    }
  }

  void calculateFlow() {
    // TODO: implement flow calculation
  }

  void step(double dt) {
    calculateFlow();

    for (int i = 0; i < d; i++) {
      omega[i] = fluctuations->getFluctuation();
      x[i] += f[i] * dt + omega[i];
    }

    tau += dt;
  }

  double *getState() { return x; }

  double getTime() { return tau; }
};

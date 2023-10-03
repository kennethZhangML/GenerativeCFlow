#include "pathIntegralF.h"

int main() {
  const int dimension = 2;
  const double simulationTime = 1.0;
  const double mean = 0.0;
  const double stddev = 1.0;
  const double dt = 0.01;

  LangevinEquation langevin(dimension, simulationTime, mean, stddev);

  double initialX[dimension] = {1.0, 2.0};
  langevin.setInitialState(initialX);

  while (langevin.getTime() < simulationTime) {
    langevin.step(dt);
    double *currentState = langevin.getState();
    std::cout << "Time: " << langevin.getTime() << ", State: ("
              << currentState[0] << ", " << currentState[1] << ")\n";
  }

  return 0;
}

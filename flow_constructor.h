#ifndef FLOW_CONSTRUCTOR_H
#define FLOW_CONSTRUCTOR_H

#include <vector>

class FlowConstructor {
private:
  int d;
  std::vector<std::vector<double>> Jacobian;

public:
  FlowConstructor(int dimension);
  void setJacobian(const std::vector<std::vector<double>> &jacobian);
  std::vector<double> constructFlow(const std::vector<double> &state);
};

#endif // FLOW_CONSTRUCTOR_H

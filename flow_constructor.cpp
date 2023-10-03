#include "flow_constructor.h"

FlowConstructor::FlowConstructor(int dimension) : d(dimension) {
  Jacobian = std::vector<std::vector<double>>(d, std::vector<double>(d, 0.0));
}

void FlowConstructor::setJacobian(
    const std::vector<std::vector<double>> &jacobian) {
  if (jacobian.size() == d && jacobian[0].size() == d) {
    Jacobian = jacobian;
  } else {
    throw std::invalid_argument("Invalid Jacobian matrix dimensions");
  }
}

std::vector<double>
FlowConstructor::constructFlow(const std::vector<double> &state) {
  if (state.size() != d) {
    throw std::invalid_argument("Invalid state vector size");
  }

  std::vector<double> flow(d, 0.0);

  for (int i = 0; i < d; i++) {
    for (int j = 0; j < d; j++) {
      flow[i] += Jacobian[i][j] * state[j];
    }
  }

  return flow;
}

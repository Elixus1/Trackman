#ifndef WRITER_HPP
#define WRITER_HPP

#include "vector3d.hpp"
#include <fstream>

struct Settings {
  int n;
  double xlo, xhi;
  double ylo, yhi;
  double zlo, zhi;
};
void WriteTrajectory(std::ofstream &out, int timestep, const Vector3D &x,
                     const Vector3D &vel, const Vector3D &force,
                     const Settings &settings);

#endif

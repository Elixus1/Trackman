#include "writer.hpp"
void WriteTrajectory(std::ofstream &out, int timestep, const Vector3D &x,
                     const Vector3D &vel, const Vector3D &force,
                     const Settings &settings) {
  int num_atoms = settings.n;

  out << "ITEM: TIMESTEP\n" << timestep << "\n";
  out << "ITEM: NUMBER OF ATOMS\n" << num_atoms << "\n";
  out << "ITEM: BOX BOUNDS\n";
  out << settings.xlo << " " << settings.xhi << "\n";
  out << settings.ylo << " " << settings.yhi << "\n";
  out << settings.zlo << " " << settings.zhi << "\n";
  out << "ITEM: ATOMS id type x y z\n";
  out << "1 1 1 " << x.x << " " << x.y << " " << x.z << "\n";
}

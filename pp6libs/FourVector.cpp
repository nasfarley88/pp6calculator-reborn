#include "FourVector.hpp"
#include <complex>
#include <iostream>

double dot(FourVector a, FourVector b)
{
  ///
  /// Define the dot (inner) product of a FourVector
  ///
  /// We're particle physicists so this uses the signature +---.
  /// 

  return a.gett()*b.gett() - a.getx()*b.getx() - a.gety()*b.gety() - a.getz()*b.getz();
}

double FourVector::modulusSquared()
{
  ///
  /// Define the modulus of a FourVector
  /// 
  return dot(*this,*this);
}

std::ostream& operator<<(std::ostream& s, const FourVector& c)
{
  ///
  /// Print a FourVector in the form (x, y, z).
  ///
  s << "(" << c.gett() << ", " << c.getx() << ", " << c.gety() << ", " << c.getz() << ")";
  return s;
}

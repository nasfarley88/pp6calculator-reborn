#include "ThreeVector.hpp"
#include <complex>
#include <iostream>



double dot(ThreeVector a, ThreeVector b)
{
  ///
  /// Define the dot (inner) product of a ThreeVector
  /// 
  return a.getx()*b.getx() + a.gety()*b.gety() + a.getz()*b.getz();
}

double ThreeVector::modulus()
{
  ///
  /// Define the modulus of a ThreeVector
  /// 
  return sqrt(dot(*this,*this));
}


std::ostream& operator<<(std::ostream& s, const ThreeVector& c)
{
  ///
  /// Print a ThreeVector in the form (x, y, z)
  /// 
  s << "(" << c.getx() << ", " << c.gety() << ", " << c.getz() << ")";
  return s;
}

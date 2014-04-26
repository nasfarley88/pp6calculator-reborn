#ifndef THREEVECTOR_HPP
#define THREEVECTOR_HPP

#include <iostream>


class ThreeVector
{
private:
  double x_,y_,z_;
public:
  ThreeVector()
    : x_(0), y_(0), z_(0) {}
  ThreeVector(double x, double y, double z)
    : x_(x), y_(y), z_(z) {}
  double getx() const { return x_; }
  double gety() const { return y_; }
  double getz() const { return z_; }
  double setx(double x) { x_ = x; return x_; }
  double sety(double y) { y_ = y; return y_; }
  double setz(double z) { z_ = z; return z_; }
  double modulus();
  friend std::ostream& operator<<(std::ostream& s, const ThreeVector& c);

};

// dot product defined in ThreeVector.cpp
double dot(ThreeVector a, ThreeVector b);

#endif

#ifndef FOURVECTOR_HPP
#define FOURVECTOR_HPP
#include "ThreeVector.hpp"


class FourVector
{
private:
  double t_,x_,y_,z_;
public:
  FourVector()
    : t_(0), x_(0), y_(0), z_(0) {}
  FourVector(double t, double x, double y, double z)
    : t_(t), x_(x), y_(y), z_(z) {}
  double gett() const { return t_; }
  double getx() const { return x_; }
  double gety() const { return y_; }
  double getz() const { return z_; }
  ThreeVector getThreeVector() const { return ThreeVector(x_,y_,z_); }
  double sett(double t) { t_ = t; return t_; }
  double setx(double x) { x_ = x; return x_; }
  double sety(double y) { y_ = y; return y_; }
  double setz(double z) { z_ = z; return z_; }
  double modulusSquared();
};

// dot product defined in FourVector.cpp
double dot(FourVector a, FourVector b);

#endif

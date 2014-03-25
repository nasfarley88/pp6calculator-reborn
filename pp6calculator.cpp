#include <iostream>
#include <string>
#include <regex>
// #include <cmath>
#include <complex>
#include "ThreeVector.hpp"
#include "FourVector.hpp"

std::ostream& operator<<(std::ostream& s, const ThreeVector& c)
{
  ///
  /// Print a ThreeVector in the form (x, y, z)
  /// 
  s << "(" << c.getx() << ", " << c.gety() << ", " << c.getz() << ")";
  return s;
}

std::ostream& operator<<(std::ostream& s, const FourVector& c)
{
  ///
  /// Print a FourVector in the form (x, y, z).
  ///
  s << "(" << c.gett() << ", " << c.getx() << ", " << c.gety() << ", " << c.getz() << ")";
  return s;
}

double interceptXAxis(double m, double c)
{
  ///
  /// A function to calculate the intercept on the x-axis of a straight line
  /// 
  return c/m;
}

struct quadraticRoots
{
  std::complex<double> root1,root2; 
};

std::ostream& operator<<(std::ostream& s, const quadraticRoots& c)
{
  ///
  /// Be smart about what to print when it comes to roots of quadratic equations
  /// 
  if(c.root1 == c.root2 && c.root1.imag() != 0)
    s << c.root1 << " (repeated root)";
  else if(c.root1 == c.root2 && c.root1.imag() == 0)
    s << c.root1.real() << " (repeated root)";
  else if(c.root1.imag() == 0 || c.root2.imag() == 0)
    s << c.root1.real() << " and " << c.root2.real();
  else 				// all that's left is root1, root2 are complex
    s << c.root1 << " and " << c.root2;
  return s;
}

quadraticRoots quadraticSolver(double aReal, double bReal, double cReal)
{
  quadraticRoots roots = quadraticRoots();
  roots.root1 = std::complex<double>(0,0);
  roots.root2 = std::complex<double>(0,0);

  std::complex<double> a = aReal;
  std::complex<double> b = bReal;
  std::complex<double> c = cReal;

  if((b*b - 4.0*a*c) == std::complex<double>(0,0))
    {
      roots.root1 = (-b)/(2.0*a);
      roots.root2 = roots.root1;
    }
  else
    {
      roots.root1 = (-b+sqrt(b*b-4.0*a*c))/(2.0*a);
      roots.root2 = (-b-sqrt(b*b-4.0*a*c))/(2.0*a);
    }
  return roots;
}

void coutChosen(std::string x)
{
  ///
  /// Function to cout "You have chosen the [x] function"
  /// 
  std::cout << "You have chosen the " << x << " function!" << std::endl;
}

template<typename T>
void promptForValue(T *x)
{
  ///
  /// Function for prompting for a single value, without spaces
  ///

  // Ask for it
  std::cout << "> ";
  std::cin >> *x;
}

int main(int argc, char *argv[])
{
  // string to decide what to do
  // TODO make it 'human' so that the user could type (e.g.)
  // > Please can I find out the intercept of a straight line on the x-axis
  // and the program knows what to do (by matching 'intercept' and 'x-axis')
  std::string decision;
  
  std::cout << "Hello World" << std::endl;

  std::cout << "Welcome to PP6Calculator (reborn). "
	    << "Please specify which function you would like to perform: "
	    << std::endl
	    << "> ";
  
  std::getline(std::cin,decision);
  
  if(std::regex_match(decision, std::regex("(^i$)|(.*intercept.*)")))
    {
      // initialise variables for y=mx+c
      double m,c;
      
      coutChosen("intercept");
      std::cout << "Please specify a gradient (m): ";
      std::cin >> m;
      std::cout << "Please specify an intercept (c): " << std::endl;
      std::cin >> c;
      std::cout << "The x intercept for the line y = " << m << "x + " << c
		<< " is " << interceptXAxis(m,c) << "." << std::endl;
    }
  else if(std::regex_match(decision, std::regex("(^q$)|(.*quadratic.*)")))
    {
      // Initialise variables for (-b±√(b^2 - 4ac))/(2a)
      double a, b, c;

      coutChosen("quadratic solver");
      std::cout << "Choose the x^2 term (a): " << std::endl << "> ";
      std::cin >> a;
      std::cout << "Choose the x term (b): " << std::endl << "> ";
      std::cin >> b;
      std::cout << "Choose the constant term (c): " << std::endl << "> ";
      std::cin >> c;

      std::cout << "The roots for your chosen quadratic are  "
		<< quadraticSolver(a,b,c) << std::endl;
    }
  else if(std::regex_match(decision,std::regex("(^im$)")))
    {
      coutChosen("invariant mass of 2 particles");

      // Initialise the four momentum of the particles involved
      double particleOne[4], particleTwo[4];

      std::cout << "Choose the E term for particle one" << std::endl;
      promptForValue(&particleOne[0]);
      std::cout << "Choose the px term for particle one" << std::endl;
      promptForValue(&particleOne[1]);
      std::cout << "Choose the py term for particle one" << std::endl;
      promptForValue(&particleOne[2]);
      std::cout << "Choose the pz term for particle one" << std::endl;
      promptForValue(&particleOne[3]);

      std::cout << "Choose the E term for particle two" << std::endl;
      promptForValue(&particleTwo[0]);
      std::cout << "Choose the px term for particle two" << std::endl;
      promptForValue(&particleTwo[1]);
      std::cout << "Choose the py term for particle two" << std::endl;
      promptForValue(&particleTwo[2]);
      std::cout << "Choose the pz term for particle two" << std::endl;
      promptForValue(&particleTwo[3]);

      FourVector particleOneFV = FourVector(particleOne[0],
					    particleOne[1],
					    particleOne[2],
					    particleOne[3]);
      FourVector particleTwoFV = FourVector(particleTwo[0],
					    particleTwo[1],
					    particleTwo[2],
					    particleTwo[3]);

      // Check if the invariant mass is real (and therefore physical)
      if(dot(particleOneFV,particleTwoFV) >= 0)
	{
	  std::cout << "The invariant mass for the two particles" << particleOneFV
		    << " and " << particleTwoFV << " is "
		    << sqrt(dot(particleOneFV,particleTwoFV)) << std::endl;
	}
      else
	{
	  std::cout << "The invariant mass for the two particles" << particleOneFV
		    << " and " << particleTwoFV << " is imaginary." << std::endl;
	}	  
    }
  // This *must* come after invariant mass as .*m$ below also matches ^im$ (the
  // command for invariant mass which is not a modulus function).
  else if(std::regex_match(decision,std::regex("(.*m$)|(.*modulus.*)")))
    {
      if(std::regex_match(decision,std::regex("(^3m$)|(.*\b3.vector.*modulus.*)")))
	{
	  // Initialise variables for the ThreeVector
	  double x,y,z;
	  coutChosen("3-vector modulus");
	  std::cout << "Choose the x term: " << std::endl;
	  promptForValue(&x);
	  std::cout << "Choose the y term: " << std::endl;
	  promptForValue(&y);
	  std::cout << "Choose the z term: " << std::endl;
	  promptForValue(&z);

	  
	  std::cout << "The modulus of the 3-vector " <<  ThreeVector(x,y,z)
		    << " is " << ThreeVector(x,y,z).modulus() << std::endl;
	}
      else if(std::regex_match(decision,std::regex("(^4m$)|(.*\b4.vector.*modulus.*)")))
	{
	  // Initialise variables for the FourVector
	  double t,x,y,z;
	  coutChosen("4-vector modulus squared");
	  std::cout << "Choose the t term: " << std::endl;
	  promptForValue(&t);
	  std::cout << "Choose the x term: " << std::endl;
	  promptForValue(&x);
	  std::cout << "Choose the y term: " << std::endl;
	  promptForValue(&y);
	  std::cout << "Choose the z term: " << std::endl;
	  promptForValue(&z);
	    
	    
	  std::cout << "The modulus squared of the 4-vector " <<  FourVector(t,x,y,z)
		    << " is " << FourVector(t,x,y,z).modulusSquared() << std::endl;
	}
      else
	{
	  std::cout << "You want to do a modulus, but I'm not sure which one" << std::endl;
	}
    }
  else
    {
      std::cout << "You chose " << decision << std::endl;
      std::cout << "Sorry, I'm not yet complete enough to give you what you want."
		<< std::endl;
    }
  return 0;
}

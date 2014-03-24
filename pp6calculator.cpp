#include <iostream>
#include <string>
#include <regex>
// #include <cmath>
#include <complex>

double interceptXAxis(double m, double c) {
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
  else
    {
      std::cout << "You chose " << decision << std::endl;
      std::cout << "Sorry, I'm not yet complete enough to give you what you want."
		<< std::endl;
    }
  return 0;
}

#include <iostream>
#include <string>
#include <regex>
// #include <cmath>
#include <complex>
#include "ThreeVector.hpp"
#include "FourVector.hpp"
#include "pp6day1.hpp"
#include "pp6day2.hpp"


// std::ostream& operator<<(std::ostream& s, const ThreeVector& c)
// {
//   ///
//   /// Print a ThreeVector in the form (x, y, z)
//   /// 
//   s << "(" << c.getx() << ", " << c.gety() << ", " << c.getz() << ")";
//   return s;
// }


int main()
// int main(int argc, char *argv[])
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
    askinterceptXAxis();
  else if(std::regex_match(decision, std::regex("(^q$)|(.*quadratic.*)")))
    askquadraticSolver();
  else if(std::regex_match(decision,std::regex("(^im$)")))
    askFourVectorDot();
  else if(std::regex_match(decision,std::regex("([34]m$)|(.*modulus.*)")))
    {
      if(std::regex_match(decision,std::regex("(^3m$)|(.*\b3.vector.*modulus.*)")))
	askThreeVectormodulus();
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

#include <iostream>
#include <string>

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
  std::cin >> decision;

  std::cout << "You chose " << decision << std::endl;
  std::cout << "Sorry, I'm not yet complete enough to give you what you want."
	    << std::endl
	    << "Goodbye! I hope to see you again soon!"
	    << std::endl;
  
  return 0;
}

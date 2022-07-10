#ifndef convertTextFileToString_cpp
#define convertTextFileToString_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
function that converts a text file into a string
-----------------------------------------------------------------*/

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <ezprint.cpp>

namespace kelpfile {

std::string convertTextFileToString(const char* file_path) {
  std::ifstream text(file_path);
  std::stringstream buffer;
  buffer << text.rdbuf();
  std::string sbuff = buffer.str();
  return sbuff;
}
  
}


#endif /* convertTextFileToString_cpp */

#ifndef expandSanToHumanReadableString_cpp
#define expandSanToHumanReadableString_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
input: san string 
  -> examples: "fxe4", "O-O"
  
output: human-readable string 
  -> examples: "F takes on E4", "short castles"
-----------------------------------------------------------------*/

#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
#include <ezprint.cpp>

namespace chl {

std::vector<char> pgn_characters = {'K', 'Q', 'N', 'R', 'B'};

const std::unordered_map<char, std::string> basic_character_expansion_map = {
  {'K', "king"}, {'Q', "queen"}, {'N', "knight"}, {'R', "rook"}, {'B', "bishop"},
  {'x', "takes on"},
  {'+', "check"},
  {'#', "checkmate"},
  {'a', "ay"},
  {'b', "bee"},
  {'c', "see"},
  {'d', "dee"},
  {'e', "ee"},
  {'f', "eff"},
  {'g', "gee"},
  {'h', "aytch"},
  {'0', "zero"},
  {'1', "one"},
  {'2', "two"},
  {'3', "three"},
  {'4', "four"},
  {'5', "five"},
  {'6', "six"},
  {'7', "seven"},
  {'8', "eight"},
  {'=', "promoting to"},
  {'-', "to"}
};

const std::unordered_map<std::string, std::string> unique_san_expansion_map = {
  {"O-O", "short castles "},
  {"O-O-O", "long castles "},
};


bool checkForUniqueSan() {
  /* eliminate cases which are certainly not unique */
  return false;
}


std::string detectUniqueSanTranslation(const std::string& san) {
  return std::string("no");
}


std::string expandSanToHumanReadableString(const std::string& san) {
  std::vector<char> move_characters(san.begin(), san.end());
  std::string expanded_san = "";

  if (san[0] == 'O') {
    return unique_san_expansion_map.at(san);
  }

  for (auto const& character : move_characters) {
    expanded_san += basic_character_expansion_map.at(character);
    expanded_san += " ";
  }

  return expanded_san;
}


}



#endif /* expandSanToHumanReadableString_cpp */

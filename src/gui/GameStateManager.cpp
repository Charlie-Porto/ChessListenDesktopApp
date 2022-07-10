#ifndef GameStateManager_h
#define GameStateManager_h

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
class to assist with managing the state of the chess game
for the ListenPanel
-----------------------------------------------------------------*/

#include "GameStateManager.h"
#include "../backend/convertTextFileToString.cpp"
#include "../backend/convertPgnStringToArrayOfSanMoves.cpp"
#include "../backend/expandSanToHumanReadableString.cpp"
#include "../backend/createFliteAudioFileForMove.cpp"

namespace chl {


chl::GameStateManager::GameStateManager() {
  current_move_index_ = -1;
  current_move_file_path_ = "";
  move_list_ = {};
}

void chl::GameStateManager::SetMoveListBasedOnGuiInputText(const std::string& text, bool is_file_path) {
  /* recall: if is_file_path is false, text is a raw pgn; need to check if file or raw */  
  std::string game_string = text;
  if (is_file_path) {
    game_string = kelpfile::convertTextFileToString(text.c_str());
  }

  const std::vector<std::string> game_moves = chl::convertPgnStringToArrayOfSanMoves(game_string);
  /* create expanded san for each move */ 
  move_list_ = {};
  for (auto const& san : game_moves) {
    const std::string expanded_san = chl::expandSanToHumanReadableString(san);
    move_list_.push_back(expanded_san);
  }

}

void chl::GameStateManager::GenerateWavFileForCurrentMove() {
  int a = chl::createFliteAudioFileForMove(move_list_[current_move_index_]);
}







}



#endif /* GameStateManager_h */

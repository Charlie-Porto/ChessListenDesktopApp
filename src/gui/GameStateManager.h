#ifndef GameStateManager_cpp
#define GameStateManager_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
class to assist with managing the state of the chess game
for the ListenPanel
-----------------------------------------------------------------*/

#include <vector>
#include <string>
#include <ezprint.cpp>


namespace chl {

class GameStateManager {
public:
  GameStateManager();
  void SetMoveListBasedOnGuiInputText(const std::string& text, bool is_file_path);
  std::string GetPathOfCurrentMoveWavFile() const;
  void GenerateWavFileForCurrentMove();
  void DestroyWavFileForCurrentMove();
       
  size_t current_move_index_;
private:
  std::string current_move_file_path_;
  std::vector<std::string> move_list_;
};






}



#endif /* GameStateManager_cpp */
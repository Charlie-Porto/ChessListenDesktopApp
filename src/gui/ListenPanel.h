#ifndef ListenPanel_h
#define ListenPanel_h

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/button.h>
#include "GameStateManager.h"

namespace chl {

class ListenPanel : public wxPanel {
public:
  ListenPanel(wxPanel* parent);

  void ClickGoBack(wxCommandEvent& event);
  void ClickSayNextMove(wxCommandEvent& event);
  void ClickRepeatMove(wxCommandEvent& event);
  void ClickReturnToFirstMove(wxCommandEvent& event);
  void SetGameManagerMoveListInputFromUploadPanel(const std::string& text, const bool is_file_path);

  wxPanel* parent_;


  /* buttons */
  wxButton* read_next_move_button_;
  wxButton* repeat_move_button_;
  wxButton* return_to_before_first_move_button_;
  wxButton* back_button_;


private:
  GameStateManager* game_state_manager_; 
  int next_move_number_to_read_;
  void ReadNextMove();

};

}




#endif /* ListenPanel_h */

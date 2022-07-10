#ifndef ListenPanel_cpp
#define ListenPanel_cpp

#include <iostream>
#include "ListenPanel.h"
#include "MainWindow.h"
#include <ezprint.cpp>
#include "../backend/playWavAudioFile.cpp"

namespace chl {

ListenPanel::ListenPanel(wxPanel* parent) 
    : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(620, 400), wxBORDER_SUNKEN) {

  parent_ = parent; 
  wxBoxSizer* button_sizer = new wxBoxSizer( wxHORIZONTAL );

  /* buttons */
  back_button_ = new wxButton(this, 101, wxT("go back"), wxPoint(-1, -1), wxSize(80, 30));
  read_next_move_button_ = new wxButton(
      this, 102, wxT("say next move"), wxPoint(210, 200), wxSize(200, 50));
  return_to_before_first_move_button_ = new wxButton(
      this, 103, wxT("go to start"), wxPoint(100, 200), wxSize(100, 50));
  button_sizer->Add(back_button_, 0, wxALL, 5);

  /* button events */
  Connect(102, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ListenPanel::ClickSayNextMove));
  Connect(103, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ListenPanel::ClickReturnToFirstMove));
  Connect(101, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ListenPanel::ClickGoBack));

  game_state_manager_ = new GameStateManager();
  next_move_number_to_read_ = 0;
}


void ListenPanel::SetGameManagerMoveListInputFromUploadPanel(const std::string& text, const bool is_file_path) {
  game_state_manager_->SetMoveListBasedOnGuiInputText(text, is_file_path);
}


void ListenPanel::ClickGoBack(wxCommandEvent& event) {
  MainWindow* main_window = (MainWindow *) parent_->GetParent();
  main_window->SwitchPanels();
}


void ListenPanel::ClickReturnToFirstMove(wxCommandEvent& event) {
  game_state_manager_->current_move_index_ = -1;
}


void ListenPanel::ClickSayNextMove(wxCommandEvent& event) {
  ++game_state_manager_->current_move_index_; 
  game_state_manager_->GenerateWavFileForCurrentMove();
  const char* file_name = "/Users/charlieporto/realshit/cppstuff/sandbox/gui_experiments/ChessListenDesktopApp/ChessListenMove_TempFile.wav";
  chl::playWavAudioFile(file_name);
}

}



#endif /* ListenPanel_cpp */

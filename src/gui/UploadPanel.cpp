#ifndef UploadPanel_cpp
#define UploadPanel_cpp


#include "UploadPanel.h"
#include "MainWindow.h"
#include <ezprint.cpp>
#include "upload_panel/functions/detectIfTextIsFilePathOrRawPgn.cpp"


namespace chl {


UploadPanel::UploadPanel(wxPanel* parent)
    : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_SUNKEN) {

  parent_ = parent;
  text_control_ = new wxTextCtrl(this, 101, wxT(""), wxPoint(110, 50),
        wxSize(400, 200), wxTE_MULTILINE);    

  Connect(101, wxEVT_TEXT, wxCommandEventHandler(UploadPanel::OnTextUpdate));

  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
  hbox->Add(text_control_, 0, wxEXPAND | wxALL, 5);
  
  /* text labels */
  text_label_ = new wxStaticText(this, 102, wxT("In the box below, enter a .pgn filepath or paste a game's raw pgn"), wxPoint(110, 30));
  detection_label_ = new wxStaticText(this, 103, wxT("detected: "), wxPoint(250, 252));
  detection_text_ = new wxStaticText(this, 104, wxT("nothing"), wxPoint(320, 252));
  warning_text_ = new wxStaticText(this, 106, wxT(""), wxPoint(140, 330));

  /* buttons */
  listen_button_ = new wxButton(this, 105, wxT("Listen To Game"), wxPoint(200, 265), wxSize(200, 90));
  Connect(105, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(UploadPanel::LaunchListen));

  /* private items */ 
  text_box_status_ = 0;
}


void UploadPanel::OnTextUpdate(wxCommandEvent& event) {
  const int line_count = text_control_->GetNumberOfLines();
  text_box_text_ = "";

  for (int i = 0; i < line_count; ++i) {
    wxString line_content = text_control_->GetLineText(i);
    const std::string str_line_content = std::string(line_content.mb_str());
    text_box_text_ += str_line_content;
  }

  const int is_pgn_filepath = detectIfTextIsFilePathOrRawPgn(text_box_text_);
  wxString new_label = wxT("nothing");
  switch (is_pgn_filepath) {
    case 1:
      new_label = wxT("pgn file path");
      text_box_status_ = 1;
      break;
    case 2:
      new_label = wxT("raw pgn text");
      text_box_status_ = 2;
      break;
    default:
      text_box_status_ = 0;
      break;
  }

  /* set new label */
  detection_text_->SetLabel(new_label);

}

void UploadPanel::LaunchListen(wxCommandEvent& event) {
  if (text_box_status_ == 0) {
    warning_text_->SetLabel(wxString::Format(wxT("HOLD UP: please enter a pgn filepath or raw pgn text")));
  } else {
    warning_text_->SetLabel(wxString::Format(wxT("")));
    bool is_file_path = true;
    if (text_box_status_ == 2) { is_file_path = false; }

    MainWindow* main_window = (MainWindow *) parent_->GetParent();
    main_window->SwitchPanels();
    main_window->listen_panel_->SetGameManagerMoveListInputFromUploadPanel(text_box_text_, is_file_path);
  }
}


}


#endif /* UploadPanel_cpp */

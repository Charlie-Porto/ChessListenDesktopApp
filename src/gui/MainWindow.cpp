#ifndef MainWindow_cpp
#define MainWindow_cpp

#include "MainWindow.h"
#include <ezprint.cpp>

namespace chl {

MainWindow::MainWindow(const wxString& title) 
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(620, 400)) {
  
  parent_panel_ = new wxPanel(this, wxID_ANY);
  wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);

  upload_panel_ = new UploadPanel(parent_panel_);
  hbox->Add(upload_panel_, 1, wxEXPAND | wxALL, 5);
  listen_panel_ = new ListenPanel(parent_panel_);
  hbox->Add(listen_panel_, 1, wxEXPAND | wxALL, 5);
  listen_panel_->Hide();
  parent_panel_->SetSizer(hbox);
}

void MainWindow::SwitchPanels() {
  if (upload_panel_->IsShown()) {
    upload_panel_->Hide();
    listen_panel_->Show();
  } else {
    upload_panel_->Show();
    listen_panel_->Hide();
  }
}

}


#endif /* MainWindow_cpp */

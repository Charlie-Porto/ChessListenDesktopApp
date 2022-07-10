#ifndef MainWindow_h
#define MainWindow_h

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
the main window for the program.
-----------------------------------------------------------------*/

#include <wx/wx.h>
#include "UploadPanel.h"
#include "ListenPanel.h"

namespace chl {

class MainWindow : public wxFrame {
public:
  MainWindow(const wxString& title);

  void SwitchPanels();

  wxPanel* parent_panel_;
  UploadPanel* upload_panel_;
  ListenPanel* listen_panel_;
};

}




#endif /* MainWindow_h */

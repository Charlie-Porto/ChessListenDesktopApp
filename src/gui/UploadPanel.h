#ifndef UploadPanel_h
#define UploadPanel_h

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
panel for uploading chess games
-----------------------------------------------------------------*/

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace chl {

class UploadPanel : public wxPanel {
public:
  UploadPanel(wxPanel* parent); 

  void OnTextUpdate(wxCommandEvent & event);
  void LaunchListen(wxCommandEvent & event);

  wxPanel *parent_;
  wxTextCtrl* text_control_;

  /* text labels */
  wxStaticText* text_label_;
  wxStaticText* detection_label_;
  wxStaticText* detection_text_;
  wxStaticText* warning_text_;

  /* buttons */
  wxButton* listen_button_;

private:
  std::string text_box_text_;
  int text_box_status_;

};


}




#endif /* UploadPanel_h */

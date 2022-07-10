#include "main.h"
// #include "Communicate.h"
#include "gui/MainWindow.h"
#include "flite.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

    // Communicate *communicate = new Communicate(wxT("Widgets communicate"));
    // communicate->Show(true);
    chl::MainWindow* main_window = new chl::MainWindow(wxT("Chess Listen: prototype"));
    main_window->Show(true);
    return true;
}

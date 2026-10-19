#include "AppFrame.h"

AppFrame::AppFrame(wxWindow* parent)
    : AppFrameBase(parent, wxID_ANY, "wxWidgets Boilerplate", wxDefaultPosition,
                   wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxMINIMIZE_BOX)
{
}

void AppFrame::OnClose(wxCloseEvent&)
{
    Destroy();
}

void AppFrame::OnExit(wxCommandEvent&)
{
    Close();
}

void AppFrame::OnMinimize(wxCommandEvent&)
{
    Iconize(true);
}

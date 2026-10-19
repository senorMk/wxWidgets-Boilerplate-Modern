#include "App.h"
#include "AppFrame.h"

#include <wx/cmdline.h>
#include <wx/image.h>

wxIMPLEMENT_APP(TemplateApp);

void TemplateApp::OnInitCmdLine(wxCmdLineParser& parser)
{
    wxApp::OnInitCmdLine(parser);
    parser.AddSwitch("", "smoke-test", "Open the window, then close it.");
}

bool TemplateApp::OnCmdLineParsed(wxCmdLineParser& parser)
{
    smokeTest = parser.Found("smoke-test");
    return wxApp::OnCmdLineParsed(parser);
}

bool TemplateApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    SetAppName("wxWidgets Boilerplate");
    wxInitAllImageHandlers();

    auto* frame = new AppFrame(nullptr);
    SetTopWindow(frame);
    frame->Show();

    if (smokeTest)
    {
        CallAfter([frame] {
            wxCommandEvent exitEvent(wxEVT_BUTTON, frame->GetExitButton()->GetId());
            frame->GetExitButton()->GetEventHandler()->ProcessEvent(exitEvent);
        });
    }
    return true;
}

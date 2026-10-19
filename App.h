#pragma once

#include <wx/app.h>

class TemplateApp final : public wxApp
{
public:
    bool OnInit() override;
    void OnInitCmdLine(wxCmdLineParser& parser) override;
    bool OnCmdLineParsed(wxCmdLineParser& parser) override;

private:
    bool smokeTest = false;
};

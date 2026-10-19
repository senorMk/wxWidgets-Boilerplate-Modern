#pragma once

#include "AppFrameBase.h"

class AppFrame final : public AppFrameBase
{
public:
    explicit AppFrame(wxWindow* parent);

protected:
    void OnClose(wxCloseEvent& event) override;
    void OnExit(wxCommandEvent& event) override;
    void OnMinimize(wxCommandEvent& event) override;
};

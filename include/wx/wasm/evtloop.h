///////////////////////////////////////////////////////////////////////////////
// Name:        wx/wasm/evtloop.h
// Purpose:
// Author:      Adam Hilss
// Copyright:   (c) 2019 Adam Hilss
// Licence:     LGPL v2
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_WASM_EVTLOOP_H_
#define _WX_WASM_EVTLOOP_H_

#include "wx/evtloop.h"

// ----------------------------------------------------------------------------
// wxGUIEventLoop for wxWebAssembly
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_CORE wxGUIEventLoop : public wxEventLoopBase
{
public:
    wxGUIEventLoop() {}

    bool IsOk() const override { return true; }

    bool Pending() const override;
    bool Dispatch() override;
    int DispatchTimeout(unsigned long timeout) override;
    void WakeUp() override;

protected:
    int DoRun() override;
    virtual void DoStop(int rc) override;
    void DoYieldFor(long eventsToProcess) override;

private:
    wxDECLARE_NO_COPY_CLASS(wxGUIEventLoop);
};

#endif // _WX_WASM_EVTLOOP_H_

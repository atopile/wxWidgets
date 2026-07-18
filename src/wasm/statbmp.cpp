/////////////////////////////////////////////////////////////////////////////
// Name:        src/wasm/statbmp.cpp
// Purpose:     wxStaticBitmap implementation for the WASM DOM port
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#if wxUSE_STATBMP

#include "wx/statbmp.h"

#include "wx/wasm/private/dom.h"

wxStaticBitmap::wxStaticBitmap()
{
}

wxStaticBitmap::wxStaticBitmap(wxWindow *parent,
                               wxWindowID id,
                               const wxBitmapBundle& label,
                               const wxPoint& pos,
                               const wxSize& size,
                               long style,
                               const wxString& name)
{
    Create(parent, id, label, pos, size, style, name);
}

bool wxStaticBitmap::Create(wxWindow *parent,
                            wxWindowID id,
                            const wxBitmapBundle& label,
                            const wxPoint& pos,
                            const wxSize& size,
                            long style,
                            const wxString& name)
{
    if (!wxControl::Create(parent, id, pos, size, style, wxDefaultValidator, name))
        return false;

    WasmCreateDomNode("image");

    // pushes the initial bitmap to the <img> created above
    SetBitmap(label);

    return true;
}

void wxStaticBitmap::SetBitmap(const wxBitmapBundle& bitmap)
{
    m_bitmapBundle = bitmap;

    if (WasmGetDomId())
    {
        // Select the representation for the current display scale. The PNG
        // keeps its physical pixels while the dimensions passed below remain
        // logical CSS pixels.
        const wxBitmap bmp = m_bitmapBundle.GetBitmapFor(this);
        if (bmp.IsOk())
            wxDomSetImageDataURL(WasmGetDomId(), wxDomBitmapToDataURL(bmp),
                                 bmp.GetWidth(), bmp.GetHeight());
    }

    InvalidateBestSize();
}

#endif // wxUSE_STATBMP

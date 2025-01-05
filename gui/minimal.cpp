#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;
    MyFrame *frame = new MyFrame("Minimal wxWidgets App");
    frame->Show(true);
    return true;
}

class ScrolledWindow : public wxScrolledWindow {
public:
  ScrolledWindow(wxWindow* parent)
      : wxScrolledWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                         wxVSCROLL | wxALWAYS_SHOW_SB) {
    auto vbox = new wxBoxSizer(wxVERTICAL);
    for (int i = 0; i < 50; i++) vbox->Add(new wxStaticText(this, wxID_ANY, "foobar"));
    vbox->FitInside(this);
    SetSizer(vbox);
    SetScrollRate(0, 10);
  }
};

// frame constructor
MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
    auto vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(new ScrolledWindow(this));    
    SetSizer(vbox);
}

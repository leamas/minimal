#include <iostream>
#include <ios>

#include "wx/wx.h"
#include "wx/settings.h"
#include "wx/sizer.h"
#include "wx/dirdlg.h"

class Panel : public wxPanel {
public:
  Panel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    auto vbox = new wxBoxSizer(wxVERTICAL);
    wxDirDialog dlg(this);
    //vbox->Add(d, wxSizerFlags().Expand());

    SetSizer(vbox);
    dlg.ShowModal();
  }
};

class Frame : public wxFrame {
public:
  Frame(const wxString& title): wxFrame(NULL, wxID_ANY, title) {
    auto vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(new Panel(this), wxSizerFlags(1).Expand());
    SetSizer(vbox);
  }
};

class TheApp : public wxApp {
public:
  virtual bool OnInit() {
    if (!wxApp::OnInit()) return false;
    auto* frame = new Frame("Minimal wxWidgets App");
    frame->Show(true);
    return true;
  };
};

IMPLEMENT_APP(TheApp)

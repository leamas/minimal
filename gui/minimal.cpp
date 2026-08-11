#include <iostream>
#include <ios>

#include "wx/wx.h"
#include "wx/settings.h"

class Panel : public wxPanel {
public:
  Panel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    auto color = wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND);
    std::cout << "Background: " << std::hex << color.GetRGB() << "\n";
    SetBackgroundColour(color);
    color = wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT);
    std::cout << "Foreground: " << std::hex << color.GetRGB() << "\n";
    SetForegroundColour(color);

    auto vbox = new wxBoxSizer(wxVERTICAL);
    for (int i = 0; i < 20; i++)
      vbox->Add(new wxStaticText(this, wxID_ANY, "bar"));
    SetSizer(vbox);
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

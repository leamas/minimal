#include <iostream>
#include <ios>
#include "wx/wx.h"
#include "wx/settings.h"

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
  MyFrame(const wxString& title);
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
  if (!wxApp::OnInit()) return false;
  MyFrame* frame = new MyFrame("Minimal wxWidgets App");
  frame->Show(true);
  return true;
}

class Frame : public wxFrame {
public:
  Frame(wxWindow* parent)
      : wxFrame(parent, wxID_ANY, "Foo") {
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

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {
  auto vbox = new wxBoxSizer(wxVERTICAL);
  vbox->Add(new Frame(this), wxSizerFlags(1).Expand());
  SetSizer(vbox);
}

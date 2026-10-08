#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/string.h>

static wxString UtfCheckMark() { return wxString::FromUTF8(reinterpret_cast<const char*>(u8"\u2713")); }
static wxString UtfGear() { return wxString::FromUTF8(reinterpret_cast<const char*>(u8"\u2699")); }
static wxString UtfCircle() { return wxString::FromUTF8(reinterpret_cast<const char*>(u8"\u25cf")); }
static wxString UtfWastebasket() { return wxString::FromUTF8(reinterpret_cast<const char*>(u8"\U0001f5d1")); }

class Panel : public wxPanel {
public:
  Panel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    auto vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(new wxStaticText(this, wxID_ANY, wxString("Gear: ") + UtfGear()));
    vbox->Add(new wxStaticText(this, wxID_ANY, wxString("check mark: ") + UtfCheckMark()));
    vbox->Add(new wxStaticText(this, wxID_ANY, wxString("Wastebasket: ") + UtfWastebasket()));
    vbox->Add(new wxStaticText(this, wxID_ANY, wxString("Circle: ") + UtfCircle()));
    SetSizer(vbox);
    Layout();
    Show();
  }
};

class Frame : public wxFrame {
public:
  Frame(const wxString& title): wxFrame(NULL, wxID_ANY, title) {
    auto vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(new Panel(this), wxSizerFlags().Expand());
    SetSizer(vbox);
    SetClientSize( 50 * GetCharWidth(), 21* GetCharHeight());
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

#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <wx/uri.h>

int main(int argc, char**argv) {
  std::stringstream ss;
  ss << 45 << "%";
  std::cout << ss.str() << "\n";

  wxURI url("https:/www.dhn.mil.pe/Archivos/cartografia/cartas_raster/cartas/BSB_111.rar");
  std::cout << "IsReference: " << (url.IsReference() ? "true\n" : "false\n");

  std::string s("https:/www.dhn.mil.pe/Archivos/cartografia/cartas_raster/cartas/BSB_111.rar");
  std::regex bad_prefix("^https:/([^/])");
  std::string s2 = std::regex_replace(s, bad_prefix, "https://$1");

  wxURI url2(s2);
  std::cout << "s2: " << s2 << "\n";
  std::cout << "IsReference2: " << (url2.IsReference() ? "true\n" : "false\n");
}

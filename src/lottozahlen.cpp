/*
 * lottozahlen.cpp
 *
 *  Created on: 03.03.2015
 *      Author: aboettger
 */

#include <glibmm/fileutils.h>
#include <glibmm/markup.h>
#include <glibmm/refptr.h>
#include <glibmm/ustring.h>
#include <gtkmm/builder.h>
#include <gtkmm/label.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <iostream>
#include <string>

#include "Lotto.h"

#define UI_FILE "ui/main.glade"

void
fireValues (Glib::RefPtr<Gtk::Builder> refBuilder)
{
  Lotto lotto;
  Gtk::Label* pLabel = 0;
  auto i = 0;
  for (auto value : lotto.getLottozahlen ())
    {
      refBuilder->get_widget ("lblZahl" + std::to_string (++i), pLabel);
      pLabel->set_text (std::to_string (value));
    }

  auto superzahl = std::to_string (lotto.getSuperzahl ());
  refBuilder->get_widget ("lblSuperzahl", pLabel);
  pLabel->set_text (superzahl);
}

int
main (int argc, char **argv)
{
  Gtk::Main kit (argc, argv);

  Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create ();
  try
    {
      refBuilder = Gtk::Builder::create_from_file (UI_FILE);
    }
  catch (const Glib::FileError& ex)
    {
      std::cerr << "FileError: " << ex.what () << std::endl;
      return (1);
    }
  catch (const Glib::MarkupError& ex)
    {
      std::cerr << "MarkupError: " << ex.what () << std::endl;
      return (1);
    }
  catch (const Gtk::BuilderError& ex)
    {
      std::cerr << "BuilderError: " << ex.what () << std::endl;
      return (1);
    }

  fireValues (refBuilder);

  Gtk::Window* pWindow = 0;
  refBuilder->get_widget ("mainWindow", pWindow);
  kit.run (*pWindow);

  return (0);
}

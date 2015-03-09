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
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <iostream>

#include "Lotto.h"

#define UI_FILE "ui/main.glade"

Gtk::Window* pWindow = 0;
Gtk::Label* pLabel = 0;

int
main (int argc, char **argv)
{
  Lotto lotto;
  std::cout << "Lottozahlen: ";
  for (auto value : lotto.getLottozahlen ())
    {
      std::cout << value << " ";
    }

  std::cout << std::endl;

  std::cout << "Zusatzzahl: " << lotto.getZusatzzahl ();

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

  refBuilder->get_widget ("mainWindow", pWindow);
  refBuilder->get_widget ("label_1", pLabel);

  kit.run (*pWindow);

  return (0);
}

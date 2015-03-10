/*
 * Lotto.cpp
 *
 *  Created on: 04.03.2015
 *      Author: aboettger
 */

#include "Lotto.h"

#include <initializer_list>
#include <iostream>

std::random_device rd;
std::mt19937 engine (rd ());
std::uniform_int_distribution<int> dist1to49 (1, 49);
std::uniform_int_distribution<int> dist0to9 (0, 9);

Lotto::Lotto ()
{
  refresh ();
}

Lotto::~Lotto ()
{
}

auto
Lotto::getLottozahlen () -> decltype(lottozahlen)
{
  return (lottozahlen);
}

void
Lotto::refresh ()
{
  lottozahlen =
    {};
  for (std::size_t i = 0; i < this->MAX_LOTTOZAHLEN; ++i)
    {
      auto isExisting = false;
      auto lottozahl = 0;
      auto j = 0;

      do
	{
	  ++j;
	  isExisting = false;
	  lottozahl = dist1to49 (engine);

	  for (auto value : lottozahlen)
	    {
	      if (value == lottozahl)
		{
		  isExisting = true;
		  break;
		}
	    }

	}
      // Wiederholung, wenn Zahl schon existiert (isExisting) oder mehr Zahlen (MAX_LOTTOZAHLEN)
      // angefordert werden, als geliefert werden können (dist1to49.max())
      while (isExisting && j < dist1to49.max ());

      lottozahlen.push_back (lottozahl);
    }

  std::sort (lottozahlen.begin (), lottozahlen.end (), [](int a, int b)
	{ return (a<b);});
//  auch möglich:
//  std::sort (lottozahlen.begin (), lottozahlen.end ());
}

auto
Lotto::getSuperzahl ()-> decltype (dist0to9 (engine))
{
  return (dist0to9 (engine));
}

/*
 * Lotto.cpp
 *
 *  Created on: 04.03.2015
 *      Author: aboettger
 */

#include "Lotto.h"

#include <algorithm>
#include <random>

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

std::vector<int>
Lotto::getLottozahlen ()
{
  return (lottozahlen);
}

void
Lotto::refresh ()
{
  lottozahlen = {};
  for (std::size_t i = 0; i < this->MAX_LOTTOZAHLEN; ++i)
    {
      bool flag = false;
      int lottozahl = 0;
      do
	{
	  flag = false;
	  lottozahl = dist1to49 (engine);
	  for (auto& value : lottozahlen)
	    {
	      if (value == lottozahl)
		{
		  flag = true;
		  break;
		}
	    }
	}
      while (flag);
      lottozahlen.push_back (lottozahl);
    }
  std::sort (lottozahlen.begin (), lottozahlen.end ());
}

int
Lotto::getZusatzzahl ()
{
  return (dist0to9 (engine));
}

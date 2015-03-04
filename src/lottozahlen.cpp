/*
 * lottozahlen.cpp
 *
 *  Created on: 03.03.2015
 *      Author: aboettger
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

#include "Lotto.h"

int
main (int argc, char **argv)
{
  Lotto lotto;
  lotto.refresh ();
  std::cout << "Lottozahlen: ";
  for (auto& value : lotto.getLottozahlen ())
    {
      std::cout << value << " ";
    }

  std::cout << std::endl;

  std::cout << "Zusatzzahl: " << lotto.getZusatzzahl ();

  return (0);
}

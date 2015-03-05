/*
 * Lotto.h
 *
 *  Created on: 04.03.2015
 *      Author: aboettger
 */

#ifndef LOTTO_H_
#define LOTTO_H_

#include <cstddef>
#include <vector>

class Lotto
{

public:
  Lotto ();                      // der Default-Konstruktor
//  Lotto (int a = 0);       // weiterer Konstruktor mit Parameter und Defaultwert
//  Lotto (const Lotto& a);   // Copy-Konstruktor
  ~Lotto ();                     // der Destruktor

  auto
  getLottozahlen () -> std::vector<int>;     // eine Funktion mit einem (Default-) Parameter

  auto
  getZusatzzahl () -> int;

  void
  refresh ();

private:
  std::size_t const MAX_LOTTOZAHLEN = 6;
  std::vector<int> lottozahlen;
};

#endif /* LOTTO_H_ */

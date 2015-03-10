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
protected:
  // Direkte Initialisierung, Kopierinitialisierung: std::size_t const MAX_LOTTOZAHLEN = 6;
  std::size_t const MAX_LOTTOZAHLEN
    { 6 };
  std::vector<int> lottozahlen;

public:
  Lotto ();                      // der Default-Konstruktor
//  Lotto (int a = 0);       // weiterer Konstruktor mit Parameter und Defaultwert
//  Lotto (const Lotto& a);   // Copy-Konstruktor
  ~Lotto ();                     // der Destruktor

  auto
  getLottozahlen () -> decltype(lottozahlen);

  auto
  getSuperzahl () -> int;

  void
  refresh ();

private:
};

#endif /* LOTTO_H_ */

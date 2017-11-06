#include "TelBuch.h"
#include <iostream>

TelBuch::TelBuch(std::string numPrivat, std::string numWork, std::string numMobile)
{
   NumberPrivat = numPrivat;
   NumberWork = numWork;
   NumberMobile = numMobil;
}

TelBuch::~TelBuch()
{
}

void TelBuch::setNumPrivat(std::string numPrivat)
{
   NumberPrivat = numPrivat;
}

void TelBuch::setNumWork(std::string numWork)
{
   NumberWork = numWork;
}

void TelBuch::setNumMobil(std::string numMobil)
{
   NumberMobil = numMobil;
}

std::string TelBuch::getNumPrivat()
{
   return NumberPrivat;
}

std::string TelBuch::getNumWork()
{
   return NumberWork;
}

std::string TelBuch::getNumMobil()
{
   return NumberMobil;
}
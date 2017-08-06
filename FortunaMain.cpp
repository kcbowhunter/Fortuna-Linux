// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdio>
#include "Fortuna.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
   printf("\nHello Fortuna-Linux!\n\n");

   auto *pFortuna = new Fortuna();

   sleep(3);

   delete pFortuna;

   return 0;
}

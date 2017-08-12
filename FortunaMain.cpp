// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdio>
#include "Fortuna.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
   pid_t pid = getpid();
   printf("\nHello Fortuna-Linux!\n   pid=%lu\n", (unsigned long)pid);

   auto *pFortuna = new Fortuna();

    int count = 0;
   int seconds = 5;
    for (int i=0; i<seconds; ++i)
    {
        sleep(1);
        printf("FortunaMain %d seconds\n", ++count);
    }


   delete pFortuna;

   return 0;
}

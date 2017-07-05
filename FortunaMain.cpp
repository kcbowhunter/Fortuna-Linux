
#include <stdio.h>
#include "Fortuna.h"
#include <unistd.h>


int main(int argc, char* argv[])
{
   printf("\nHello Fortuna-Linux!\n\n");

   Fortuna *pFortuna = new Fortuna();

   sleep(3);

   delete pFortuna;

   return 0;
}

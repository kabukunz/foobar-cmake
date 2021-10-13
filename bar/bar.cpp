// bar.cpp

#include "bar.h"
#include <stdlib.h>
#include <time.h>

bar::bar(){}

bar::~bar(){}

int bar::rmn() {
    srand(time(NULL));
    num = rand() % 5 + 1;
    return num;
}

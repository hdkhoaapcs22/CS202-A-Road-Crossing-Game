#include <time.h>
#include "src/gui/Application.h"

int main(void) {
    srand(time(NULL));
    Application app;
    app.run();
    return 0;
}
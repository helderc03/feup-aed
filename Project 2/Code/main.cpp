#include <fstream>
#include "Manager.h"
#include "Menu.h"


int main() {
    Manager manager;
    manager.init();
    Menu m;
    m.menuController(manager);

    return 0;
}
#include "gui/gui.hpp"

int main(int argc, char const *argv[]) {
    minesweeper::gui gui(1024, 1024, 16, 16);

    gui.start();

    return 0;
}

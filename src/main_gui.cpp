#include "gui/gui.hpp"

int main(int argc, char const *argv[]) {
    int square_size = 48;

    int rows = 16;
    int cols = 16;

    minesweeper::gui gui(
        square_size * rows,
        square_size * cols,
        rows,
        cols
    );

    gui.start();

    return 0;
}

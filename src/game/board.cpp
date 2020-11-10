#include "board.hpp"

#include <cstring>
#include <math.h>

void minesweeper::board::reveal_recursive(size_t posx, size_t posy) {
    if (posx >= 0 && posx < m_width &&
        posy >= 0 && posy < m_height) {
            node *cell = get_cell(posx, posy);

            if (!cell->get_visited()) {
                cell->set_visited(true);
                cell->set_display(true);

                if (!cell->get_mine() && !cell->get_adj_count())
                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++)
                            reveal_recursive(posx + dx, posy + dy);
            }
    }
}

minesweeper::board::board(size_t width, size_t height) {
    m_width = width;
    m_height = height;
    m_cells = new node[width * height];
}
minesweeper::board::~board() {
    delete[] m_cells;
}

void minesweeper::board::reset() {
    for (int y = 0; y < m_height; y++)
        for (int x = 0; x < m_width; x++)
            get_cell(x, y)->reset();
}

void minesweeper::board::init_board(int initialX, int initialY) {
    reset();
    int numMines = 0.2 * m_width * m_height;

    while (numMines) {
        int posx = rand() % m_width;
        int posy = rand() % m_height;
        
        int dx = abs(initialX - posx);
        int dy = abs(initialY - posy);

        if ((dx >= 3 || dy >= 3) && !get_cell(posx, posy)->get_mine()) {
            get_cell(posx, posy)->set_mine(true);
            numMines--;
        }
    }
    
    for (int y = 0; y < m_height; y++)
    for (int x = 0; x < m_width; x++)
    if (get_cell(x, y)->get_mine())
    for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++) {
        if (x + dx >= 0 && x + dx < m_width &&
            y + dy >= 0 && y + dy < m_height) {
                get_cell(x + dx, y + dy)->inc_adj_count();
        }
    }
}

minesweeper::node *minesweeper::board::get_cell(size_t x, size_t y) {
    return &m_cells[y * m_width + x];
}
size_t minesweeper::board::get_width() {
    return m_width;
}
size_t minesweeper::board::get_height() {
    return m_height;
}

void minesweeper::board::reveal(size_t posx, size_t posy) {
    for (int y = 0; y < m_height; y++)
        for (int x = 0; x < m_width; x++)
            get_cell(x, y)->set_visited(false);
    reveal_recursive(posx, posy);
}

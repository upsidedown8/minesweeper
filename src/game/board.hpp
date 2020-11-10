#if !defined(MINESWEEPER_GAME_BOARD_HPP)
#define MINESWEEPER_GAME_BOARD_HPP

#include "game/node.hpp"

namespace minesweeper {

class board {
private:
    size_t m_width, m_height;
    node *m_cells;

    void reveal_recursive(size_t posx, size_t posy);

public:
    board(size_t width, size_t height);
    ~board();

    void reset();

    void init_board(int initialX, int initialY);

    node *get_cell(size_t x, size_t y);
    size_t get_width();
    size_t get_height();

    void reveal(size_t posx, size_t posy);
};

}

#endif // MINESWEEPER_GAME_BOARD_HPP

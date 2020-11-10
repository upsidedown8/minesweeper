#if !defined(MINESWEEPER_GUI_GUI_HPP)
#define MINESWEEPER_GUI_GUI_HPP

#include <SFML/Graphics.hpp>

#include "game/board.hpp"

namespace minesweeper {

class gui {
private:
    sf::Texture red, flag, mine, empty, hidden, *numbers;
    sf::Sprite m_red, m_flag, m_mine, m_empty, m_hidden, *m_numbers;

    board *m_board;

    int width, height;
    int rows, cols;

    void draw_board(sf::RenderWindow &window, bool showMines);
    void scale_asset(sf::Sprite &asset);

public:
    gui(int w, int h, int rows, int cols);

    void start();
};

}

#endif // MINESWEEPER_GUI_GUI_HPP

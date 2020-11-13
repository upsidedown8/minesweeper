#include "gui.hpp"

void minesweeper::gui::draw_board(sf::RenderWindow &window, bool showMines) {
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int px = x * width / rows;
            int py = y * height / cols;

            node *cell = m_board->get_cell(x, y);
            if (cell->get_display() || (cell->get_mine() && showMines)) {
                if (cell->get_mine()) {
                    if (!cell->get_display()) {
                        m_empty.setPosition(px, py); window.draw(m_empty);
                    } else {
                        m_red.setPosition(px, py); window.draw(m_red);
                    }
                    m_mine.setPosition(px, py); window.draw(m_mine);
                } else {
                    m_empty.setPosition(px, py); window.draw(m_empty);
                    int adj = cell->get_adj_count();
                    if (adj) {
                        m_numbers[adj-1].setPosition(px, py);
                        window.draw(m_numbers[adj-1]);
                    }
                }
            } else {
                m_hidden.setPosition(px, py); window.draw(m_hidden);
                if (cell->get_flag()) {
                    m_flag.setPosition(px, py); window.draw(m_flag);
                }
            }
        }
    }
}
void minesweeper::gui::scale_asset(sf::Sprite &asset) {
    asset.setScale(sf::Vector2f(
        (float)width / rows / asset.getLocalBounds().width,
        (float)height / cols / asset.getLocalBounds().height
    ));
}

minesweeper::gui::gui(int w, int h, int rows, int cols) {
    width = w;
    height = h;
    this->rows = rows;
    this->cols = cols;

    red.loadFromFile("assets/tiles/red.png");
    flag.loadFromFile("assets/features/flag.png");
    mine.loadFromFile("assets/features/mine.png");
    empty.loadFromFile("assets/tiles/empty.png");
    hidden.loadFromFile("assets/tiles/hidden.png");

    m_red.setTexture(red);
    m_flag.setTexture(flag);
    m_mine.setTexture(mine);
    m_empty.setTexture(empty);
    m_hidden.setTexture(hidden);

    numbers = new sf::Texture[8];
    m_numbers = new sf::Sprite[8];

    for (int i = 0; i < 8; i++) {
        numbers[i].loadFromFile(("assets/numbers/"+std::to_string(i+1)+".png").c_str());
        m_numbers[i].setTexture(numbers[i]);
    }

    // scale assets
    scale_asset(m_red);
    scale_asset(m_flag);
    scale_asset(m_mine);
    scale_asset(m_empty);
    scale_asset(m_hidden);

    for (int i = 0; i < 8; i++)
        scale_asset(m_numbers[i]);

    m_board = new board(rows, cols);
}

void minesweeper::gui::start() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(width, height), "Minesweeper");


    bool displayMines = false, firstMove = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                int posx = event.mouseButton.x * rows / width;
                int posy = event.mouseButton.y * cols / height;
                node *cell = m_board->get_cell(posx, posy);
                if (!displayMines) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (firstMove) {
                            firstMove = false;
                            m_board->init_board(posx, posy);
                        }

                        // reveal adjacant
                        if (!cell->get_flag()) {
                            m_board->reveal(posx, posy);
                            if (m_board->mine_exploded() ||
                                m_board->all_mines_found())
                                displayMines = true;
                        }
                    } else {
                        cell->set_flag(!cell->get_flag());
                    }
                }
            }
        }

        window.clear(sf::Color::Black);
        draw_board(window, displayMines);
        window.display();
    }
}

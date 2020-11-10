#if !defined(MINESWEEPER_GAME_NODE_HPP)
#define MINESWEEPER_GAME_NODE_HPP

#include <vector>

namespace minesweeper {

class node {
private:
    bool m_visited, m_display, m_has_mine, m_has_flag;
    size_t m_adj_count;

public:
    node();

    void reset();

    bool get_visited();
    bool get_display();
    bool get_mine();
    bool get_flag();
    size_t get_adj_count();

    void set_visited(bool val);
    void set_display(bool val);
    void set_mine(bool val);
    void set_flag(bool val);
    void set_adj_count(size_t val);

    void inc_adj_count();
};

} // namespace minesweeper


#endif // MINESWEEPER_GAME_NODE_HPP

#include "node.hpp"

minesweeper::node::node() {
    reset();
}

void minesweeper::node::reset() {
    m_visited = false;
    m_display = false;
    m_has_mine = false;
    m_has_flag = false;
    m_adj_count = 0;
}

bool minesweeper::node::get_visited() {
    return m_visited;
}
bool minesweeper::node::get_display() {
    return m_display;
}
bool minesweeper::node::get_mine() {
    return m_has_mine;
}
bool minesweeper::node::get_flag() {
    return m_has_flag;
}
size_t minesweeper::node::get_adj_count() {
    return m_adj_count;
}

void minesweeper::node::set_visited(bool val) {
    m_visited = val;
}
void minesweeper::node::set_display(bool val) {
    m_display = val;
}
void minesweeper::node::set_mine(bool val) {
    m_has_mine = val;
}
void minesweeper::node::set_flag(bool val) {
    m_has_flag = val;
}
void minesweeper::node::set_adj_count(size_t val) {
    m_adj_count = val;
}

void minesweeper::node::inc_adj_count() {
    if (!get_mine())
        m_adj_count++;
}

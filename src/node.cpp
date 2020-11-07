#include "node.hpp"

minesweeper::node::node() {
    m_visited = false;
    m_display = false;
    m_has_mine = false;
}

bool minesweeper::node::is_visited() {
    return m_visited;
}
bool minesweeper::node::is_display() {
    return m_display;
}
bool minesweeper::node::has_mine() {
    return m_has_mine;
}

void minesweeper::node::set_mine(bool hasMine) {
    m_has_mine = hasMine;
}
void minesweeper::node::hide() {
    m_display = false;
}
void minesweeper::node::visit() {
    m_visited = true;
}
void minesweeper::node::unvisit() {
    m_visited = false;
}

void minesweeper::node::add_adjacant(node *adj) {
    m_adjacant.push_back(adj);
}
void minesweeper::node::reveal_adjacant() {
    visit();
    for (node *a : m_adjacant)
        if (!a->is_visited())
            a->reveal_adjacant();
}



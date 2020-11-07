#if !defined(MINESWEEPER_NODE_HPP)
#define MINESWEEPER_NODE_HPP

#include <vector>

namespace minesweeper {
    
class node {
private:
    std::vector<node*> m_adjacant;
    bool m_visited, m_display, m_has_mine;

public:
    node();
    
    bool is_visited();
    bool is_display();
    bool has_mine();

    void set_mine(bool hasMine);
    void hide();
    void visit();
    void unvisit();

    void add_adjacant(node *adj);
    void reveal_adjacant();

};

} // namespace minesweeper


#endif // MINESWEEPER_NODE_HPP

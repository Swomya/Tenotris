#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

#include "config.hpp"
#include "piece.hpp"

class Board
{
enum BlockStatus : int {block_empty, i_block, o_block, t_block, s_block, z_block, j_block, l_block};

public:
    Board ();
    int getTetromino (int r, int c);    
    bool isBlockFree (int r, int c);    
    bool isPositionLegal (Piece p);     
    void storePiece (Piece p);          
    void clearFullLines ();             
    bool isGameOver ();                 

private:
    BlockStatus board_state [config::playfield_height][config::playfield_width];
    std::vector<Piece> pieces;

    void deleteLine (int y);           
};

#endif 
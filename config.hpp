#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <SDL.h>

namespace config
{   
    // Title
    const char window_title[] = "Tetris";


    const int logical_window_width = 640;
    const int logical_window_height = 360;
    extern double resolution_scaling;                               // Scaling resolution
    extern double available_resolution_scalings[];                  // Resolution scalings
    const int starting_resolution_scaling_index = 4;                // available_resolution_scalings array index
    const int possible_resolution_scalings = 6;                     // No of resolution scalings

    // Board class
    const int width_to_playfield = 242;                             // in pixels
    const int height_to_playfield = 34;                             // in pixels
    const int block_size = 16;                                      // in pixels
    const int playfield_width = 10;                                 // in blocks
    const int true_playfield_height = 20;                           // in blocks
    const int playfield_height = 22;                                // above + 2 for spawn space
    const int frame_width = 6;                                      // Surrounding
    const int frame_sprite_size = 8;                                // Size of each sprite
    const int board_height = 2;                                    
    const int matrix_blocks = 5;                                    // tetromino info; in blocks

    // GameState class
    const int next_box_x = 405;                                     // Horizontal distance from top left corner; in pixels
    const int next_box_y = 10;                                      // Horizontal distance from top left corner; in pixels

    const int hold_box_x = 150;                                     // Horizontal distance from top left corner; in pixels
    const int hold_box_y = 10;                                      // Vertical distance from top left corner; in pixels

    // Constants relating to Tetris
    const int wait_time = 1000;                                     // Time in milliseconds
    extern bool ghost_piece_enabled;                                // Enables or disables the ghost piece to reduce misdrops

    // Visuals
    const SDL_Color default_text_color = {0x00, 0x00, 0x00, 0xFF};  // Default color for all text
    const Uint8 background_r_light = 0xF9;                          // Background color for light mode
    const Uint8 background_g_light = 0xE6;
    const Uint8 background_b_light = 0xCF;
    const Uint8 transparency_alpha = 100;                           // Default transparency value                       
}

#endif // CONFIG_HPP
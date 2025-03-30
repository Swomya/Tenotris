#include "graphics.hpp"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_render.h> 
#include <iostream>
#include <string>
#include "defines.hpp"

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr; 
static SDL_Texture* textureMap = nullptr;
static SDL_Rect bgsrc = { BLOCK_L, 0, WIN_WIDTH, WIN_HEIGHT };
static SDL_Rect blocksrc = { 0, 0, BLOCK_L, BLOCK_L };
static SDL_Rect blockdst = { 0, 0, BLOCK_L, BLOCK_L };
static TTF_Font* font;
static SDL_Texture* scoreText = nullptr;

bool loadAssets();
void destroyScoreText();

bool Graphics::init() {
    window = SDL_CreateWindow("Tetris", WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OCCLUDED);
    renderer = SDL_CreateRenderer(window, SDL_RENDERER_ACCELERATED);
    if (!window || !renderer) {
        LOG(SDL_GetError());
        SDL_ClearError();
        return false;
    }

    if (!loadAssets())
        return false;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    return true;
}

bool loadAssets() {
    SDL_Surface* s = nullptr;

        s = IMG_Load(TEXMAP);

        textureMap = SDL_CreateTextureFromSurface(renderer, s);


    if (s == nullptr)
        return false;

    SDL_DestroySurface(s);

    return true;
}

void Graphics::cleanup() {
    SDL_DestroyTexture(textureMap);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    destroyScoreText();
    TTF_CloseFont(font);
    TTF_Quit();
}

void Graphics::preRender() {
    SDL_RenderClear(renderer);
    SDL_FRect bgsrcF;
    SDL_RectToFRect(&bgsrc, &bgsrcF);
    SDL_RenderTexture(renderer, textureMap, &bgsrcF, nullptr);
}

void Graphics::drawBlock(int shape, int x, int y) {
    blocksrc.y = (shape - 1) * BLOCK_L;
    blockdst.x = x;
    blockdst.y = y;
    SDL_FRect blocksrcF, blockdstF;
    SDL_RectToFRect(&blocksrc, &blocksrcF);
    SDL_RectToFRect(&blockdst, &blockdstF);
    SDL_RenderTexture(renderer, textureMap, &blocksrcF, &blockdstF);
}


void Graphics::updateScore(int score) {
    std::string scoreT = "Score: " + std::to_string(score);

    destroyScoreText(); 

    SDL_Color textColor = { 255, 255, 255 };


    SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreT.c_str(), scoreT.length(), textColor);

    scoreText = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_DestroySurface(textSurface); 

}

void destroyScoreText() {
    if (scoreText) {
        SDL_DestroyTexture(scoreText);
        scoreText = nullptr;
    }
}


void Graphics::renderScore() {
    if (!scoreText) return; 

    SDL_Rect textDst = { SCORE_X, SCORE_Y, 96, 48 };
    SDL_FRect textDstF;
    SDL_RectToFRect(&textDst, &textDstF);

    SDL_RenderTexture(renderer, scoreText, nullptr, &textDstF);
}

void Graphics::present() {
    SDL_RenderPresent(renderer);
}
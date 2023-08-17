#include "Game.hpp"
#include <iostream>

bool Game::init(const char *title, int xpos, int ypos, int width, int height,
                int flags) {
  // attempt to initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL init success\n";
    // init the window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow != 0) // window init succesful
    {
      std::cout << "Window creation successful\n";
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0) // renderer init success
      {
        std::cout << "renderer creation successfull\n";
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
      } else {
        std::cout << "renderer init fail\n";
        return false; // renderer init fail
      }
    } else {
      std::cout << "window init fail\n";
      return false; // window init fail
    }
  } else {
    std::cout << "SDL init fail\n";
    return false; // SDL init fail
  }

  SDL_Surface *pTempSurface = SDL_LoadBMP("assets/animate.bmp");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  m_sourceRectangle.w = 128;
  m_sourceRectangle.h = 82;

  m_destinationRectangle.x = m_sourceRectangle.x = 0;
  m_destinationRectangle.y = m_sourceRectangle.y = 0;
  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;

  std::cout << "init success\n";
  m_bRunning = true; // everything inited, start the main loop

  return true;
}

void Game::render() {
  SDL_RenderClear(m_pRenderer); // clean the draw color

  // SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle,
  // &m_destinationRectangle);
  SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle,
                   &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);

  SDL_RenderPresent(m_pRenderer); // draw
}

void Game::update() {
  m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::handleEvents() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      m_bRunning = false;
      break;

    default:
      break;
    }
  }
}
void Game::clean() {
  std::cout << "cleaning game\n";
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

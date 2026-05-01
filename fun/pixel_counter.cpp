#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

int main() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
    std::cerr << SDL_GetError() << "\n";
    return 1;
  }

  if (TTF_Init() != 0) {
    std::cerr << TTF_GetError() << "\n";
    return 1;
  }

  SDL_DisplayMode dm;
  if (SDL_GetCurrentDisplayMode(0, &dm) != 0) {
    std::cerr << SDL_GetError() << "\n";
    return 1;
  }

  int width = dm.w;
  int height = dm.h;

  SDL_Window *window = SDL_CreateWindow("Pixel Counter", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, width, height,
                                        SDL_WINDOW_BORDERLESS);
  if (!window) {
    std::cerr << SDL_GetError() << "\n";
    return 1;
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << SDL_GetError() << "\n";
    return 1;
  }

  SDL_Texture *texture =
      SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24,
                        SDL_TEXTUREACCESS_STREAMING, width, height);
  if (!texture) {
    std::cerr << SDL_GetError() << "\n";
    return 1;
  }

  // SYSTEM FONT (reliable)
  TTF_Font *font = TTF_OpenFont(
      "/usr/share/fonts/dejavu-sans-fonts/DejaVuSans-Bold.ttf", 80);
  if (!font) {
    std::cerr << "Font error: " << TTF_GetError() << "\n";
    return 1;
  }

  int total_pixels = width * height;
  unsigned char *buffer = new unsigned char[total_pixels * 3];
  memset(buffer, 0, total_pixels * 3);

  int index = 0;
  int speed = 1;
  Uint32 lastTick = SDL_GetTicks();

  bool running = true;
  while (running) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        running = false;

      if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_UP)
          speed += 10;
        if (e.key.keysym.sym == SDLK_DOWN && speed > 1)
          speed -= 10;
      }
    }

    Uint32 current = SDL_GetTicks();

    if (current - lastTick >= 100) {
      for (int s = 0; s < speed && index < total_pixels; s++) {
        int i = index * 3;
        buffer[i] = 255;
        buffer[i + 1] = 255;
        buffer[i + 2] = 255;
        index++;
      }
      lastTick = current;
    }

    SDL_UpdateTexture(texture, NULL, buffer, width * 3);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    // render counter
    std::string text = std::to_string(index);
    SDL_Color color = {255, 0, 0};

    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface) {
      SDL_Texture *textTex = SDL_CreateTextureFromSurface(renderer, surface);
      if (textTex) {
        SDL_Rect dst = {(width - surface->w) / 2, (height - surface->h) / 2,
                        surface->w, surface->h};
        SDL_RenderCopy(renderer, textTex, NULL, &dst);
        SDL_DestroyTexture(textTex);
      }
      SDL_FreeSurface(surface);
    }

    SDL_RenderPresent(renderer);
  }

  delete[] buffer;
  TTF_CloseFont(font);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  TTF_Quit();
  SDL_Quit();
  return 0;
}

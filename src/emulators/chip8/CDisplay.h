//
// Created by valerino on 09/11/2017.
//

#ifndef PROJECT_CDISPLAY_H
#define PROJECT_CDISPLAY_H

#include "CMemory.h"
#include <CConfiguration.h>

/*
 * define different draw colors
 */
#define DRAW_COLOR_WHITE 0
#define DRAW_COLOR_GREEN 1

/**
 * implements the display subsystem
 */
class CDisplay {
public:
  /**
   * initializes the display
   * @param cfg the configuration instance
   * @param mem represents emulated memory
   * @throws if SDL fails
   */
  CDisplay(CConfiguration *cfg, CMemory *mem);
  ~CDisplay();

  /**
   * update the display
   */
  void update();

  /**
   * put a pixel at screen coordinates
   * @param x
   * @param y
   * @param on true to lit the pixel, false to unlit
   * @return 1 if the pixel was set and is overwritten (=collision)
   */
  int put_pixel(int x, int y, bool on);

  /**
   * get a pixel from screen coordinates
   * @param x
   * @param y
   * @return true if the pixel is lit
   */
  bool get_pixel(int x, int y);

  /**
   * draw sprite at screen coordinates
   * @param s the sprite buffer
   * @param len buffer size
   * @param x
   * @param y
   * @return 0 if no collision
   */
  int draw_sprite(const uint8_t *s, int len, int x, int y);

  /**
   * scroll down N lines
   * @param n lines to scroll down
   */
  void scroll_down(int n);

  /**
   * scroll 4 pixel left
   */
  void scroll_left();

  /**
   * scroll 4 pixel right
   */
  void scroll_right();

  /**
   * clear display
   */
  void clear();

  /**
   * dynamically set mode via the HIGH/LOW instruction from the cpu
   * @param mode one of the modes defined in defs.h (MODE_CHIP8, MODE_SUPERCHIP8, MODE_ETI660)
   */
  void set_mode(int mode);

private:
  CConfiguration *m_cfg;
  int m_width;
  int m_height;
  int m_mode;
  int m_color;
  double m_scale;
  SDL_Renderer *m_renderer;
  SDL_Window *m_window;
  CMemory *m_mem;
  uint8_t m_videoMem[64*128];
  std::array<bool, 64 * 128> m_videomem;
};

#endif // PROJECT_CDISPLAY_H

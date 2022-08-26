#ifndef CONSTANTS_SCREEN_H
#define CONSTANTS_SCREEN_H
const float SCREEN_WIDTH = 1125;
const float SCREEN_HEIGHT = 900;
const float WORK_PANEL = SCREEN_WIDTH * 4 / 5;
const float SIDE_BAR = SCREEN_WIDTH * 1 / 5;

const int SB_MOUSE_POSITION = 0;
const int SB_DOMAIN = SB_MOUSE_POSITION + 1;
const int SB_MOUSE_CLICKED = SB_DOMAIN + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;
const int SB_MOUSE_WHEEL_SCROLLED = SB_KEY_PRESSED + 1;
const int SB_RESET_BUTTOM = SB_MOUSE_WHEEL_SCROLLED + 1;
const int SB_TEXT_BOX = SB_RESET_BUTTOM + 1;
const int SB_HISTORY = SB_TEXT_BOX + 3;
#endif // CONSTANTS_H
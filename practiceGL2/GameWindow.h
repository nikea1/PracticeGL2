//
//  GameWindow.h
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#ifndef GameWindow_h
#define GameWindow_h

#include <stdio.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>

#define SCREEN_WIDTH 84
#define SCREEN_HEIGHT 48
#define MODIFIER 5

extern int display_width;
extern int display_height;
typedef struct {
    void (*render)(void);
    void (*update)(void);
}GameWindow;

int getMonsterLvl(void);
void setMonsterLvl(int lvl);
GameWindow *initGameWindow(void);
void destroyGameWindow(GameWindow *gw);
#endif /* GameWindow_h */

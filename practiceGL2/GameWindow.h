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

typedef struct {
    void (*render)(void);
    void (*update)(void);
}GameWindow;

GameWindow *initGameWindow(void);
void destroyGameWindow(GameWindow *gw);
#endif /* GameWindow_h */

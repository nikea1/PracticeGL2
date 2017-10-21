//
//  GameWindow.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#include "GameWindow.h"

void gamewindowRender(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    glutSwapBuffers();
}

void gamewindowUpdate(){
    
}

GameWindow *initGameWindow(){
    GameWindow *gw = malloc(sizeof(*gw));
    
    gw->render = gamewindowRender;
    gw->update = gamewindowUpdate;
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    return gw;
}

void destroyGameWindow(GameWindow *gw){
    free(gw);
}

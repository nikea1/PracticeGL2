//
//  main.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#include <stdio.h>
#include <GLUT/glut.h>
#include "GameWindow.h"

GameWindow *gw;

void processNormalKeys(unsigned char ch, int xx, int yy){
    switch(ch){
        case 27:
            destroyGameWindow(gw);
            exit(1);
            break;
            
            
    }
}

int main(int argc, const char * argv[]) {
    
    
    glutInit(&argc, argv);
    glutInitWindowSize(display_width, display_height);
    glutInitWindowPosition(320, 320);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Practice2");
    
    gw = initGameWindow();
    
    glutDisplayFunc(*(gw->render));
    glutKeyboardFunc(processNormalKeys);
    printf("Hello, World!\n");
    
    glutMainLoop();
    return 0;
}

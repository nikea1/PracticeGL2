//
//  main.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#include <stdio.h>
#include <GLUT/glut.h>

#define SCREEN_WIDTH 84
#define SCREEN_HEIGHT 48
#define MODIFIER 5

int display_width = SCREEN_WIDTH*MODIFIER;
int display_height = SCREEN_HEIGHT*MODIFIER;

void processNormalKeys(unsigned char ch, int xx, int yy){
    switch(ch){
        case 27:
            //deconstructGameWindow(gw);
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
    
    glutKeyboardFunc(processNormalKeys);
    printf("Hello, World!\n");
    
    glutMainLoop();
    return 0;
}

//
//  GameWindow.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#include "GameWindow.h"
#include "glbmp.h"
#include "sprite.h"


GLuint _GWtextureBufferID;
GLuint _GWvertexBufferID;
Sprite *monster;

//vertex struct
typedef struct{
    GLfloat pos[3];
    GLfloat tex[2];
} VertexData;

//vertex data for a square {(x,y,x), (u,v)}
VertexData vertices[] = {
    {{  0.0f,   0.0f, 0.0f}, {0.0, 0.0}},
    {{  0.0f, 100.0f, 0.0f}, {0.0, 1.0}},
    {{100.0f, 100.0f, 0.0f}, {1.0, 1.0}},
    {{100.0f,   0.0f, 0.0f}, {1.0, 0.0}}
};

//load image into texture
GLuint loadAndBufferImage(const char *filename){
    GLuint texture;
    glBMP img = initGLBMP(filename);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    if(img.hasAlpha)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_BGRA, GL_UNSIGNED_BYTE, img.pixelData);
    else
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width, img.height, 0, GL_BGR, GL_UNSIGNED_BYTE, img.pixelData);

    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    //free(data);
    free(img.pixelData);
    return texture;
 
    
   
}

//rendering function
void gamewindowRender(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Draw your stuff here
    //Note: (0,0) is center of window
    //without adjustments to view window
    //glColor3f(1.0f, 0.0f, 0.0f);
    
    monster->render();
    
    //glDrawArrays(GL_QUADS, 0, 4);
    
    /*
    //can color individual points with this
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 100.0f);
    glVertex2f(100.0f, 100.0f);
    glVertex2f(100.0f, 0.0f);
    glEnd();
    */
    //End of drawing
    
    //swap buffers
    glutSwapBuffers();
}

//update function
void gamewindowUpdate(){
    
}

//initialize gamewindow struct information
GameWindow *initGameWindow(){
    GameWindow *gw = malloc(sizeof(*gw));
    
    gw->render = gamewindowRender;
    gw->update = gamewindowUpdate;
    //end of initializing Game Window struct
    
    //begin initiallizing OPENGL
    
    //clears the screen with white background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //Adjust view window
    glMatrixMode(GL_PROJECTION);
    //ortho2d shifts 2D plain view
    gluOrtho2D(0, display_width, 0, display_height);
    glMatrixMode(GL_MODELVIEW);
    
    //generate buffers, bind BUFFERS!!!, load data
    glGenBuffers(1, &_GWvertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _GWvertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    //enable vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(VertexData), (GLvoid *)offsetof(VertexData, pos));
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, sizeof(VertexData), (GLvoid *)offsetof(VertexData, tex));
    
    _GWtextureBufferID = loadAndBufferImage("testA.bmp");
    Vector2 monsterPosition;
    monsterPosition.x = 42;
    monsterPosition.y = 24;
    monster = initSprite(_GWtextureBufferID, monsterPosition);
    
    return gw;
}

//destroy struct
void destroyGameWindow(GameWindow *gw){
    destroySprite(monster);
    free(gw);
}

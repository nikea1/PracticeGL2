//
//  GameWindow.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 10/21/17.
//  Copyright © 2017 Adenike Adeyemi. All rights reserved.
//

#include "GameWindow.h"

GLuint _GWtextureBufferID;
GLuint _GWvertexBufferID;

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
GLuint loadAndBufferImage(char const *filename){
    
    GLuint texture = 0;
    FILE *image;
    
    unsigned char header[0x46];
    int dataPos; //where the color data starts
    int width,height;   //width and height of image
    int imageSize;  //total image size
    int nColorBit;
    int alphaMask;
    unsigned char *imageData;
    
    image = fopen(filename, "rb");
    
    if(image == NULL){
        printf("File failed to open. \n");
        exit(1);
    }
    
    if(fread(header, 1, 0x46, image) != 0x46)
    {
        printf("<#const char *restrict, ...#>");
    }
    
    
    
    fclose(image);
    
    return texture;
}

//rendering function
void gamewindowRender(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Draw your stuff here
    //Note: (0,0) is center of window
    //without adjustments to view window
    glColor3f(1.0f, 1.0f, 0.0f);
    
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
    
    return gw;
}

//destroy struct
void destroyGameWindow(GameWindow *gw){
    free(gw);
}

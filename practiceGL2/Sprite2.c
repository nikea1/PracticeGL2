//
//  Sprite2.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/26/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#include "Sprite2.h"
#include <stdlib.h>

void sprite2Render(Sprite2 *self){
    glBindBuffer(GL_TEXTURE_2D, self->_TextureBufferID);
    
    
    //glLoadIdentity();
    glPushMatrix();
    glTranslatef(self->_Position.x, self->_Position.y, 0);
    
    //turn pet around facing the direction it's moving
    if(self->_Velocity.x > 0)
        glRotatef(180.0, 0.0, 1.0, 0.0);
    
    
    glDrawArrays(GL_QUADS, 0, 4);
    glPopMatrix();
   
}

void sprite2Update(Sprite2 *self){
    self->_Position = addVector(self->_Position, self->_Velocity);
}

Sprite2 *initSprite2(GLuint textureBufferID, Vector2 position){
    Sprite2 *out = NULL;
    out = malloc(sizeof(*out));
    if(!out){
        printf("Out of Memory for Sprite2\n");
    }
    
    out->_Position = position;
    out->_TextureBufferID = textureBufferID;
    out->render = sprite2Render;
    out->update = sprite2Update;
    
    
    return out;
}

void destroySprite2(Sprite2 *s){
    free(s);
}
/**/

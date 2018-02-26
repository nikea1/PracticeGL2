//
//  sprite.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/23/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#include "sprite.h"

GLuint _spriteTextureBufferID;
Vector2 _spritePosition;
Vector2 _spriteVelocity;

void spriteSetPosition(Vector2 position){
    _spritePosition = position;
}

Vector2 spriteGetPosition(){
    return _spritePosition;
}

void spriteSetVelocity(Vector2 velocity){
    _spriteVelocity = velocity;
}

Vector2 spriteGetVelocity(){
    return _spriteVelocity;
}

void spriteRender(){
    glBindBuffer(GL_TEXTURE_2D, _spriteTextureBufferID);
    
    glLoadIdentity();
    
    glTranslatef(_spritePosition.x, _spritePosition.y, 0);
    
    glDrawArrays(GL_QUADS, 0, 4);
}

void spriteUpdate(){
    _spritePosition = addVector(_spritePosition, _spriteVelocity);
}

Sprite *initSprite(GLuint textureBufferID, Vector2 position){
    Sprite *out = NULL;
    out = malloc(sizeof(*out));
    
    if(!out){
        printf("We are already out of memory\n");
        exit(1);
    }
    out->setPosition = spriteSetPosition;
    out->getPosition = spriteGetPosition;
    out->getVelocity = spriteGetVelocity;
    out->setVelocity = spriteSetVelocity;
    out->render = spriteRender;
    out->update = spriteUpdate;
    _spriteTextureBufferID = textureBufferID;
    _spritePosition = position;
    
    return out;
}

void destroySprite(Sprite *s){
    free(s);
}

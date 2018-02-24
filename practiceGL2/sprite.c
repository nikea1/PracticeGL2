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

void spriteSetPosition(Vector2 vec){
    _spritePosition = vec;
}

Vector2 spriteGetPosition(){
    return _spritePosition;
}

void spriteRender(){
    glBindBuffer(GL_TEXTURE_2D, _spriteTextureBufferID);
    
    glDrawArrays(GL_QUADS, 0, 4);
}

void spriteUpdate(){
    
}

Sprite *initSprite(GLuint textureBufferID){
    Sprite *out = NULL;
    out = malloc(sizeof(*out));
    
    if(!out){
        printf("We are already out of memory\n");
        exit(1);
    }
    out->setPosition = spriteSetPosition;
    out->getPosition = spriteGetPosition;
    out->render = spriteRender;
    out->update = spriteUpdate;
    _spriteTextureBufferID = textureBufferID;
    
    return out;
}

void destroySprite(Sprite *s){
    free(s);
}

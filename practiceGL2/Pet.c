//
//  Pet.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/26/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#include "Pet.h"

GLuint _petTextureBufferID;
Vector2 _petPosition;
Vector2 _petVelocity;

void petSetPosition(Vector2 position){
    _petPosition = position;
}

Vector2 petGetPosition(){
    return _petPosition;
}

void petSetVelocity(Vector2 velocity){
    _petVelocity = velocity;
}

Vector2 petGetVelocity(){
    return _petVelocity;
}

void petRender(){
    glBindBuffer(GL_TEXTURE_2D, _petTextureBufferID);
    
    glLoadIdentity();
    
    glTranslatef(_petPosition.x, _petPosition.y, 0);
    
    glDrawArrays(GL_QUADS, 0, 4);
}

void petUpdate(){
    
}

Pet *initPet(GLuint textureBufferID, Vector2 position){
    Pet *out = NULL;
    out = malloc(sizeof(*out));
    
    if(!out){
        printf("We are already out of memory\n");
        exit(1);
    }
    out->setPosition = petSetPosition;
    out->getPosition = petGetPosition;
    out->getVelocity = petGetVelocity;
    out->setVelocity = petSetVelocity;
    out->render = petRender;
    out->update = petUpdate;
    _petTextureBufferID = textureBufferID;
    _petPosition = position;
    
    return out;
}

void destroyPet(Pet *p){
    free(p);
}


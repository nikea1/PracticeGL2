//
//  Vector2.c
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/23/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#include "Vector2.h"

Vector2 makeVector(GLfloat x, GLfloat y){
    
    Vector2 out;
    
    out.x = x;
    out.y = y;
    
    return out;
}

Vector2 addVector(Vector2 first, Vector2 second){
    
    Vector2 sum;
    sum.x = first.x + second.x;
    sum.y = first.y + second.y;
    
    return sum;
}

//
//  BoundingBox.h
//  practiceGL2
//
//  Created by Adenike Adeyemi on 2/26/18.
//  Copyright © 2018 Adenike Adeyemi. All rights reserved.
//

#ifndef BoundingBox_h
#define BoundingBox_h

#include <stdio.h>

typedef struct{
    int top;
    int bottom;
    int left;
    int right;
} BoundingBox;

BoundingBox makeBoundingBox(int, int, int, int);
#endif /* BoundingBox_h */

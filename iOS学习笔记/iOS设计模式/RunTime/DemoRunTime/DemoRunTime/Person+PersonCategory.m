//
//  Person+PersonCategory.m
//  DemoRunTime
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "Person+PersonCategory.h"
#import <objc/runtime.h>

const char *str = "height";

@implementation Person (PersonCategory)

- (void)setHeight:(float)height {
  NSNumber *hei = [NSNumber numberWithFloat:height];
  objc_setAssociatedObject(self, str, hei, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
  
}

- (float)height {
  NSNumber *num = objc_getAssociatedObject(self, str);
  return [num floatValue];
}

@end

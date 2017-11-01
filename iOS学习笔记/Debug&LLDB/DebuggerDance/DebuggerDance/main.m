//
//  main.m
//  DebuggerDance
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

static BOOL isEven(int i) {
  if (i %2 ==0) {
    NSLog(@"%d is even",i);
    return YES;
  }
  
  NSLog(@"%d is odd",i);
  return NO;
}

int main(int argc, char * argv[]) {
  @autoreleasepool {
//      return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    int i = 99;
    BOOL even0 = isEven(i + 2);
    BOOL even1 = isEven(i + 11);
    
  }
}

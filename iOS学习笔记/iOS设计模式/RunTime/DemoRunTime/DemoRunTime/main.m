//
//  main.m
//  DemoRunTime
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
  @autoreleasepool {
//      return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    
    NSUInteger count = 99;
    NSString *objects = @"tt";
    NSLog(@"%lu,%@",count,objects);
  }
}

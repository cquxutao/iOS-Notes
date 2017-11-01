//
//  main.m
//  函数式编程
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "Calculator.h"

int main(int argc, char * argv[]) {
//  @autoreleasepool {
//      return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
//  }
  Calculator *c = [[Calculator alloc] init];

  int value1 = [[[c calculator:^int(int value) {
    value += 10;
    return value;
  }] equal:^BOOL(int value) {
    return value == 110;
  }] isequal];
  
  NSLog(@"%d",value1);
}

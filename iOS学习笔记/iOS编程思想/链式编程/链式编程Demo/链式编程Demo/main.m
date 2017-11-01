//
//  main.m
//  链式编程Demo
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import "NSObject+CalculatorMaker.h"
#import "CM.h"

int main(int argc, char * argv[]) {
//  @autoreleasepool {
//      return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
//  }
//  CM *cm = [[CM alloc] init];
//  NSLog(@"%d", cm.add(1).add(2).muilt(5).result); //链式编程思想
  
  int result = [NSObject makeCalculator:^(CM *cm) { //这里其实也有函数式编程的思想
    cm.add(1).add(2).add(3);//相当于在此定义，传入到行参中的函数体（block体）
  }];
  NSLog(@"%d",result);
  //一定要理解block的用法
  //这里NSObject调用了，分类中添加的类方法，该方法传入了一个block参数，而这个blcok实参也就是对应了函数定义中的行参
  //相当于传入一个函数体（block）
}

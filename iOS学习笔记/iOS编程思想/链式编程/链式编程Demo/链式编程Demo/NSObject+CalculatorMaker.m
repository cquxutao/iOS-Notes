//
//  NSObject+CalculatorMaker.m
//  链式编程Demo
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "NSObject+CalculatorMaker.h"
#import "CM.h"

@implementation NSObject (CalculatorMaker)

//调用方式
/*
 int result = [NSObject makeCalculator:^(CM *cm) {
 cm.add(1).add(2).add(3);
 }];
 相当于传入一个函数体（block体）
 */
+ (int)makeCalculator:(void (^)(CM *cm))cmg { //cmg的body部分由实参定义好，这里只执行传入参数并执行这个block
  CM *cm = [[CM alloc] init];
  cmg(cm);
  return cm.result;
}

@end

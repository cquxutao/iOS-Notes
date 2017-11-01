//
//  Calculator.m
//  函数式编程
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "Calculator.h"

@implementation Calculator

//重要思想，函数式编程
/*
 int value1 = [[c calculator:^int(int value) { //传入的block，所以在实参处，定义block的函数（block）体
 value += 10;
 return value;
 }] value];
 */
- (Calculator *)calculator:(int (^)(int value))calblock {
  
  self.value = calblock(100);//传入参数,执行block;block的体,由实参定义
  return self;
}

- (Calculator *)equal:(BOOL (^)(int value))oper {
  self.isequal = oper(self.value);//传入参数,执行block;block的体,由实参定义
  return self;
}


@end

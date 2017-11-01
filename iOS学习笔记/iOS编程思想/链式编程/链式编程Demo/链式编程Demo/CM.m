//
//  CM.m
//  链式编程Demo
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "CM.h"

@implementation CM

- (CM *(^)(int value))add {
  return ^CM *(int value) { //函数返回值是block
    self.result += value;
    return self; //block必须有返回值，一般为self
  };
}

- (CM *(^)(int value))sub {
  return ^CM *(int value) {
    self.result -= value;
    return self;
  };
}

- (CM *(^)(int value))muilt {
  return ^CM *(int value) {
    self.result *= value;
    return self;
  };
}

- (CM *(^)(int value))divide {
  return ^CM *(int value) {
    self.result /= value;
    return self;
  };
}
@end

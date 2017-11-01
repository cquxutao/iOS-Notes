//
//  NSObject+CalculatorMaker.h
//  链式编程Demo
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CM;

@interface NSObject (CalculatorMaker)

+ (int)makeCalculator:(void (^)(CM *cm))cmg;

//Block pointer to non-function type is invalid
//这个问题怎么解,block是关键字，肯定不能用作单独的变量啊！

@end

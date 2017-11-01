//
//  Calculator.h
//  函数式编程
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Calculator : NSObject

@property (nonatomic,assign) BOOL isequal;
@property (nonatomic,assign) int value;

- (Calculator *)calculator:(int (^)(int value))calblock;

- (Calculator *)equal:(BOOL (^)(int value))oper;

@end

//
//  CM.h
//  链式编程Demo
//
//  Created by 徐涛 on 02/10/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CM : NSObject

@property (nonatomic,assign) int result;

- (CM *(^)(int value))add;
- (CM *(^)(int value))sub;
- (CM *(^)(int value))muilt;
- (CM *(^)(int value))divide;

@end

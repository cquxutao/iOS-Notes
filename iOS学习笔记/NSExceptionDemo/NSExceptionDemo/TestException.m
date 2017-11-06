//
//  TestException.m
//  NSExceptionDemo
//
//  Created by tenny on 06/11/2017.
//  Copyright © 2017 tenny. All rights reserved.
//

#import "TestException.h"
#import "TypeAException.h"
#import "TypeBException.h"

@interface TestException () {
    NSInteger number;
}

@end

@implementation TestException

- (id)init {
    self = [super init];
    if (self) {
        [self setNum:0];
    }
    return self;
}

- (void)setNum:(NSInteger) num {
    number = num;
    @try {
        if (number > 5) {
            NSException *e = [TypeAException exceptionWithName:@"A"
                                                        reason:@"reason A"
                                                      userInfo:nil];
            @throw e;
        } else if (number < 0){
            NSException *e = [TypeBException exceptionWithName:@"B"
                                                        reason:@"reason B"
                                                      userInfo:nil];
            @throw e;
        }
    }
    @catch (TypeAException *e) {
        NSLog(@"%@--%@",[e name],[e reason]);
    }
    @catch (TypeBException *e) {
        NSLog(@"%@--%@",[e name],[e reason]);
    }
    @finally {
        NSLog(@"number = %ld",(long)number);
    }
    
}

- (void)add {
    [self setNum:number + 1];
}

- (void)sub {
    [self setNum:number - 1];
}

- (void)print {
    NSLog(@"number = %ld",(long)number);
}

@end

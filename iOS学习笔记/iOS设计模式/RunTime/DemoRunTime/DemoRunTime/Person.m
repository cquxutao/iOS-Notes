//
//  Person.m
//  DemoRunTime
//
//  Created by tennyxu on 04/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "Person.h"

@implementation Person {
  NSString *name;
}
@synthesize age;

- (instancetype)init {
  self = [super init];
  if (self) {
    name = @"TT";
    age = 10;
  }
  return self;
}

- (void)func1 {
  NSLog(@"execute func1");
}

- (void)func2 {
  NSLog(@"execute func2");
}

- (NSString *)description {
  return [NSString stringWithFormat:@"name=%@,age=%d",name,age];
}
@end

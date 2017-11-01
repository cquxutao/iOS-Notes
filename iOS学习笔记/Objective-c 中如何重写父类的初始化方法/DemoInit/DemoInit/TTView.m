//
//  TTView.m
//  DemoInit
//
//  Created by tennyxu on 26/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "TTView.h"

@implementation TTView {
  UIView *subView;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (id)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];
  if (self) {
    [self setUp];
    NSLog(@"%@",NSStringFromSelector(_cmd));
  }
  return self;
}

- (id)init {
  self = [super init];
  if (self) {
    [self setUp];
    NSLog(@"%@",NSStringFromSelector(_cmd));
  }
  return self;
}

- (id)initWithCoder:(NSCoder *)aDecoder {
  self = [super initWithCoder:aDecoder];
  if (self) {
    [self setUp];
    NSLog(@"%@",NSStringFromSelector(_cmd));
  }
  return self;
}

- (void)setUp {
  NSLog(@"%@",NSStringFromSelector(_cmd));
  subView = [[UIView alloc] initWithFrame:CGRectMake(10, 10, 20, 20)];
  subView.backgroundColor = [UIColor redColor];
  [self addSubview:subView];
}

@end

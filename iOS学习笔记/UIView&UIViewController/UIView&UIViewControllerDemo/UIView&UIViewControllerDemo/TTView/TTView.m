//
//  TTView.m
//  UIView&UIViewControllerDemo
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "TTView.h"

@implementation TTView


/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (void)layoutSubviews {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}
@end

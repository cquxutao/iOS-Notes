//
//  TTWindow.m
//  UIWindowLevelDemo
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "TTWindow.h"

@implementation TTWindow

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (void)becomeKeyWindow{
  NSLog(@"TTWindow becomeKeyWindow");
}

- (void)resignKeyWindow {
  NSLog(@"TTWindow resignKeyWindow");
}

@end

//
//  SecondViewController.m
//  UIResponderDemo
//
//  Created by tennyxu on 26/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "SecondViewController.h"

@interface SecondViewController ()

@end

@implementation SecondViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  NSLog(@"%@",NSStringFromSelector(_cmd));
  NSLog(@"%d",self.isFirstResponder);
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

#pragma mark UIResponder

- (BOOL)isFirstResponder {
  NSLog(@"%@",NSStringFromSelector(_cmd));
  return true;
}


@end

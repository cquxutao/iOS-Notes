//
//  FirstViewController.m
//  UIView&UIViewControllerDemo
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "FirstViewController.h"
#import "TTView.h"

@interface FirstViewController ()

@property (strong,nonatomic,nullable) TTView *ttView;

@end

@implementation FirstViewController

#pragma mark 初始化
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder {
  self = [super initWithCoder:aDecoder];
  NSLog(@"%@",NSStringFromSelector(_cmd));
  return self;
}

//- (void)loadView {
//  NSLog(@"%@",NSStringFromSelector(_cmd));
//}

- (void)viewDidLoad {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}


- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  NSLog(@"%@",NSStringFromSelector(_cmd));
}

- (void)viewDidAppear:(BOOL)animated {
  [super viewDidAppear:animated];
  
//  _ttView = [[TTView alloc] init];
//
//  [self.view addSubview:_ttView];
  
  NSLog(@"%@",NSStringFromSelector(_cmd));
  
  
}

- (void)viewWillDisappear:(BOOL)animated {
  NSLog(@"%@",NSStringFromSelector(_cmd));
  [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated {
  NSLog(@"%@",NSStringFromSelector(_cmd));
  [super viewDidDisappear:animated];
}

- (void)viewWillLayoutSubviews {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}

- (void)viewDidLayoutSubviews {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}

@end

//
//  ViewController.m
//  UIStatusBarDemo
//
//  Created by tennyxu on 24/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  
  self.view.backgroundColor = [UIColor grayColor];
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  [self setNeedsStatusBarAppearanceUpdate];
}

#pragma mark 局部设置
//当插入Navigation Controller后, 这里的所有设置都失效了
- (BOOL)prefersStatusBarHidden {
  return NO;
}

- (UIStatusBarStyle)preferredStatusBarStyle {
  return UIStatusBarStyleLightContent;
}

- (UIStatusBarAnimation)preferredStatusBarUpdateAnimation {
  return UIStatusBarAnimationFade;
}

@end

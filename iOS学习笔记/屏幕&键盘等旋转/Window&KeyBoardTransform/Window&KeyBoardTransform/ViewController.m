//
//  ViewController.m
//  Window&KeyBoardTransform
//
//  Created by tennyxu on 24/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic,assign) BOOL isLandscape;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  
  self.isLandscape = false;
  
  NSArray<__kindof UIWindow *> *windows = [[UIApplication sharedApplication] windows];
  
  for (UIWindow *window in windows) {
    NSLog(@"%@",window);
  }
  
  UIWindow *keyWindow = [[UIApplication sharedApplication] keyWindow];
  
  NSLog(@"keyWindow = %@",keyWindow);
  
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

- (IBAction)btn:(UIButton *)sender {
  //注意，这里的旋转时绝对意思的旋转：
  //比如说，现在顺时针旋转了M_PI_2（90度），则下一次，点击按钮，它不会在旋转，因为它已经到了M_PI_2这个位置了，所以这就是绝对位置的旋转
  //但是我认为这并不是真正的旋转屏幕，一点可以证明的就是：状态条并不随着旋转）
  
  if (!_isLandscape) {
    self.view.transform = CGAffineTransformMakeRotation(M_PI_2);
    self.view.frame = [UIScreen mainScreen].bounds;
    
  } else {
    self.view.transform = CGAffineTransformMakeRotation(0);
    self.view.frame = [UIScreen mainScreen].bounds;
  }
  _isLandscape = !_isLandscape;
}

//局部管理
//http://www.jianshu.com/p/006c2d663d2d
#pragma mark 修改状态栏
- (BOOL)prefersStatusBarHidden {
  return NO;
}
- (UIStatusBarStyle)preferredStatusBarStyle {
  return UIStatusBarStyleDefault;
}
- (UIStatusBarAnimation)preferredStatusBarUpdateAnimation {
  return UIStatusBarAnimationSlide;//感觉没什么卵用
}


@end

//
//  ViewController.m
//  KeyBoardNotificationDemo
//
//  Created by tennyxu on 23/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"

@interface ViewController () <UITextFieldDelegate>

@property (strong,nonatomic) UITextField *tf;

@end

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  
  self.tf = [[UITextField alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];
  self.tf.backgroundColor = [UIColor redColor];
  self.tf.delegate = self;
  [self.view addSubview:_tf];
}

- (void) UIKeyboardWillShowNotification:(NSNotification *)notification {
  NSLog(@"%@",NSStringFromSelector(_cmd));
  NSLog(@"%@",notification);
  NSDictionary *dic = [notification userInfo];
  //修改动画类型
//  NSInteger curve = [[dic objectForKey:@"UIKeyboardAnimationCurveUserInfoKey"] integerValue];
  
  //以后多用这种语法，感觉很骚
  NSTimeInterval animationDuration;
  UIViewAnimationCurve animationCurve;
  
  [[dic objectForKey:@"UIKeyboardAnimationDurationUserInfoKey"] getValue:&animationDuration];
  
  [[dic objectForKey:@"UIKeyboardAnimationCurveUserInfoKey"] getValue:&animationCurve];
  
  UIViewAnimationOptions option = animationCurve << 16;
  
  __weak typeof(self) weakSelf = self;
  [UIView animateWithDuration:animationDuration
                        delay:0
                      options:option
                   animations:^{
                     //修改高度什么的
                     weakSelf.tf.frame = CGRectMake(100, 50, 100, 100);
                     [weakSelf.view layoutIfNeeded];
                   } completion:nil];
}

- (void) UIKeyboardDidShowNotification {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}

- (void) UIKeyboardWillHideNotification:(NSNotification *)notification {
  NSLog(@"%@",NSStringFromSelector(_cmd));
  NSLog(@"%@",notification);
  NSDictionary *dic = [notification userInfo];
  NSLog(@"%@",dic);
}

- (void) UIKeyboardDidHideNotification {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}

- (void) UIKeyboardWillChangeFrameNotification {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}

- (void) UIKeyboardDidChangeFrameNotification {
  NSLog(@"%@",NSStringFromSelector(_cmd));
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
  
  
  
  NSLog(@"%@",NSStringFromSelector(_cmd));
  
  NSLog(@"tennyxu:%d",self.tf.canResignFirstResponder);
  
  [self.tf resignFirstResponder];
  
  return YES;
}

- (BOOL)canBecomeFirstResponder {
  NSLog(@"tennyxu:canBecomeFirstResponder");
  return NO;
}

- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}
//http://blog.csdn.net/iosfengguibin/article/details/53140241
- (void)viewWillAppear:(BOOL)animated {
  [super viewWillAppear:animated];
  //正确的注册通知的地方
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(UIKeyboardWillShowNotification:) name:UIKeyboardWillShowNotification object:nil];
  
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(UIKeyboardDidShowNotification) name:UIKeyboardDidShowNotification object:nil];
  
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(UIKeyboardWillHideNotification:) name:UIKeyboardWillHideNotification object:nil];
  
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(UIKeyboardDidHideNotification) name:UIKeyboardDidHideNotification object:nil];
  
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(UIKeyboardWillChangeFrameNotification) name:UIKeyboardWillChangeFrameNotification object:nil];
  
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(UIKeyboardDidChangeFrameNotification) name:UIKeyboardDidChangeFrameNotification object:nil];
  
  
}
- (void)viewWillDisappear:(BOOL)animated {
  [super viewWillDisappear:animated];
  [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillShowNotification object:nil];
  [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardDidShowNotification object:nil];
  [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardWillHideNotification object:nil];
  [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardDidHideNotification object:nil];
}


- (void)dealloc {
//  [[NSNotificationCenter defaultCenter] removeObserver:self name:<#(nullable NSNotificationName)#> object:nil];
}

@end

//
//  FirstViewController.m
//  CovertRectDemo1
//
//  Created by 徐涛 on 23/08/2017.
//  Copyright © 2017 徐涛. All rights reserved.
//

#import "FirstViewController.h"

@interface FirstViewController ()
@property (weak, nonatomic) IBOutlet UIView *layer1View;
@property (weak, nonatomic) IBOutlet UILabel *layer1Label;

@end

@implementation FirstViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  NSLog(@"windows.frame: %@",NSStringFromCGRect([[[UIApplication sharedApplication] delegate] window].frame));
  NSLog(@"windows.bounds: %@",NSStringFromCGRect([[[UIApplication sharedApplication] delegate] window].bounds));
  NSLog(@"_layer1View.frame: %@",NSStringFromCGRect(_layer1View.frame));
  NSLog(@"_layer1View.bounds: %@",NSStringFromCGRect(_layer1View.bounds));
  NSLog(@"_layer1Label.frame: %@",NSStringFromCGRect(_layer1Label.frame));
  NSLog(@"_layer1Label.bounds: %@",NSStringFromCGRect(_layer1Label.bounds));
  
  CGRect rect1 = [_layer1View convertRect:_layer1View.bounds toView:[[[UIApplication sharedApplication] delegate] window]];
  
  NSLog(@"_layer1View相对于window的位置:%@",NSStringFromCGRect(rect1));
  
  CGRect rect2 = [_layer1Label convertRect:_layer1Label.bounds toView:[[[UIApplication sharedApplication] delegate] window]];
  
  NSLog(@"_layer1Label相对于window的位置:%@",NSStringFromCGRect(rect2));
  
//  [[UIApplication sharedApplication] windows][0].frame
  
  
  
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}


@end

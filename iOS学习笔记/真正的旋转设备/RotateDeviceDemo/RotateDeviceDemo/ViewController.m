//
//  ViewController.m
//  RotateDeviceDemo
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
  
//  NSLog(@"%d",self.shouldAutorotate);
//  NSLog(@"%lu",(unsigned long)self.supportedInterfaceOrientations);
//  NSLog(@"%ld",(long)self.preferredInterfaceOrientationForPresentation);
  
//  UIInterfaceOrientationMask m1 = UIInterfaceOrientationMaskPortrait;
//  NSLog(@"%lu",(unsigned long)m1);
//
//  UIInterfaceOrientationMask m2 = UIInterfaceOrientationMaskLandscapeLeft;
//  NSLog(@"%lu",(unsigned long)m2);
//
//  UIInterfaceOrientationMask m3 = UIInterfaceOrientationMaskLandscapeRight;
//  NSLog(@"%lu",(unsigned long)m3);
//
//  UIInterfaceOrientationMask m4 = UIInterfaceOrientationMaskPortraitUpsideDown;
//  NSLog(@"%lu",(unsigned long)m4);
//
//  UIInterfaceOrientationMask m5 = UIInterfaceOrientationMaskLandscape;
//  NSLog(@"%lu",(unsigned long)m5);
//
//  UIInterfaceOrientationMask m6 = UIInterfaceOrientationMaskAll;
//  NSLog(@"%lu",(unsigned long)m6);
//
//  UIInterfaceOrientationMask m7 = UIInterfaceOrientationMaskAllButUpsideDown;
//  NSLog(@"%lu",(unsigned long)m7);
  
  NSLog(@"%d",[UIDevice currentDevice].isGeneratingDeviceOrientationNotifications);
}


- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

- (IBAction)btn:(UIButton *)sender {
  
  NSLog(@"%ld",(long)[UIDevice currentDevice].orientation);
  //强行进行设备旋转，而不管锁屏按钮
  if (self.preferredInterfaceOrientationForPresentation == UIInterfaceOrientationPortrait) {
    [[UIDevice currentDevice] setValue:[NSNumber numberWithInt:UIInterfaceOrientationLandscapeRight] forKey:@"orientation"];
  } else if (self.preferredInterfaceOrientationForPresentation == UIInterfaceOrientationLandscapeRight || self.preferredInterfaceOrientationForPresentation == UIInterfaceOrientationLandscapeLeft){
    [[UIDevice currentDevice] setValue:[NSNumber numberWithInt:UIInterfaceOrientationPortrait] forKey:@"orientation"];
  }
  
  
  
  
}

//- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation {
//  return UIInterfaceOrientationLandscapeLeft;
//}

- (void)viewWillAppear:(BOOL)animated {
//  if (![UIDevice currentDevice].isGeneratingDeviceOrientationNotifications) {
//    [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
//
//  }
}

@end

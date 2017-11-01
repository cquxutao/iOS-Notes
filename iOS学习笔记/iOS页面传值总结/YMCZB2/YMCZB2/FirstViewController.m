//
//  FirstViewController.m
//  YMCZB2
//
//  Created by tennyxu on 05/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "FirstViewController.h"
#import "SecondViewController.h"

@interface FirstViewController ()

@end

@implementation FirstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
  NSLog(@"1");
    // Do any additional setup after loading the view, typically from a nib.
    _dis.text = @"0";
    //获取SecondViewController
    SecondViewController *sVC = [self.tabBarController.viewControllers objectAtIndex:1];
    //指定SecondViewController(sVC)的block属性
    sVC.block = ^(int number) {
        _dis.text = [NSString stringWithFormat:@"%d",number];
    };
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

//
//  NavigationController.m
//  UIStatusBarDemo
//
//  Created by tennyxu on 24/09/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "NavigationController.h"

@interface NavigationController ()

@end

@implementation NavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
//http://www.jianshu.com/p/006c2d663d2d
//重载导航控制器Navigation Controller中如下两个方法, 根据栈顶控制器View Controller对状态栏的管理结果来管理状态栏
#pragma mark 当插入Navigation Controller后, 再设置
- (UIViewController *)childViewControllerForStatusBarHidden {
  return self.topViewController;
}
- (UIViewController *)childViewControllerForStatusBarStyle {
  return self.topViewController;
}


@end

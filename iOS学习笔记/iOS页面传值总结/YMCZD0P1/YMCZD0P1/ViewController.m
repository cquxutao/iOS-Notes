//
//  ViewController.m
//  YMCZD0P1
//
//  Created by tennyxu on 19/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"
#import "NextViewController.h"

@interface ViewController () <NextViewControllerDelegate> {
    UILabel *dis;
    UIButton *goVC;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    dis = [[UILabel alloc] init];
    [dis setFrame:CGRectMake(20.0, self.view.center.y - 15.0, self.view.frame.size.width - 40.0, 30.0)];
    dis.text = @"0";
    dis.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:dis];
    //
    goVC = [UIButton buttonWithType:UIButtonTypeSystem];
    [goVC setFrame:CGRectMake(20.0, self.view.center.y - 45.0, self.view.frame.size.width - 40.0, 30.0)];
    [goVC addTarget:self action:@selector(goNext:) forControlEvents:UIControlEventTouchDown];
    [goVC setTitle:@"go" forState:UIControlStateNormal];
    [self.view addSubview:goVC];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#pragma mark -- selector
- (void)goNext:(id)sender {
    NextViewController *nextVC = [[NextViewController alloc] init];
    nextVC.delegate = self;
    [self showViewController:nextVC sender:self];
}
#pragma mark -- NextViewControllerDelegate

- (void)increment:(id)sender withPara:(NSInteger)para {
    dis.text = [NSString stringWithFormat:@"%ld",(long)para];
}

@end

//
//  ViewController.m
//  YMCZB0
//
//  Created by tennyxu on 05/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"
#import "NextViewController.h"

@interface ViewController ()

@end

@implementation ViewController{
    UIButton *btn;
    UILabel *dis;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    btn = [UIButton buttonWithType:UIButtonTypeSystem];
    [btn setTitle:@"NextViewController" forState:UIControlStateNormal];
    [btn setFrame:CGRectMake(20.0, 140.0, self.view.frame.size.width - 20.0 - 20.0, 50.0)];
    [btn setBackgroundColor:[UIColor orangeColor]];
    [btn addTarget:self action:@selector(btnClicked:) forControlEvents:UIControlEventTouchDown];
    [self.view addSubview:btn];
    
    dis = [[UILabel alloc] init];
    [dis setBackgroundColor:[UIColor grayColor]];
    [dis setFrame:CGRectMake(20.0, 50.0, self.view.frame.size.width - 20.0 - 20.0, 50.0)];
    [dis setTextColor:[UIColor redColor]];
    dis.textAlignment = NSTextAlignmentCenter;
    dis.text = @"0";
    
    [self.view addSubview:dis];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) btnClicked: (id) sender{
    NextViewController *nVC = [[NextViewController alloc] init];
    nVC.block = ^(int number) {
        dis.text = [NSString stringWithFormat:@"%d",number];
    };
    [self showViewController:nVC sender:nil];
}

@end

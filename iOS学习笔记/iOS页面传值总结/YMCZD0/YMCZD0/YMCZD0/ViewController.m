//
//  ViewController.m
//  YMCZD0
//
//  Created by tennyxu on 06/08/2017.
//  Copyright © 2017 tennyxu. All rights reserved.
//

#import "ViewController.h"
#import "NextViewController.h"

@interface ViewController ()

@end

@implementation ViewController {
    UILabel *dis;
    UIButton *btn;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self setView];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
#pragma mark --setView
- (void) setView {
    dis = [[UILabel alloc] initWithFrame:CGRectMake(20.0, 50.0, self.view.frame.size.width - 40.0, 50.0)];
    dis.textAlignment = NSTextAlignmentCenter;
    dis.text = @"0";
    //
    btn = [UIButton buttonWithType:UIButtonTypeSystem];
    btn.frame = CGRectMake(20.0, 160.0, dis.frame.size.width, 50.0);
    [btn addTarget:self action:@selector(btnClicked:) forControlEvents:UIControlEventTouchDown];
    [btn setTitle:@"NextViewController" forState:UIControlStateNormal];
    [self.view addSubview:dis];
    [self.view addSubview:btn];
}
- (void) btnClicked:(id) sender {
    NextViewController *nVC = [[NextViewController alloc] init];
    nVC.delegate = self;
    [self presentViewController:nVC animated:YES completion:nil];
    
    
}

#pragma mark -- NextViewControllerDeleggate

- (void) incrementBy1:(int)number {
    dis.text = [NSString stringWithFormat:@"%d",number];
}

@end
